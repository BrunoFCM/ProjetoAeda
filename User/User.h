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

class User
{
private:
	string name;
	string email;
	unsigned int age;
	string address;
	vector<Card> cards;
	vector<Game*> library;
	vector<PlaySession*> sessions;
public:
	User(const string &name, const string &email, const unsigned int &age, const string &address);
	void addToLibrary(Game* game);
	string getName() const;
	string getEmail() const;
	unsigned int getAge() const;
	string getAddress() const;
	vector<Card> getCards() const;
	vector<Game*> getLibrary() const;
	vector<PlaySession*> getSessions() const;
	bool operator==(const User &user) const;
};

#endif /* SRC_USER_H_ */
