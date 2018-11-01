#include "Card.h"
#include <string>

#define ASCII_0 48 //corresponde ao valor de '0' na tabela ASCII

bool Card::check_validity()
/* Esta função utiliza o algoritmo de Luhn para verificar se o número do cartão é válido */
{
	if (card_number.length() != 16)
		return false;
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
		return false;
	else
		return true;
}

Card::Card(string number)
{
	card_number = number;
	valid = check_validity();
	balance = 0;
}

Card::Card(string number, int bal)
{
	card_number = number;
	valid = check_validity();
	if (valid)
		balance = bal;
	else
		balance = 0;
}

bool Card::set_balance(int bal)
{
	if (valid)
	{
		balance = bal;
		return true;
	}
	else return false;
}

void Card::set_number(string number)
{
	card_number = number;
	valid = check_validity(); //atualizar o valor de valid
	if (!valid)
		balance = 0;
}

int Card::get_balance() const {return balance;}

bool Card::get_validity() const {return valid;}

string Card::get_number() const {return card_number;}

