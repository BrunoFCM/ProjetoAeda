#include <iostream>
#include "PlaySession.h"

using namespace std;

PlaySession::PlaySession(const Date date, const int duration, const string platform, User* user): date(date), duration(duration), user(user) {}

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
