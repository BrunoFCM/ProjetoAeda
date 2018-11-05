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

void Game::revertToPrice(const unsigned int &number)
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


Online::Online(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const int &play_time, const vector<PlaySession*> &play_history):
		Game(title,price,release,age_range,platforms,genres,developer){
	this->play_time = play_time;
	this->play_history = play_history;
}

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

FixedSubsc::FixedSubsc(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const int &play_time, const vector<PlaySession*> &play_history,const double &fixed_price) :
	Online(title,price,release,age_range,platforms,genres,developer,play_time,play_history){
	this->fixed_price = fixed_price;
}

double FixedSubsc::getPrice() const
{
	return fixed_price;
}

VariableSubsc::VariableSubsc(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const int &play_time, const vector<PlaySession*> &play_history,const double &price_hour) :
	Online(title,price,release,age_range,platforms,genres,developer,play_time,play_history){
	this->price_hour = price_hour;
}

double VariableSubsc::getPrice() const
{
	return price_hour * (double)getPlayTime();
}


