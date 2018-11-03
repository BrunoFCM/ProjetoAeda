#include <iostream>
#include "User.h"

using namespace std;

User::User(const string &name, const string &email, const unsigned int &age, const string &address)
{
	this->name = name;
	this->email = email;
	this->age = age;
	this->address = address;
}

bool User::addToLibrary(Game* game)
{
	for (size_t i = 0; i < library.size(); i++)
		if (*library[i] == *game)
		{
			throw RepeatedGame();
			return false;
		}
	library.push_back(game);
	return true;
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

