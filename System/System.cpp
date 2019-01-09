#include <iostream>
#include <string>
#include <sstream>
#include "System.h"
#include "../Exceptions.h"

using namespace std;
/*
System::System(ifstream &file) : developers(new Developer("",0,"")), current_date(Date("01/01/2019")) {
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

		std::string developer;
		getline(file, developer);

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
*/
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

	BSTItrIn<Developer*> it (developers);
	while (!it.isAtEnd())
	{
		it.retrieve()->giveInfoDeveloper(info);
		info << ",\n";
		it.advance();
	}
	info << "@" << "\n";
}


/********				  ********/
/********     PARTE 2     ********/
/********				  ********/

BST<Developer*> System::getDevelopers() const
{
	return developers;
}

void System::addDeveloper(Developer* developer)
{
	if (developers.isEmpty())
	{
		developers.insert(developer);
		return;
	}

	BSTItrIn<Developer*> it (developers);
	while (!it.isAtEnd())
	{
		if (*it.retrieve() == *developer)
			throw RepeatedDeveloper(developer->getName());
		it.advance();
	}
	developers.insert(developer);
}

Developer* System::searchDeveloper(long unsigned nif)
{
	if (developers.isEmpty())
		throw NonExistingDeveloper();

	BSTItrIn<Developer*> it (developers);
	while (!it.isAtEnd())
	{
		if (it.retrieve()->getNif() == nif)
			return it.retrieve();
		it.advance();
	}

	throw NonExistingDeveloper();
}

Developer* System::searchDeveloper(string name)
{
	if (developers.isEmpty())
		throw NonExistingDeveloper();

	BSTItrIn<Developer*> it (developers);
	while (!it.isAtEnd())
	{
		if (it.retrieve()->getName() == name)
			return it.retrieve();
		it.advance();
	}

	throw NonExistingDeveloper();
}

void System::addDays(unsigned int days) {
	if ((current_date.getMonth() == 1) ||
		(current_date.getMonth() == 3) ||
		(current_date.getMonth() == 5) ||
		(current_date.getMonth() == 7) ||
		(current_date.getMonth() == 8) ||
		(current_date.getMonth() == 10)) {
		if (current_date.getDay() + days > 31)
			current_date.setDate(days - (31 - current_date.getDay()), current_date.getMonth() + 1, current_date.getYear());
		else current_date.setDays(current_date.getDay() + days);
	}

	if ((current_date.getMonth() == 4) ||
		(current_date.getMonth() == 6) ||
		(current_date.getMonth() == 9) ||
		(current_date.getMonth() == 11)) {
		if (current_date.getDay() + days > 30)
			current_date.setDate(days - (30 - current_date.getDay()), current_date.getMonth() + 1, current_date.getYear());
		else current_date.setDays(current_date.getDay() + days);
	}

	if (current_date.getMonth() == 2) {
		if (current_date.getDay() + days > 28)
			current_date.setDate(days - (28 - current_date.getDay()), current_date.getMonth() + 1, current_date.getYear());
		else current_date.setDays(current_date.getDay() + days);
	}

	if (current_date.getMonth() == 12) {
		if (current_date.getDay() + days > 31)
			current_date.setDate(days - (31 - current_date.getDay()), current_date.getMonth() + 1, current_date.getYear() + 1);
		else current_date.setDays(current_date.getDay() + days);
	}
}

void System::addMonths(unsigned int months) {
	if (current_date.getMonth() + months > 12)
		current_date.setDate(current_date.getDay(), months - (12 - current_date.getMonth()), current_date.getYear() + 1);
	else current_date.setMonths(current_date.getMonth() + months);
}

bool System::checkAsleep(User* user) {
	if (current_date < user->getLastPurchase())
		return false;

	if (current_date.getYear() - user->getLastPurchase().getYear() >= 2)
		return true;
	if ((current_date.getYear() - user->getLastPurchase().getYear() == 1) && (current_date.getMonth() + 12 - user->getLastPurchase().getMonth() >= 3))
		return true;

	if (current_date.getMonth() - user->getLastPurchase().getMonth() >= 3)
		return true;

	return false;
}

void System::updateSleepingUsers() {

	//Em primeiro lugar, apagar as hash tables de jogadores adormecidos todos os jogos
	for(unsigned int i = 0; i < store.size(); i++)
		store[i]->deleteSleepingUsers();


	//De seguida, encontrar os utilizadores adormecidos
	for(unsigned int j = 0; j < user_library.size(); j++) {

		//Se o utilizador esta adormecido, percorre a hash table dos jogos interessantes e adiciona o user a hash de utilizadores adormecidos dos jogos
		if (checkAsleep(user_library[j])) {

			HashTabGames intGames = user_library[j]->getInterestingGames();
			HashTabGames::iterator it = intGames.begin();

			while(it != intGames.end()) {

				//Se o valor da probabilidade de compra for superior a 50%, adiciona-se o utilizador a hash do jogo
				if(it->probability >= 0.5)
					it->item->addSleepingUser(user_library[j]->getEmail());
			}
		}
	}
}

void System::setCurrentDate(const std::string &date){
	Date aux(date);
	current_date = aux;
}

Date System::getCurrentDate() {
	return current_date;
}




