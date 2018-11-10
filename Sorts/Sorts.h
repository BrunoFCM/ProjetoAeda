#pragma once

#include "Game.h"
#include "User.h"
#include "Exceptions.h"
#include <type_traits>

typedef bool (*GameComparer)(Game*,Game*);
typedef bool (*UserComparer)(User*,User*);

bool userNameAscend(User* user1,User* user2);
bool userNameDescend(User* user1,User* user2);
bool userAgeAscend(User* user1,User* user2);
bool userAgeDescend(User* user1,User* user2);

bool gameIdAscend(Game* user1,Game* user2);
bool gameIdDescend(Game* user1,Game* user2);
bool gameTitleAscend(Game* user1,Game* user2);
bool gameTitleDescend(Game* user1,Game* user2);
bool gamePriceAscend(Game* user1,Game* user2);
bool gamePriceDescend(Game* user1,Game* user2);
bool gameBasePriceAscend(Game* user1,Game* user2);
bool gameBasePriceDescend(Game* user1,Game* user2);
bool gameReleaseAscend(Game* user1,Game* user2);
bool gameReleaseDescend(Game* user1,Game* user2);
bool gameAgeRangeAscend(Game* user1,Game* user2);
bool gameAgeRangeDescend(Game* user1,Game* user2);
bool gameDeveloperAscend(Game* user1,Game* user2);
bool gameDeveloperDescend(Game* user1,Game* user2);



template <class T>
static bool isUserComparer(const T &func){
	return (std::is_same<T,UserComparer>::value);
}

template <class T>
static bool isGameComparer(const T &func){
	return (std::is_same<T,GameComparer>::value);
}



template <class Comparable, class Comparator>
void insertionSort(vector<Comparable> &v, Comparator func)
{
    for (unsigned int p = 1; p < v.size(); p++)
    {
    	Comparable tmp = v[p];
    	int j;
    	for (j = p; j > 0 && func(tmp, v[j-1]); j--)
    		v[j] = v[j-1];
    	v[j] = tmp;
    }
}


