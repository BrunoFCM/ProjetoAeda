#include "Card.h"
#include <string>

#define ASCII_0 48 //corresponde ao valor de '0' na tabela ASCII

void Card::checkValidity()
/* Esta função utiliza o algoritmo de Luhn para verificar se o número do cartão é válido */
{
	if (card_number.length() != 16) {
		valid = false;
		return;
	}
	int sum = 0;
	for (int i = card_number.length() - 1; i>=0; i += -2)
		sum += (int)(card_number[i] - ASCII_0);
	for (int i = card_number.length() - 2; i>=0; i += -2)
	{
		int value = 2 * (int)(card_number[i] - ASCII_0);
		if (value > 9)
			value = (value % 10) + (value / 10);
		sum += value;
	}
	if (sum % 10)
		valid = false;
	else
		valid = true;
	return;
}

Card::Card(string number)
{
	card_number = number;
	check_validity();
	balance = 0;
}

Card::Card(string number, int bal)
{
	card_number = number;
	check_validity();
	if (valid)
		balance = bal;
	else
		balance = 0;
}

bool Card::setBalance(int bal)
{
	if (valid)
	{
		balance = bal;
		return true;
	}
	else return false;
}

void Card::setNumber(string number)
{
	card_number = number;
	check_validity(); //atualizar o valor de valid
	if (!valid)
		balance = 0;
}

int Card::getBalance() const {return balance;}

bool Card::getValidity() const {return valid;}

string Card::getNumber() const {return card_number;}

