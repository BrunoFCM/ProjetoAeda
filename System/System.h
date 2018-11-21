#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <iostream>
#include "Game.h"
#include "User.h"
#include "Sorts.h"
#include "Restricts.h"

using namespace std;

/**
 * Classe System - classes base onde são guardados os utilizadores e os jogos
 */
class System
{
private:
	vector<Game*> store;			//
	vector<User*> user_library;		//
public:
	/**
	 * @brief
	 * @param user -
	 */
	void addUser(User* user);

	/**
	 * @brief
	 * @param game -
	 */
	void addGame(Game* game);

	/**
	 * @brief
	 * @param comparer -
	 */
	void sortUsers(const UserComparer &comparer);

	/**
	 * @brief
	 * @param comparer -
	 */
	void sortGames(const GameComparer &comparer);


	template <class Restrictor, class Argument>
	/**
	 * @brief
	 * @param func -
	 * @param arg -
	 * @return
	 */
	vector<User*> sortUsersRestrict(const Restrictor &func, const Argument &arg){
		if(!properRestrictor(func, USER_RESTRICTOR)) throw InvalidRestrictor();
		if(!properArgument(func, arg)) throw InvalidArgument();
		return restrictedVector(user_library,func,arg);
	}


	template <class Restrictor, class Argument>
	/**
	 * @brief
	 * @param func -
	 * @param arg -
	 * @return
	 */
	vector<Game*> sortGamesRestrict(const Restrictor &func, const Argument &arg){
		if(!properRestrictor(func, GAME_RESTRICTOR)) throw InvalidRestrictor();
		if(!properArgument(func, arg)) throw InvalidArgument();
		return restrictedVector(user_library,func,arg);
	}
};

#endif /* SRC_SYSTEM_H_ */
