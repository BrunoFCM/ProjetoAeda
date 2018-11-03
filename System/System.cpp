#include <iostream>
#include "System.h"

using namespace std;

void System::addUser(User* user)
{
	for (size_t i = 0; i < user_library.size(); i++)
		if (user == user_library[i])
			throw RepeatedUser();
	user_library.push_back(user);
}

void System::addGame(Game* game)
{
	for (size_t i = 0; i < store.size(); i++)
		if (game == store[i])
			throw RepeatedGame();
	store.push_back(game);
}




