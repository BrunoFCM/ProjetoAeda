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

void User::addToLibrary(Game* game)
{
	for (size_t i = 0; i < library.size(); i++)
		if (*library[i] == *game)
			throw RepeatedGame();
	library.push_back(game);
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

bool User::operator==(User &user) const
{
	return (name == user.name && email == user.email && age ==user.age && address == user.address);
}

