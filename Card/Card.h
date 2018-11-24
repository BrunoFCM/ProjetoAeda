#pragma once

#include <string>
#include <iostream>


/**
 *  Classe Card que contem dados sobre cartoes de credito
 */
class Card{
	double balance; 	//correspondente ao saldo do cartao
	std::string card_number; //correspondente ao numero de identificao do cartao
	bool valid;		    //indica a validade do numero do cartao

	/**
	 * @brief Funcao que utiliza o algoritmo de Luhn para verificar a validade do numero do cartao
	 */
	void checkValidity();

public:
	/**
	 * @brief Construtor da classe Card usando apenas o numero do cartao
	 * @param number Numero de identificao do cartao
	 */
	Card(const std::string &number);

	/**
	 * @brief Construtor da classe Card usando o numero do cartao e o respetivo saldo
	 * @param number Numero do cartao
	 * @param bal Valor do saldo do cartao
	 */
	Card(const std::string &number, const double &bal);

	/**
	 * @brief Funcao que altera o valor de balance, caso o numero do cartao seja valido
	 * @param bal Valor do saldo do cartao
	 * @return True se o valor de balance for alterado com sucesso
	 */
	bool setBalance(const double &bal);

	/**
	 * @brief Funcao que altera o numero do cartao, e de seguida o valor de valid a partir da funcao check_validity()
	 * @param number Numero do cartao
	 */
	void setNumber(const std::string &number);

	/**
	 * @brief Funcao que retorna o valor do saldo do cartao (balance)
	 * @return balance Saldo do cartao
	 */
	double getBalance() const;

	/**
	 * @brief Funcao que retorna true se o numero do cartao for valido (valid)
	 * @return valid True se o numero do cartao for valido
	 */
	bool getValidity() const;

	/**
	 * @brief Funcao que retorna o numero do cartao
	 * @return card_number Numero do cartao
	 */
	std::string getNumber() const;

	/**
	 * @brief Imprime informacao relativamente ao cartao
	 */
	void printCard() const;
};
