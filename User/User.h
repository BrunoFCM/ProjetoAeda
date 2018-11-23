#ifndef SRC_USER_H_
#define SRC_USER_H_
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Game.h"
#include "PlaySession.h"

using namespace std;

class PlaySession;
class Game;


/**
 * Classe User que contem dados sobre cada utilizador da biblioteca de jogos
 */
class User
{
private:
	string name;						//correspondente ao nome do utilizador
	string email;						//correspondente ao endereco eletronico
	unsigned int age;					//correspondente a idade do utilizador
	string address;						//correspondente a morada do utilizador
	vector<Card> cards;					//correspondente ao conjunto dos cartoes do utilizador
	vector<Game*> library;				//correspondente ao conjunto dos jogos do utilizador
	vector<PlaySession*> sessions;		//correspondente ao conjunto dos historiais de cada sessao de jogo

public:
	/**
	 * @brief Construtor da classe User
	 * @param name Nome do jogador
	 * @param email Endereco eletronico
	 * @param age Idade do jogador
	 * @param adress Morada do jogador
	 */
	User(const string &name, const string &email, const unsigned int &age, const string &address);

	/**
	 * @brief Funcao que adiciona um jogo a biblioteca de jogos
	 * @param game Jogo a adicionar
	 */
	void addToLibrary(Game* game);

	/**
	 * @brief Funcao que retorna o nome do utilizador
	 * @return Retorna o nome de um utilizador
	 */
	string getName() const;

	/**
	 * @brief Funcao que retorna o endereco eletronico do utilizador
	 * @return Retorna o endereco eletronico do utilizador
	 */
	string getEmail() const;

	/**
	 * @brief Funcao que retorna a idade do utilizador
	 * @return Retorna a idade do utilizador
	 */
	unsigned int getAge() const;

	/**
	 * @brief Funcao que retorna a morada do utilizador
	 * @return Retorna a morada de um utilizador
	 */
	string getAddress() const;

	/**
	 * @brief Funcao que retorna um vetor com o conjunto dos cartoes do utilizador
	 * @return Retorna um vetor com o conjunto dos cartoes de um utilizador
	 */
	vector<Card> getCards() const;

	/**
	 * @brief Funcao que retorna um vetor com o conjunto dos jogos da biblioteca do utilizador
	 * @return Um vetor com o conjunto dos jogos da biblioteca de um utilizador
	 */
	vector<Game*> getLibrary() const;

	/**
	 * @brief Funcao que retorna um vetor com o conjunto dos historiais de cada sessao de jogo
	 * @return Retorna um vetor com o conjunto dos historiais de cada sessao de jogo
	 */
	vector<PlaySession*> getSessions() const;

	/**
	 * @brief Overload do operador == para igualdade de dois utilizadores
	 * @param user Utilizador
	 * @return Retorna true se os utilizadores sao iguais, false caso contrario
	 */
	bool operator==(const User &user) const;

	/**
	* @brief Funcao que imprime no ecra "in a human friendly way" a informacao (membros-dado) de um utilizador
	*/
	void printInfoUser() const;

	/**
	* @brief Funcao que passa para uma ostream a informacao (membros-dado) de um utilizador
	* @param info Ostream que ira conter a informacao (membros-dado) de um utilizador
	*/
	void giveInfoUser(ostream &info) const;

	/**
	* @brief Funcao que imprime no ecra os titulos dos jogos de um utilizador
	* @param numberOfGames Numero de titulos a serem impressos
	*/
	void printLibraryUser(int numberOfGames = 0) const;

	/**
	* @brief Funcao que passa para uma ostream os titulos dos jogos de um utilizador
	* @param numberOfGames Numero de titulos a serem passados
	* @return Retorna uma ostream que contem os titulos dos jogos de um utilizador
	*/
	ostream giveLibraryUser(int numberOfGames = 0) const;

	/**
	* @brief Funcao que imprime no ecra os numeros dos cartoes de um utilizador
	* @param numberOfCards Numero de numeros a serem impressos
	*/
	void printCardsUser(int numberOfCards = 0) const;

	/**
	* @brief Funcao que passa para uma ostream os numeros dos cartoes de um utilizador
	* @param numberOfCards Numero de numeros a serem passados
	* @return Retorna um ostream que contem os numeros dos cartoes de um utilizador
	*/
	ostream giveCardsUser(int numberOfCards = 0) const;

	/**
	* @brief Funcao que imprime no ecra os historiais de cada sessao de jogo
	* @param numberOfSessions Numero de sessoes a serem impressas
	*/
	void printSessionsUser(int numberOfSessions = 0) const;

	/**
	* @brief Funcao que passa para uma ostream os historiais de cada sessao de jogo
	* @param numberOfSessions Numero de sessoes a serem passadas
	* @return Retorna uma ostream que contem as sessoes de um utilizador
	*/
	ostream giveSessionsUser(int numberOfSessions = 0) const;
};

#endif /* SRC_USER_H_ */

