#include <iostream>
#include <iomanip>
#include "../Date/Date.h"
#include "../User/User.h"
#include "../Exceptions.h"

using namespace std;

bool operator<(const Wanted_item &i1, const Wanted_item &i2){
	if (i1.interest == i2.interest){
		return i1.item->getTitle() < i2.item->getTitle();
	}
	else{
		return i1.interest < i2.interest;
	}
}

User::User(const string &name, const string &email, const unsigned int &age, const string &address) : last_purchase("01/01/1900")
{
	this->name = name;
	this->email = email;
	this->age = age;
	this->address = address;
}

void User::addToLibrary(Game* game)
{
	if (checkLibraryFor(game))
		throw (GameAlreadyOwned(game->getTitle()));
	library.push_back(game);
}

bool User::checkLibraryFor(Game* game) const{
	for (size_t i = 0; i < library.size(); i++) {
		if (*library[i] == *game) {
			string info = to_string(game->getId());
			return true;
		}
	}
	return false;
}

void User::addCard(const Card &card){
	for(unsigned int i = 0; i < cards.size(); ++i){
		if (cards[i].getNumber() == card.getNumber())
			throw (RepeatedCard(card.getNumber()));
	}
	cards.push_back(card);
}

void User::addSession(PlaySession *sess){
	sessions.push_back(sess);
}

string User::getName() const
{
	return name;
}

string User::getEmail() const
{
	return email;
}

unsigned int User::getAge() const
{
	return age;
}

string User::getAddress() const
{
	return address;
}

vector<Card> User::getCards() const
{
	return cards;
}

vector<Game*> User::getLibrary() const
{
	return library;
}

vector<PlaySession*> User::getSessions() const
{
	return sessions;
}

map<string,vector<Date>> User::getUpdates() const
{
	return updates;
}

void User::printUpdates(unsigned int numberOfUpdates) const
{
	map<string,vector<Date>>::const_iterator it = updates.begin();
	cout << endl << endl;
	if (numberOfUpdates)
		for(;it != updates.end(); ++it){
			cout << "Game: " << it->first << '\t' << "Date: " << it->second[0].toStr() << endl;
		}
	else
		for(;it != updates.end() && numberOfUpdates != 0; ++it){
			cout << "Game: " << it->first << '\t' << "Date: " << it->second[0].toStr() << endl;
			--numberOfUpdates;
		}
}

bool User::operator==(const User &user) const
{
	return (name == user.name && email == user.email && age ==user.age && address == user.address);
}

void User::printInfoUser() const
{
	cout << setiosflags(ios::left);
	cout << "User Data" << endl << endl;
	cout << setw(20) << "Name: "; cout << name << endl;
	cout << setw(20) << "Email: "; cout << email << endl;
	cout << setw(20) << "Age: "; cout << age << endl;
	cout << setw(20) << "Address: "; cout << address << endl;
	cout << setw(20) << "Number of cards: "; cout << cards.size() << endl;
	cout << setw(20) << "Number of games: "; cout << library.size() << endl;
	cout << setw(20) << "Number of sessions: "; cout << sessions.size() << endl;
}

void User::giveInfoUser(ofstream &info) const
{
	info << name << "\n"
		 << email << "\n"
		 << age << "\n"
		 << address << "\n";
	giveLibraryUser(info);
	giveCardsUser(info);
}

void User::printLibraryUser(unsigned int numberOfGames) const
{
	if (numberOfGames == 0)
		for (unsigned int i = 0; i < library.size(); i++)
			cout << library[i]->getTitle() << "\n";
	else
	{
		for (unsigned int i = 0; i < library.size() && i < numberOfGames; i++)
			cout << library[i]->getTitle() << "\n";
	}
}

void User::giveLibraryUser(ofstream &titles) const
{
	for (unsigned int i = 0; i < library.size(); ++i){
	if(i != (library.size() - 1)){
		titles << library[i]->getTitle() << ",\n";
	}
	else{
		titles << library[i]->getTitle() << ".\n";
	}
}
}

void User::printCardsUser(unsigned int numberOfCards) const
{
	if (numberOfCards == 0)
		for (unsigned int i = 0; i < cards.size(); i++){
			std::cout << (i+1) << ":\n";
			cards[i].printCard();
			std::cout << std::endl << std::endl;
		}
	else
	{
		for (unsigned int i = 0; i < cards.size() && i < numberOfCards; i++){
			std::cout << (i+1) << ":\n";
			cards[i].printCard();
			std::cout << std::endl << std::endl;
		}
	}
}

void User::giveCardsUser(ofstream &numbers) const
{
	for (unsigned int i = 0; i < cards.size(); ++i){
		if(i != (cards.size() - 1)){
			numbers << cards[i].getNumber() << cards[i].getBalance() << ",\n";
		}
		else{
			numbers << cards[i].getNumber() << cards[i].getBalance() << ".\n";
		}
	}
}

void User::printSessionsUser(unsigned int numberOfSessions) const
{
	if (numberOfSessions == 0)
		for (unsigned int i = 0; i < sessions.size(); i++)
			sessions[i]->printInfoSession();
	else
	{
		for (unsigned int i = 0; i < sessions.size() && i < numberOfSessions; i++)
			sessions[i]->printInfoSession();
	}
}

bool User::installUpdates(Game* game)
{
	unsigned int num_updates = game->getUpdates().size();
	try{
		if (num_updates == updates.at(game->getTitle()).size())
			return false;
	}
	catch (std::out_of_range &e){
		throw GameNotOwned(game->getTitle());
	}

	vector<Date> updatesRequired;
	for (unsigned int i = updates.size(); i < num_updates; i++)
	{
		updatesRequired.push_back(game->getUpdates()[i]);
	}
	updates[game->getTitle()] = updatesRequired;
	return true;
}

Card & User::getCardRef(unsigned int index){
	try{
		return cards.at(index);
	}
	catch(std::out_of_range &e){
		throw e;
	}
}

priority_queue<Wanted_item> User::getWishlist(){
	return Wishlist;
}

void User::addToWishlist(Game *game, int interest){
	try{
		searchWishlist(game);
	}
	catch(NonExistingGame &e){
		Wanted_item aux = {game,interest};
		Wishlist.push(aux);
		return;
	}

	throw (RepeatedGame(game->getTitle()));
}

void User::removeFromWishlist(Game *game){
	try{
		searchWishlist(game);
	}
	catch(NonExistingGame &e){
		throw (NonExistingGame(game->getTitle()));
	}

	vector<Wanted_item> aux;
	while (!Wishlist.empty()){
		if (Wishlist.top().item->getTitle() != game->getTitle())
			aux.push_back(Wishlist.top());
		Wishlist.pop();
	}
	for(unsigned int i = 0; i < aux.size(); ++i){
		Wishlist.push(aux[i]);
	}
}

Wanted_item User::searchWishlist(Game *game){
	Wanted_item out = {NULL,-1};
	vector<Wanted_item> aux;
	while (!Wishlist.empty()){
		if (Wishlist.top().item->getTitle() == game->getTitle())
			out = Wishlist.top();
		aux.push_back(Wishlist.top());
		Wishlist.pop();
	}
	for(unsigned int i = 0; i < aux.size(); ++i){
		Wishlist.push(aux[i]);
	}

	if (out.item == NULL){
		throw (NonExistingGame(game->getTitle()));
	}

	return out;
}

void User::changeInterestLevel(Game *game, int interest){
	try{
		searchWishlist(game);
	}
	catch(NonExistingGame &e){
		throw (NonExistingGame(game->getTitle()));
	}

	removeFromWishlist(game);
	addToWishlist(game,interest);
}


