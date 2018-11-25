#include <iostream>
#include "System.h"
#include "Exceptions.h"


using namespace std;

System::~System()
{
	for (size_t i = 0; i < user_library.size(); i++) {
 		vector<PlaySession*> sessions = user_library.at(i)->getSessions();
 		for (size_t j = 0; j < sessions.size(); j++) {
			delete sessions.at(j);
		}
 		delete user_library.at(i);
	}
 	for (size_t i = 0; i < store.size(); i++) {
		delete store.at(i);
	}
 }

void System::addUser(User* user)
{
	for (size_t i = 0; i < user_library.size(); i++) {
		if (user == user_library[i]) {
			string info = user->getName();
			throw RepeatedUser(info);
		}
	}
	user_library.push_back(user);
}

void System::addGame(Game* game)
{
	for (size_t i = 0; i < store.size(); i++) {
		if (game == store[i]) {
			string info = to_string(game->getId());
			throw RepeatedGame(info);
		}
	}
	store.push_back(game);
}

Game* System::searchGame(unsigned int id){
	for (unsigned int i = 0; i < store.size(); i++)
		if (store[i]->getId() == id)
			return store[i];
	throw NonExistingGame(to_string(id));
}

Game* System::searchGame(string title){
	for (unsigned int i = 0; i < store.size(); i++)
		if (store[i]->getTitle() == title)
			return store[i];
	throw NonExistingGame(title);
}

User* System::searchUser(string name){
	for (unsigned int i = 0; i < user_library.size(); i++)
		if (user_library[i]->getName() == name)
			return user_library[i];
	throw NonExistingUser(name);
}

void System::sortUsers(const UserComparer &comparer){
	if(!isUserComparer(comparer))
		throw InvalidComparer();
	insertionSort(user_library,comparer);
}

void System::sortGames(const GameComparer &comparer){
	if(!isGameComparer(comparer))
		throw InvalidComparer();
	insertionSort(store,comparer);
}

void System::buyGame(User* user, Game* game, unsigned int id)
{
	string info = to_string(game->getAge().getLower());
	if (user->getAge() >= game->getAge().getLower())
	{
		if (user->getCards()[id].getValidity() && user->getCards()[id].getBalance() >= game->getPrice())
		{
			double bal = user->getCards()[id].getBalance() - game->getPrice();
			user->getCards()[id].setBalance(bal);
			user->addToLibrary(game);
			return;
		}
		throw InvalidCard();
	}
	else throw UserTooYoung(info);
}

void System::giveInfoSystem(ostream &info) const
{
	for (unsigned int i = 0; i < store.size() - 1; i++)
	{
		store[i]->giveInfoGame(info);
		info << "\n";
	}
	store[store.size() - 1]->giveInfoGame(info);
	info << "@" << "\n";

	for (unsigned int j = 0; j < user_library.size(); j++)
	{
		user_library[j]->giveInfoUser(info);
		info << "\n";
	}
	user_library[store.size() - 1]->giveInfoUser(info);
	info << "@" << "\n";

	for (unsigned int j = 0; j < user_library.size(); j++)
	{
		vector<PlaySession *> sess (user_library[j]->getSessions());
		for (unsigned int i = 0; i < sess.size(); i++)
		{
			sess[i]->giveSessions(info);
		}
	}
	vector<PlaySession *> sess (user_library[user_library.size() - 1]->getSessions());
	for (unsigned int i = 0; i < sess.size(); i++)
	{
		sess[i]->giveSessions(info);
	}
	info << "@" << "\n";
}





