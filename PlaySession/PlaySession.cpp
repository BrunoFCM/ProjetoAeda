#include <iostream>
#include "PlaySession.h"

using namespace std;

PlaySession::PlaySession(Date date, int duration, string platform, User* user)
{
	this->date = date;
	this->duration = duration;
	this->user = user;
}

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







