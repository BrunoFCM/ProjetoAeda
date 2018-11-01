#ifndef SRC_CARD_H_
#define SRC_CARD_H_

#include <string>

using namespace std;

class Card{
	int balance;
	string card_number;
	bool valid;
	bool check_validity();
public:
	Card(string number);
	Card(string number, int bal);
	bool set_balance(int bal);
	void set_number(string number);
};



#endif /* SRC_CARD_H_ */
