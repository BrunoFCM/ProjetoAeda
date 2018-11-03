#ifndef SRC_PLAYSESSION_H_
#define SRC_PLAYSESSION_H_

#include <iostream>
#include "Date.h"
#include "User.h"

using namespace std;

class PlaySession
{
private:
	Date date;
	unsigned int duration;
	string platform;
	User* user;
public:
	PlaySession(Date date, int duration, string platform, User* user);
	Date getDate() const;
	unsigned int getDuration() const;
	string getPlatform() const;
	User* getUser() const;
};

#endif /* SRC_PLAYSESSION_H_ */
