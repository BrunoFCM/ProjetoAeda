#include <iostream>
#include <iomanip>
#include "User.h"
#include "Exceptions.h"

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
	for (size_t i = 0; i < library.size(); i++) {
		if (*library[i] == *game) {
			string info = to_string(game->getId());
			throw RepeatedGame(info);
		}
	}
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

ostream User::giveInfoUser() const
{
	ostream info;
	info << name << "\n"
		 << email << "\n"
		 << age << "\n"
		 << address << "\n"
		 << cards.size() << "\n"
		 << library.size() << "\n"
		 << sessions.size() << "\n";
	return info;
}

void User::printLibraryUser(int numberOfGames = 0) const
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

ostream User::giveLibraryUser(int numberOfGames = 0) const
{
	ostream titles;
	if (numberOfGames == 0)
		for (unsigned int i = 0; i < library.size(); i++)
			titles << library[i]->getTitle() << "\n";
	else
	{
		for (unsigned int i = 0; i < library.size() && i < numberOfGames; i++)
			titles << library[i]->getTitle() << "\n";
	}

	return titles;
}

void User::printCardsUser(int numberOfCards = 0) const
{
	if (numberOfCards == 0)
		for (unsigned int i = 0; i < cards.size(); i++)
			cout << cards[i].getNumber() << "\n";
	else
	{
		for (unsigned int i = 0; i < cards.size() && i < numberOfCards; i++)
			cout << cards[i].getNumber() << "\n";
	}
}

ostream User::giveCardsUser(int numberOfCards = 0) const
{
	ostream numbers;
	if (numberOfCards == 0)
		for (unsigned int i = 0; i < cards.size(); i++)
			numbers << cards[i].getNumber() << "\n";
	else
	{
		for (unsigned int i = 0; i < cards.size() && i < numberOfCards; i++)
			numbers << cards[i].getNumber() << "\n";
	}

	return numbers;
}
