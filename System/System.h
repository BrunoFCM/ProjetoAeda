#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <iostream>
#include "Game.h"
#include "User.h"
#include "Sorts.h"
#include "Restricts.h"

using namespace std;

/**
 * Classe System - classes base onde sao guardados os utilizadores e os jogos
 */
class System
{
	vector<Game*> store;		//base de dados com o conjunto de todos os jogos
	vector<User*> user_library; //base de dados com o conjunto de todos os utilizadores

public:
	/**
	 * @brief Funcao que adiciona um utilizador ao vetor user_library
	 * @param user Utilizador a ser adicionado
	 */
	void addUser(User* user);

 	/**
	 * @brief Funcao que adiciona um jogo ao vetor store
	 * @param game Jogo a ser adicionado
	 */
	void addGame(Game* game);

 	/**
	 * @brief Funcao que pesquisa um jogo atraves do seu id (passado como argumento)
	 * @param id Numero de identificacao de um jogo
	 * @return Retorna o jogo pesquisado
	 */
	Game* searchGame(unsigned int id);

	/**
	* @brief Funcao que pesquisa um jogo atraves do seu titulo (passado como argumento)
	* @param title Titulo de um jogo
	* @return Retorna o jogo pesquisado
	*/
	Game* searchGame(string title);

	/**
	 * @brief Funcao que pesquisa um utilizador atraves do seu nome (passado como argumento)
	 * @param name Nome de um utilizador
	 * @return Retorna o utilizador pesquisado
	 */
	User* searchUser(string name);

	/**
	 * @brief Funcao que ordena o vetor de utilizadores atraves de um termo comparatorio
	 * @param comparer Elemento usado para a comparacao
	 */
	void sortUsers(const UserComparer &comparer);

 	/**
	 * @brief Funcao que ordena o vetor de jogos atraves de um termo comparatorio
	 * @param comparer Elemento usado para a comparacao
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

