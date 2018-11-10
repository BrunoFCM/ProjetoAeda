#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <iostream>
#include "Game.h"
#include "User.h"
#include "Sorts.h"
#include "Restricts.h"

using namespace std;

class System
{
private:
	vector<Game*> store;
	vector<User*> user_library;
public:
	void addUser(User* user);
	void addGame(Game* game);
	void sortUsers(const UserComparer &comparer);
	void sortGames(const GameComparer &comparer);
	template <class Restrictor, class Argument>
	vector<User*> sortUsersRestrict(const Restrictor &func, const Argument &arg){/*
		if(!properRestrictor(func, USER_RESTRICTOR)) throw InvalidRestrictor();
		if(!properArgument(func, arg)) throw InvalidArgument();*/
		return restrictedVector(user_library,func,arg);
	}
	template <class Restrictor, class Argument>
	vector<Game*> sortGamesRestrict(const Restrictor &func, const Argument &arg){/*
		if(!properRestrictor(func, GAME_RESTRICTOR)) throw InvalidRestrictor();
		if(!properArgument(func, arg)) throw InvalidArgument();*/
		return restrictedVector(user_library,func,arg);
	}
};

#endif /* SRC_SYSTEM_H_ */

