#ifndef SRC_PLAYSESSION_H_
#define SRC_PLAYSESSION_H_

#include <iostream>
#include "Date.h"
#include "User.h"
#include "Game.h"

using namespace std;

class Date;
class User;
class Game;

/**
 * Classe PlaySession que contem os dados sobre cada sessao de jogo realizada
 */
class PlaySession
{
private:
	Date date;					//Data de inicio de uma sessao
	unsigned int duration;		//Duracao de tempo (em horas) de uma sessao
	string platform;			//Plataforma em que a sessao foi realizada
	User* user;					//Utilizador que realizou a sessao
	Game* game;					//Jogo correspondente a sessao

public:
	/**
	 *@brief Construtor da classe PlaySession
	 *@param date Data de inicio de uma sessao
	 *@param duration Duracao de tempo de uma sessao
	 *@param platform Plataforma em que a sessao foi realizada
	 *@param user Utilizador que realizou a sessao
	 *@param game Jogo correspondente a sessao
	 */
	PlaySession(const Date date, const int duration, const string platform, User* user, Game* game);

	/**
	 * @brief Funcao que retorna a data de inicio de uma sessao
	 * @return Retorna a data de inicio de uma sessao
	 */
	Date getDate() const;

	/**
	 * @brief Funcao que retorna a duracao de uma sessao (em horas)
	 * @return Retorna a duracao de uma sessao (em horas)
	 */
	unsigned int getDuration() const;

	/**
	 * @brief Funcao que retorna a plataforma em que a sessao foi realizada
	 * @return Retorna a plataforma em que a sessao foi realizada
	 */
	string getPlatform() const;

	/**
	 * @brief Funcao que retorna o utilizador que realizou a sessao
	 * @return Retorna o utilizador que realizou a sessao
	 */
	User* getUser() const;

	/**
	 * @brief Funcao que retorna o jogo correspondente a sessao
	 * @return Retorna o jogo correspondente a sessao
	 */
	Game* getGame() const;

	/**
	 * @brief Funcao que imprime no ecra "in a human friendly way" a informacao de uma sessao
	 */
	void printInfoSession() const;

	/**
	* @brief Funcao que passa para uma ostream a informacao de uma sessao
	* @param info Ostream que recebe a informacao de uma sessao
	*/
	void giveSessions(ofstream &info) const;
};

#endif /* SRC_PLAYSESSION_H_ */

