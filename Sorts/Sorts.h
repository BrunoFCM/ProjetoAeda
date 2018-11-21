#pragma once

#include "Game.h"
#include "User.h"
#include "Exceptions.h"
#include <type_traits>

typedef bool (*GameComparer)(Game*,Game*);
typedef bool (*UserComparer)(User*,User*);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool userNameAscend(User* user1,User* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool userNameDescend(User* user1,User* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool userAgeAscend(User* user1,User* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool userAgeDescend(User* user1,User* user2);


/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameIdAscend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameIdDescend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameTitleAscend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameTitleDescend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gamePriceAscend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gamePriceDescend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameBasePriceAscend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameBasePriceDescend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameReleaseAscend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameReleaseDescend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameAgeRangeAscend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameAgeRangeDescend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameDeveloperAscend(Game* user1,Game* user2);

/**
 * @brief
 * @param user1 -
 * @param user2 -
 * @return
 */
bool gameDeveloperDescend(Game* user1,Game* user2);



template <class T>
/**
 * @brief
 * @param func -
 * @return
 */
static bool isUserComparer(const T &func){
	return (std::is_same<T,UserComparer>::value);
}

template <class T>
/**
 * @brief
 * @param func -
 * @return
 */
static bool isGameComparer(const T &func){
	return (std::is_same<T,GameComparer>::value);
}



template <class Comparable, class Comparator>
/**
 * @brief
 * @param func -
 * @return
 */
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
