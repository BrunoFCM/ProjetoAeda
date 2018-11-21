#pragma once

#include "Game.h"
#include "User.h"
#include "Interval.h"
#include "Date.h"
#include "Exceptions.h"
#include <string>
#include <type_traits>

#define USER_RESTRICTOR true
#define GAME_RESTRICTOR false

/**
 * @brief
 * @param g1 -
 * @param inter -
 * @return
 */
bool gameIdInterval(Game* g1, const Interval &inter);

/**
 * @brief
 * @param g1 -
 * @param max -
 * @return
 */
bool gamePriceMax(Game* g1, const double &max);

/**
 * @brief
 * @param g1 -
 * @param date -
 * @return
 */
bool gameRelease(Game* g1, const Date &date);

/**
 * @brief
 * @param g1 -
 * @param inter -
 * @return
 */
bool gameAgeRange(Game* g1, const Interval &inter);

/**
 * @brief
 * @param g1 -
 * @param platform -
 * @return
 */
bool gamePlatform(Game* g1, const std::string &platform);

/**
 * @brief
 * @param g1 -
 * @param genre -
 * @return
 */
bool gameGenre(Game* g1, const std::string &genre);

/**
 * @brief
 * @param g1 -
 * @param developer -
 * @return
 */
bool gameDeveloper(Game* g1, const std::string &developer);


/**
 * @brief
 * @param u1 -
 * @param inter -
 * @return
 */
bool userAgeInterval(User* u1, const Interval &inter);

/**
 * @brief
 * @param u1 -
 * @param inter -
 * @return
 */
bool userLibrarySize(User* u1, const Interval &inter);



template <class Restrictor>
/**
 * @brief
 * @param func -
 * @param is_user_restrictor -
 * @return
 */
bool properRestrictor(Restrictor func, const bool &is_user_restrictor){
	switch(func){
	case &gameIdInterval:
	case &gameAgeRange:
	case &gamePlatform:
	case &gameGenre:
	case &gameDeveloper:
	case &gamePriceMax:
	case &gameRelease:
		return !is_user_restrictor;
	case &userAgeInterval:
	case &userLibrarySize:
		return is_user_restrictor;
	default:
		return false;
	}
}


template <class Restrictor, class Argument>
/**
 * @brief
 * @param func -
 * @param arg -
 * @return
 */
bool properArgument(Restrictor func, Argument arg){
	switch(func){
	case &gameIdInterval:
	case &gameAgeRange:
	case &userAgeInterval:
	case &userLibrarySize:
		return (std::is_same<Argument,Interval>::value);
	case &gamePriceMax:
		return (std::is_same<Argument,double>::value);
	case &gameRelease:
		return (std::is_same<Argument,Date>::value);
	case &gamePlatform:
	case &gameGenre:
	case &gameDeveloper:
		return (std::is_same<Argument,std::string>::value);
	default:
		return false;
	}
}



template <class Comparable, class Restrictor, class Argument>
/**
 * @brief
 * @param v -
 * @param func -
 * @param arg -
 * @return
 */
vector<Comparable> restrictedVector(const vector<Comparable> &v, Restrictor func, Argument arg)
{
	vector <Comparable> out;
    for (unsigned int i = 0; i < v.size(); i++)
    	if (func(v[i], arg))
    		out.push_back(v[i]);
    return out;
}
