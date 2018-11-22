#ifndef SRC_PLAYSESSION_H_
#define SRC_PLAYSESSION_H_

#include <iostream>
#include "Date.h"
#include "User.h"
#include "Game.h"

using namespace std;

class Date;
class User;

/**
 * Classe PlaySession que contém os dados sobre cada sessão de jogo realizada
 */
class PlaySession
{
private:
	Date date;					//
	unsigned int duration;		//
	string platform;			//
	User* user;					//
	Game* game;					//
public:
	/**
	 *@brief - Construtor da classe PlaySession
	 *@param date -
	 *@param duration -
	 *@param platform -
	 *@param user -
	 */
	PlaySession(const Date date, const int duration, const string platform, User* user, Game* game);

	/**
	 * @brief
	 * @return
	 */
	Date getDate() const;

	/**
	 * @brief
	 * @return
	 */
	unsigned int getDuration() const;

	/**
	 * @brief
	 * @return
	 */
	string getPlatform() const;

	/**
	 * @brief
	 * @return
	 */
	User* getUser() const;

	/**
	* @brief
	* @return
	*/
	Game* getGame() const;

	/**
	* @brief
	* @return
	*/
	void printInfoSession() const;

	/**
	* @brief
	* @return
	*/
	ostream giveSessions() const;
};

#endif /* SRC_PLAYSESSION_H_ */

