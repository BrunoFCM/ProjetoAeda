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
	price_history.push_back(price);
	this->platform = platforms;
	this->genre = genres;
	this->developer = developer;
	player_base = 0;
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

unsigned int Game::getPlayerBase() const
{
	return player_base;
}

vector<Date> Game::getUpdates() const
{
	vector<Date> dates;
	return dates;
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

void Game::addUser()
{
	++player_base;
}

void Game::addSession(PlaySession *sess){}

void Game::addUpdate(Date date) {}

vector<PlaySession*> Game::getPlayHistory() const {vector<PlaySession*> out; return out;}

void Game::giveInfoGame(ofstream &info) const
{
	info << id << "\n" << title << "/n" << price << "\n" << base_price << "/n"
		 << release.toStr() << age_range.getLower() << " " << age_range.getUpper() << "\n";

	for (unsigned int i = 0; i < platform.size() - 1; i++)
		info << platform[i] << ",\n";
	info << platform[platform.size() - 1] << ".\n";

	for (unsigned int i = 0; i < genre.size() - 1; i++)
		info << genre[i] << ",\n";
	info << genre[genre.size() - 1] << ".\n" << developer << "\n";

	for (unsigned int i = 0; i < price_history.size() - 1; i++)
		info << price_history[i] << ",\n";
	info << price_history[price_history.size() - 1] << ".\n" << player_base << "\n";

}





Home::Home(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer):
	Game(title,price,release,age_range,platforms,genres,developer){}


vector<Date> Home::getUpdates() const
{
	return updates;
}

void Home::addUpdate(Date date)
{
	updates.push_back(date);
}

void Home::printInfoGame() const {
	string platforms = platform[0];
	for (unsigned int i = 1; i < platform.size(); i++) {
		platforms += ", " + platform[i];
	}

	string genres = genre[0];
	for (unsigned int i = 1; i < genre.size(); i++) {
		genres += ", " + genre[i];
	}

	cout << "Title: " << getTitle() << endl;
	cout << "ID: " << id << endl;
	cout << "Platforms: " << platforms << endl;
	cout << "Genres: " << genres << endl;
	cout << "Current Price: " << getPrice() << endl;
	cout << "Base Price: " << getBasePrice() << endl;
	cout << "Release Date: " << getRelease().toStr() << endl;
	cout << "Recommended age: " << getAge().toStr() << endl;
	cout << "Developer: " << getDeveloper() << endl;
	cout << "Number of players: " << player_base << endl;
}

void Home::giveInfoGame(ofstream &info) const
{
	Game::giveInfoGame(info);
	for (unsigned int i = 0; i < updates.size() - 1; i++)
		info << updates[i].toStr() << ",\n";
	info << updates[updates.size() - 1].toStr() << ".\n";
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

void Online::addSession(PlaySession *sess){
	play_history.push_back(sess);
}

bool Online::isHomeTitle() const {return false;}

bool Home::isHomeTitle() const {return true;}



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
	for (unsigned int i = 0; i < p.size(); i++) {
		platforms += p[i] + ", ";
	}
	platforms.pop_back();

	string genres = "";
	for (unsigned int i = 0; i < genre.size(); i++) {
		genres += genre[i] + ", ";
	}
	genres.pop_back();


	cout << "Title: " << getTitle() << endl;
	cout << "ID: " << id << endl;
	cout << "Plataforms: " << platforms << endl;
	cout << "Genres: " << genres << endl;
	cout << "Fixed subscription price: " << getPrice() << endl;
	cout << "Release Date: " << getRelease().toStr() << endl;
	cout << "Recommended age: " << getAge().toStr() << endl;
	cout << "Developer: " << getDeveloper() << endl;
	cout << "Number of players: " << player_base << endl;
	cout << "Total play time: " << getPlayTime() << endl;

}

void FixedSubsc::giveInfoGame(ofstream &info) const
{
	Game::giveInfoGame(info);
	info << fixed_price << "\n";
}





VariableSubsc::VariableSubsc(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const double &price_hour) :
	Online(title,price,release,age_range,platforms,genres,developer){
	this->price_hour = price_hour;
}

double VariableSubsc::getPriceHour() const
{
	return price_hour;
}

void VariableSubsc::printInfoGame() const {
	string platforms = "";
	for (unsigned int i = 0; i < platform.size(); i++) {
		platforms += platform[i] + ", ";
	}
	platforms.pop_back();

	string genres = "";
	for (unsigned int i = 0; i < genre.size(); i++) {
		genres += genre[i] + ", ";
	}
	genres.pop_back();


	cout << "Title: " << getTitle() << endl;
	cout << "ID: " << id << endl;
	cout << "Plataforms: " << platforms << endl;
	cout << "Genres: " << genres << endl;
	cout << "Price per hour: " << getPriceHour() << endl;
	cout << "Release Date: " << getRelease().toStr() << endl;
	cout << "Recommended age: " << getAge().toStr() << endl;
	cout << "Developer: " << getDeveloper() << endl;
	cout << "Number of players: " << player_base << endl;
	cout << "Total play time: " << getPlayTime() << endl;
}

void VariableSubsc::giveInfoGame(ofstream &info) const
{
	Game::giveInfoGame(info);
	info << price_hour << "\n";
}
