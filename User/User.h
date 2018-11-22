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
 * Classe User que contém dados sobre cada utilizador da biblioteca de jogos
 */
class User
{
private:
	string name;						//
	string email;						//
	unsigned int age;					//
	string address;						//
	vector<Card> cards;					//
	vector<Game*> library;				//
	vector<PlaySession*> sessions;		//
public:
	/**
	 * @brief - Construtor da classe User
	 * @param name -
	 * @param email -
	 * @param age -
	 * @param adress -
	 */
	User(const string &name, const string &email, const unsigned int &age, const string &address);

	/**
	 * @brief
	 * @param game -
	 */
	void addToLibrary(Game* game);

	/**
	 * @brief
	 * @return
	 */
	string getName() const;

	/**
	 * @brief
	 * @return
	 */
	string getEmail() const;

	/**
	 * @brief
	 * @return
	 */
	unsigned int getAge() const;

	/**
	 * @brief
	 * @return
	 */
	string getAddress() const;

	/**
	 * @brief
	 * @return
	 */
	vector<Card> getCards() const;

	/**
	 * @brief
	 * @return
	 */
	vector<Game*> getLibrary() const;

	/**
	 * @brief
	 * @return
	 */
	vector<PlaySession*> getSessions() const;

	/**
	 * @brief
	 * @param user -
	 * @return
	 */
	bool operator==(const User &user) const;

	/**
	* @brief
	* @return
	*/
	void printInfoUser() const;

	/**
	* @brief
	* @return
	*/
	ostream giveInfoUser() const;

	/**
	* @brief
	* @param numberOfGames -
	* @return
	*/
	void printLibraryUser(int numberOfGames = 0) const;

	/**
	* @brief
	* @param numberOfGames -
	* @return
	*/
	ostream giveLibraryUser(int numberOfGames = 0) const;

	/**
	* @brief
	* @param numberOfCards -
	* @return
	*/
	void printCardsUser(int numberOfCards = 0) const;

	/**
	* @brief
	* @param numberOfCards -
	* @return
	*/
	ostream giveCardsUser(int numberOfCards = 0) const;
};

#endif /* SRC_USER_H_ */

