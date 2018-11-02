#pragma once

#include <string>

using namespace std;

class Card{
	int balance; //correspondente ao saldo do cartão
	string card_number; //correspondente ao número de identificação do cartão
	bool valid;	//indica a validade do número do cartão

	/**
	 * @brief Função que utiliza o algoritmo de Luhn para verificar a validade do número do cartão
	 */
	void checkValidity();
	
public:
	/**
	 * @brief Construtor da classe Card usando apenas o número do cartão
	 * @param number - número do cartão
	 */
	Card(string number);
	
	/**
	 * @brief Construtor da classe Card usando o número do cartão e o respetivo saldo
	 * @param number - número do cartão
	 * @param bal - valor do saldo do cartão
	 */
	Card(string number, int bal);
	
	/**
	 * @brief Função que altera o valor de balance, caso o número do cartão seja válido
	 * @param bal - valor do saldo do cartão
	 * @return True se o valor de balance for alterado com sucesso
	 */
	bool setBalance(int bal);
	
	/**
	 * @brief Função que altera o número do cartão, e de seguida o valor de valid a partir da função check_validity()
	 * @param number - número do cartão
	 */
	void setNumber(string number);
	
	/**
	 * @brief Função que retorna o valor do saldo do cartão (balance)
	 * @return balance - saldo do cartão
	 */
	int getBalance() const;
	
	/**
	 * @brief Função que retorna se o número do cartão é válido (valid)
	 * @return valid - True se o número do cartão é válido
	 */
	bool getValidity() const;
	
	/**
	 * @brief Função que retorna o número do cartão
	 * @return card_number - número do cartão
	 */
	string getNumber() const;
};
