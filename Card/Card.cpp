#include <iomanip>
#include "Card.h"

#define ASCII_0 48 //corresponde ao valor de '0' na tabela ASCII

void Card::checkValidity()
/* Esta funcao utiliza o algoritmo de Luhn para verificar se o numero do cartao Ã© valido */
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

Card::Card(const std::string &number)
{
	card_number = number;
	checkValidity();
	balance = 0;
}

Card::Card(const std::string &number, const double &bal)
{
	card_number = number;
	checkValidity();
	if (valid)
		balance = bal;
	else
		balance = 0;
}

bool Card::setBalance(const double &bal)
{
	if (valid)
	{
		balance = bal;
		return true;
	}
	else return false;
}

void Card::setNumber(const std::string &number)
{
	card_number = number;
	checkValidity(); //atualizar o valor de valid
	if (!valid)
		balance = 0;
}

double Card::getBalance() const {return balance;}

bool Card::getValidity() const {return valid;}

std::string Card::getNumber() const {return card_number;}

void Card::printCard() const
{
	std::string validity;
	if (valid)
		validity = "Yes";
	else
		validity = "No";

	std::cout << "Card number: " << getNumber() << std::endl;
	std::cout << "Balance: " << std::setprecision(2) << getBalance() << std::endl;
	std::cout << "Valid: " << validity << std::endl;

}

