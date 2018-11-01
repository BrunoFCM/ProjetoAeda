#include "Card.h"

bool Card::check_validity()
/* Esta função utiliza o algoritmo de Luhn para verificar se o número do cartão é válido */
{
	if (number.length() != 16)
		return false;
	int sum = 0;
	for (unsigned int i = number.length() - 1; i>=0; i += -2)
		sum += atoi(number[i]);
	for (unsigned int i = number.length() - 2; i>=0; i += -2)
	{
		int value = 2 * atoi(number[i]);
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
		bal = 0;
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
	check_validity;
}



