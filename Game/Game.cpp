#include "Game.h"
#include "Exceptions.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Interval;
class Date;

static unsigned int id_seq = 1;

Game::Game(const string &title,const double &price,const Date &release,const Interval &age_range,const vector<string> &platforms,const vector<string> &genres,const string &developer) :
		release(release), age_range(age_range)
{
	id = id_seq;
	id_seq++;
	this->title = title;
	this->price = price;
	base_price = price;
	this->platform = platform;
	this->genre = genre;
	this->developer = developer;
}


Game::~Game() {}

unsigned int Game::getId() const
{
	return id;
}

string Game::getTitle() const
{
	return title;
}

double Game::getPrice() const
{
	return price;
}

double Game::getBasePrice() const
{
	return base_price;
}

Date Game::getRelease() const
{
	return release;
}

Interval Game::getAge() const
{
	return age_range;
}

vector<string> Game::getPlatforms() const
{
	return platform;
}

vector<string> Game::getGenre() const
{
	return genre;
}

string Game::getDeveloper() const
{
	return developer;
}

vector<double> Game::getPriceHist() const
{
	return price_history;
}

bool Game::operator==(Game &game)
{
	return (id == game.id);
}

void Game::changePrice(const double &newPrice)
{
	price = newPrice;
	price_history.push_back(newPrice);
}

void Game::discountPrice(const unsigned int &percentage)
{
	double discount = price*percentage / 100;
	price = price - discount;
	price_history.push_back(price);
}

void Game::changeBasePrice(const double &newPrice)
{
	base_price = newPrice;
}

void Game::revertToPrice()
{
	price = base_price;
	price_history.push_back(price);
}

void Game::addUser(User* user)
{
	for (size_t i = 0; i < users.size(); i++)
		if (user == users[i])
			throw; //RepeatedUser();
	users.push_back(user);
}





Home::Home(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer):
	Game(title,price,release,age_range,platforms,genres,developer){}


vector<Date> Home::getUpdates() const
{
	return updates;
}

void Home::addUpdate(Date date) const
{
	updates.push_back(date);
}

void Home::printInfoGame() const {
	string platforms = "";
	for (int i = 0; i < platform.size(); i++) {
		platforms += platform[i] + ", "
	}
	platforms.pop_back().pop_back();

	string genres = "";
	for (int i = 0; i < genre.size(); i++) {
		genres += genre[i] + ", "
	}
	genres.pop_back().pop_back();


	cout << "Title: " << getTitle() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Platforms: " << platforms << endl;
	cout << "Genres: " << genres << endl;
	cout << "Current Price: " << getPrice() << endl;
	cout << "Base Price: " << getBasePrice() << endl;
	cout << "Release Date: " << getRelease().toStr() << endl;
	cout << "Recommended age: " << getAge().toStr() << endl;
	cout << "Developer: " << getDeveloper() << endl;
	cout << "Number of players: " << users.size() << endl;
}





Online::Online(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer):
		Game(title,price,release,age_range,platforms,genres,developer){
	play_time = 0;
};

int Online::getPlayTime() const
{
	return play_time;
}

vector<PlaySession*> Online::getPlayHistory() const
{
	return play_history;
}

double Online::getPrice() const
{
	return 0;
}





FixedSubsc::FixedSubsc(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const double &fixed_price) :
	Online(title,price,release,age_range,platforms,genres,developer){
	this->fixed_price = fixed_price;
}

double FixedSubsc::getPrice() const
{
	return fixed_price;
}

void FixedSubsc::printInfoGame() const {

	string platforms = "";
	vector<string> p = getPlatforms();
	for (int i = 0; i < p.size(); i++) {
		platforms += p[i] + ", "
	}
	platforms.pop_back().pop_back();

	string genres = "";
	for (int i = 0; i < genre.size(); i++) {
		genres += genre[i] + ", "
	}
	genres.pop_back().pop_back();


	cout << "Title: " << getTitle() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Plataforms: " << platforms << endl;
	cout << "Genres: " << genres << endl;
	cout << "Fixed subscription price: " << getPrice() << endl;
	cout << "Release Date: " << getRelease().toStr() << endl;
	cout << "Recommended age: " << getAge().toStr() << endl;
	cout << "Developer: " << getDeveloper() << endl;
	cout << "Number of players: " << users.size() << endl;
	cout << "Total play time: " << getPlayTime() << endl;

}





VariableSubsc::VariableSubsc(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const double &price_hour) :
	Online(title,price,release,age_range,platforms,genres,developer){
	this->price_hour = price_hour;
}

double VariableSubsc::getPrice() const
{
	return price_hour * (double)getPlayTime();
}

double VariableSubs::getPriceHour() const
{
	return price_hour;
}

void Variable_Subsc::printInfoGame() const {
	string platforms = "";
	for (int i = 0; i < platform.size(); i++) {
		platforms += platform[i] + ", "
	}
	platforms.pop_back().pop_back();

	string genres = "";
	for (int i = 0; i < genre.size(); i++) {
		genres += genre[i] + ", "
	}
	genres.pop_back().pop_back();


	cout << "Title: " << getTitle() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Plataforms: " << platforms << endl;
	cout << "Genres: " << genres << endl;
	cout << "Price per hour: " << getPriceHour() << endl;
	cout << "Release Date: " << getRelease().toStr() << endl;
	cout << "Recommended age: " << getAge().toStr() << endl;
	cout << "Developer: " << getDeveloper() << endl;
	cout << "Number of players: " << users.size() << endl;
	cout << "Total play time: " << getPlayTime() << endl;
}
