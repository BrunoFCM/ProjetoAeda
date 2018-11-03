#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <iostream>
#include "Game.h"
#include "User.h"

using namespace std;

class System
{
private:
	vector<Game*> store;
	vector<User*> user_library;
public:
	bool addUser(User* user);
	bool addGame(Game* game);
};

#endif /* SRC_SYSTEM_H_ *
