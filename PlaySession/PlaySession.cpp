#include <iostream>
#include <iomanip>
#include "PlaySession.h"

using namespace std;

PlaySession::PlaySession(const Date date, const int duration, const string platform, User* user, Game* game): date(date), duration(duration), user(user), game(game) {}

Date PlaySession::getDate() const
{
	return date;
}

unsigned int PlaySession::getDuration() const
{
	return duration;
}

string PlaySession::getPlatform() const
{
	return platform;
}

User* PlaySession::getUser() const
{
	return user;
}

Game* PlaySession::getGame() const
{
	return game;
}

void PlaySession::printInfoSession() const
{
	string date = date.printDate();
	cout << setiosflags(ios::left);
	cout << "PlaySession Data" << endl << endl;
	cout << setw(20) << "User: "; cout << user->getName() << endl;
	cout << setw(20) << "Game: "; cout << game->getTitle() << endl;
	cout << setw(20) << "Date: "; cout << date << endl;
	cout << setw(20) << "Duration: "; cout << duration << endl;
	cout << setw(20) << "Platform: "; cout << platform << endl;
}

void PlaySession::giveSessions(ostream &info) const
{
	info << user->getName() << "\n"
		 << game->getTitle() << "\n"
		 << date.printDate() << "\n"
		 << duration << "\n"
		 << platform << "\n";
}

