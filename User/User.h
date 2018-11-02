/*
 * User.h
 *
 *  Created on: 02/11/2018
 *      Author: Nuno Cardoso
 */

#ifndef SRC_USER_H_
#define SRC_USER_H_
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Game.h"

using namespace std;

class User
{
private:
	string name;
	string email;
	unsigned int age;
	string address;
	vector<Card> cards;
	vector<Game*> library;
	vector<PlaySessions*> sessions;
public:
	User(const string &name, const string &email, const unsigned int &age, const string &address);
	bool addToLibrary(Game* game);
	string getName() const;
	string getEmail() const;
	unsigned int getAge() const;
	string getAddress() const;
	vector<Card> getCards() const;
	vector<Game*> getLibrary() const;
	vector<PlaySessions*> getSessions() const;
};

#endif /* SRC_USER_H_ */
