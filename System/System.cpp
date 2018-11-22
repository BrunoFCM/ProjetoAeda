#include <iostream>
#include "System.h"
#include "Exceptions.h"


using namespace std;

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
	throw NonExistantGame(to_string(id));
}

Game* System::searchGame(string title){
	for (unsigned int i = 0; i < store.size(); i++)
		if (store[i]->getTitle() == title)
			return store[i];
	throw NonExistantGame(title);
}

User* System::searchUser(string name){
	for (unsigned int i = 0; i < user_library.size(); i++)
		if (user_library[i]->getName() == name)
			return user_library[i];
	throw NonExistantUser(name);
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




