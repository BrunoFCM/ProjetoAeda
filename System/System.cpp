#include <iostream>
#include <string>
#include <sstream>
#include "System.h"
#include "../Exceptions.h"

using namespace std;

System::System(ifstream &file) : developers(Developer("",0,"")) {
	std::string input;

	getline(file,input);
	while(input != "@"){
		int type;
		file >> type;
		file.ignore(1,'\n');

		getline(file,input);
		std::string title = input;

		double base,current;
		file >> current >> base;
		file.ignore(1,'\n');

		getline(file,input);
		Date release(input);

		unsigned int amin, amax;
		file >> amin >> amax;
		file.ignore(1,'\n');
		Interval ages(amin,amax);

		vector<std::string> platforms;
		while(input.back() != '.'){
			getline(file,input);
			std::string platform = input;
			platform.pop_back();
			platforms.push_back(platform);
		}

		vector<std::string> genres;
		while(input.back() != '.'){
			getline(file,input);
			std::string genre = input;
			genres.pop_back();
			genres.push_back(genre);
		}

		vector<double> prices;
		while(input.back() != '.'){
			getline(file,input);
			std::string value = input;
			value.pop_back();
			stringstream stream(value);
			double price;
			stream >> price;
			prices.push_back(price);
		}

		std::string name;
		std::string nif;
		std::string email;
		std::string::size_type sz;
		getline(file,name);
		getline(file, nif);
		getline(file,email);
		long unsigned nifint = stoi(nif, &sz);
		Developer developer(name, nifint, email);

		Game* game;

		switch(type){
			case 0:
				game = new Home(title,current,release,ages,platforms,genres,developer);
				while(input.back() != '.'){
					getline(file,input);
					Date update(input);
					game->addUpdate(update);
				}
				break;
			case 1:{
				double sub;
				file >> sub;
				file.ignore(1,'\n');
				game = new VariableSubsc(title,current,release,ages,platforms,genres,developer,sub);
				break;
			}
			case 2:{
				double sub;
				file >> sub;
				file.ignore(1,'\n');
				game = new FixedSubsc(title,current,release,ages,platforms,genres,developer,sub);
				break;
			}
		}

		store.push_back(game);

		//addpricehist

		getline(file,input);
		getline(file,input);
	}

	getline(file,input);
	while(input != "@"){

		getline(file,input);
		std::string name = input;

		getline(file,input);
		std::string email = input;

		int age;
		file >> age;
		file.ignore(1,'\n');

		getline(file,input);
		std::string address = input;

		User* user = new User(name,email,age,address);

		while(input.back() != '.'){
			getline(file,input);
			std::string game = input;
			Game* game_ptr = searchGame(game);
			user->addToLibrary(game_ptr);
		}

		while(input.back() != '.'){
			getline(file,input);
			std::string value = input;
			value.pop_back();
			stringstream stream(value);
			std::string number;
			double price;
			stream >> number >> price;
			Card card(number,price);
			user->addCard(card);
		}

		getline(file,input);
		getline(file,input);
	}

	getline(file,input);
	while(input != "@"){

		getline(file,input);
		User* user_ptr = searchUser(input);
		getline(file,input);
		Game* game_ptr = searchGame(input);
		getline(file,input);
		Date date(input);
		int duration;
		file >> duration;
		file.ignore(1,'\n');
		getline(file,input);
		std::string platform = input;

		PlaySession session(date,duration,platform,user_ptr,game_ptr);
		user_ptr->addSession(&session);

		getline(file,input);
		getline(file,input);
	}
}

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

void System::giveInfoSystem(ofstream &info) const
{
	for (unsigned int i = 0; i < store.size(); i++)
	{
		store[i]->giveInfoGame(info);
		info << "\n";
	}
	info << "@" << "\n";

	for (unsigned int j = 0; j < user_library.size(); j++)
	{
		user_library[j]->giveInfoUser(info);
		info << "\n";
	}
	info << "@" << "\n";

	for (unsigned int j = 0; j < user_library.size(); j++)
	{
		vector<PlaySession *> sess (user_library[j]->getSessions());
		for (unsigned int i = 0; i < sess.size(); i++)
		{
			sess[i]->giveSessions(info);
		}
	}
	info << "@" << "\n";

	BSTItrIn<Developer> it (developers);
	while (!it.isAtEnd())
	{
		it.retrieve().giveInfoDeveloper(info);
		info << ",\n";
		it.advance();
	}
	info << "@" << "\n";
}

void System::addDeveloper(Developer developer)
{
	if (developers.isEmpty())
	{
		developers.insert(developer);
		return;
	}

	Developer search = developers.find(developer);
	if (search.getEMail() == "")
		developers.insert(developer);
	else throw RepeatedDeveloper(developer.getName());
}

Developer System::searchDeveloper(long unsigned nif)
{
	if (developers.isEmpty())
		throw NonExistingDeveloper();

	BSTItrIn<Developer> it (developers);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getNif() == nif)
			return it.retrieve();
		it.advance();
	}

	throw NonExistingDeveloper();
}

Developer System::searchDeveloper(string name)
{
	if (developers.isEmpty())
		throw NonExistingDeveloper();

	BSTItrIn<Developer> it (developers);
	while (!it.isAtEnd())
	{
		if (it.retrieve().getName() == name)
			return it.retrieve();
		it.advance();
	}

		throw NonExistingDeveloper();
}
