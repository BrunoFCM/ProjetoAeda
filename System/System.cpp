#include <iostream>
#include "System.h"

using namespace std;

bool System::addUser(User* user)
{
	for (size_t i = 0; i < user_library.size(); i++)
		if (user == user_library[i])
		{
			throw RepeatedUser();
			return false;
		}
	user_library.push_back(user);
	return true;
}

bool System::addGame(Game* game)
{
	for (size_t i = 0; i < store.size(); i++)
		if (game == store[i])
		{
			throw RepeatedGame();
			return false;
		}
	store.push_back(game);
	return true;
}



