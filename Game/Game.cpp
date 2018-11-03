#include "Game.h"
#include "Exceptions.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Game::Game(string title, double price, Date release, Interval age_range, vector<string> platforms, vector<string> genres, string developer)
{
	id = id_seq;
	id_seq++;
	this->title = title;
	this->price = price;
	base_price = price;
	this->release = release;
	this->age_range = age_range;
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

vector<unsigned int> Game::getPriceHist() const
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
			throw RepeatedUser();
	users.push_back(user);
}


Home::Home(string title, double price, Date release, Interval age_range, vector<string> platforms, vector<string> genres, string developer):
	Game(string title, double price, Date release, Interval age_range, vector<string> platforms, vector<string> genres, string developer){}
