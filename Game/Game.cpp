#include "Game.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Game::Game(string title, double price, Date release, Interval age_range, vector<string> platform, vector<string> genre, string developer)
{
	id = id_Seq;
	id_Seq++;
	this->title = title;
	this->price = price;
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
