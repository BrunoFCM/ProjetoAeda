#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <iostream>
#include <fstream>
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
	* @brief Construtor default de system
	*/
	System();

	/**
	* @brief Construtor de system que importa a informacao a partir de um ficheiro
	* @param file Referencia a uma stream de ficheiro que contem as informacoes de system
	*/
	System(ifstream &file);
	/**
	* @brief Destrutor da classe System
	*/
	~System();

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

	/**
	 * @brief Funcao que traduz a compra de um jogo por parte de um utilizador e com um cartao
	 * @param user Utilizador
	 * @param game Jogo
	 * @param card Cartao
	 */
	void buyGame(User* user, Game* game, unsigned int id);

	template <class Restrictor, class Argument>
	/**
	 * @brief Funcao template para restricao de procuras de utilizadores
	 * @param func Funcao de restricao
	 * @param arg Argumento de restricao
	 * @return Vetor de utilizadores apos restricao
	 */
	vector<User*> restrictUsers(const Restrictor &func, const Argument &arg){
		return restrictedVector(user_library,func,arg);
	}

	template <class Restrictor, class Argument>
	/**
	 * @brief Funcao template para restricao de procuras de jogos
	 * @param func Funcao de restricao
	 * @param arg Argumento de restricao
	 * @return Vetor de jogos apos restricao
	 */
	vector<Game*> restrictGames(const Restrictor &func, const Argument &arg){
		return restrictedVector(store,func,arg);
	}

	/**
	* @brief Funcao que passa para uma ofstream a informacao relativa ao sistema
	*/
	void giveInfoSystem(ofstream &info) const;


};

#endif /* SRC_SYSTEM_H_ */

