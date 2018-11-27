#ifndef SRC_USER_H_
#define SRC_USER_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>
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
	string name;							//correspondente ao nome do utilizador
	string email;							//correspondente ao endereco eletronico
	unsigned int age;						//correspondente a idade do utilizador
	string address;							//correspondente a morada do utilizador
	vector<Card> cards;						//correspondente ao conjunto dos cartoes do utilizador
	vector<Game*> library;					//correspondente ao conjunto dos jogos do utilizador
	vector<PlaySession*> sessions;			//correspondente ao conjunto dos historiais de cada sessao de jogo
	map<string,vector<Date>> updates; 		//correspondente ao conjunto de conjuntos de updates de cada jogo

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
	 * @brief Funcao que verifica se um jogo ja se encotra na biblioteca de jogos
	 * @param game Jogo a procurar
	 * @return True se o jogo ja esta na biblioteca do utilizador
	 */
	bool checkLibraryFor(Game* game) const;

	/**
	 * @brief Funcao que adiciona um cartao ao vetor de cartoes
	 * @param card Cartao a adicionar
	 */
	void addCard(const Card &card);

	/**
	 * @brief Funcao que adiciona uma sessao de jogo ao historico do utilizador
	 * @param sess Sessao a adicionar
	 */
	void addSession(PlaySession *sess);

	/**
	 * @brief Funcao que retorna o nome do utilizador
	 * @return name Nome do utilizador
	 */
	string getName() const;

	/**
	 * @brief Funcao que retorna o endereco eletronico do utilizador
	 * @return email Endereco eletronico do utilizador
	 */
	string getEmail() const;

	/**
	 * @brief Funcao que retorna a idade do utilizador
	 * @return age Idade do utilizador
	 */
	unsigned int getAge() const;

	/**
	 * @brief Funcao que retorna a morada do utilizador
	 * @return address Morada do utilizador
	 */
	string getAddress() const;

	/**
	 * @brief Funcao que retorna um vetor com o conjunto dos cartoes do utilizador
	 * @return cards Vetor com o conjunto dos cartoes do utilizador
	 */
	vector<Card> getCards() const;

	/**
	 * @brief Funcao que retorna um vetor com o conjunto dos jogos da biblioteca do utilizador
	 * @return Retorna um vetor com o conjunto dos jogos da biblioteca do utilizador
	 */
	vector<Game*> getLibrary() const;

	/**
	 * @brief Funcao que retorna um vetor com o conjunto dos historiais de cada sessao de jogo
	 * @return Retorna um vetor com o conjunto dos historiais de cada sessao de jogo
	 */
	vector<PlaySession*> getSessions() const;

	/**
	 * @brief Funcao que retorna um map com o conjunto de conjuntos de updates de cada jogo
	 * @return Retorna um map com o conjunto de conjuntos de updates de cada jogo
	 */
	map<string,vector<Date>> getUpdates() const;

	/**
	 * @brief Funcao que imprime os conteudos do map dos updates transferidos pelo utilizador
	 * @param numberOfUpdates Numero de updates a imprimir
	 */
	void printUpdates(unsigned int numberOfUpdates = 0) const;

	/**
	 * @brief Overload do operador == para igualdade de dois utilizadores
	 * @param user Utilizador
	 * @return True se os utilizadores sao iguais, false caso contrario
	 */
	bool operator==(const User &user) const;

	/**
	* @brief Funcao que imprime no ecra "in a human friendly way" a informacao (membros-dado) de um utilizador
	*/
	void printInfoUser() const;

	/**
	* @brief Funcao que passa para uma fstream a informacao (membros-dado) de um utilizador
	* @param info Ofstream que ira conter a informacao (membros-dado) de um utilizador
	*/
	void giveInfoUser(ofstream &info) const;

	/**
	* @brief Funcao que imprime no ecra os titulos dos jogos de um utilizador
	* @param numberOfGames Numero de titulos a serem impressos
	*/
	void printLibraryUser(unsigned int numberOfGames = 0) const;

	/**
	* @brief Funcao que passa para uma fstream os titulos dos jogos de um utilizador
	* @param titles Ofstream que contem os titulos dos jogos de um utilizador
	*/
	void giveLibraryUser(ofstream &titles) const;

	/**
	* @brief Funcao que imprime no ecra os numeros dos cartoes de um utilizador
	* @param numberOfCards Numero de numeros a serem impressos
	* @param titles Ostream na qual e guardada a informacao
	*/
	void printCardsUser (unsigned int numberOfCards = 0) const;

	/**
	* @brief Funcao que passa para uma fstream os numeros dos cartoes de um utilizador
	* @param numbers Ostream que contem os numeros dos cartoes de um utilizador
	*/
	void giveCardsUser(ofstream &numbers) const;

	/**
	* @brief Funcao que imprime no ecra os historiais de cada sessao de jogo
	* @param numberOfSessions Numero de sessoes a serem impressas
	* @param numbers Ostream na qual e guardada a informacao
	*/
	void printSessionsUser(unsigned int numberOfSessions = 0) const;

	/**
	* @brief Funcao que instala os updates de um jogo para o utilizador
	* @param game Jogo com updates para instalar
	* @return True se forem instalados updates no jogo, false se o jogo ja estiver atualizado
	*/
	bool installUpdates(Game* game);

	/**
	* @brief Funcao que retorna a referencia de um card do utilizador
	* @param index Indice do card pedido
	* @return Referencia ao card pedido
	*/
	Card & getCardRef(unsigned int index);
};

#endif /* SRC_USER_H_ */

