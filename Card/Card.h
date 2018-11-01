#include <string>

using namespace std;

class Card{
	int balance; //correspondente ao saldo do cartão
	string card_number; //correspondente ao número de identificação do cartão
	bool valid;	//indica a validade do número do cartão
	bool check_validity();
	/**
	 * @brief Função que utiliza o algoritmo de Luhn para verificar a validade do número do cartão
	 * @return True se o valor de card_number for válido, caso contrário retorna false
	 */
public:
	Card(string number);
	/**
	 * @brief Construtor da classe Card usando apenas o número do cartão
	 * @param number - número do cartão
	 */
	Card(string number, int bal);
	/**
	 * @brief Construtor da classe Card usando o número do cartão e o respetivo saldo
	 * @param number - número do cartão
	 * @param bal - valor do saldo do cartão
	 */
	bool set_balance(int bal);
	/**
	 * @brief Função que altera o valor de balance, caso o número do cartão seja válido
	 * @param bal - valor do saldo do cartão
	 * @return True se o valor de balance for alterado com sucesso
	 */
	void set_number(string number);
	/**
	 * @brief Função que altera o número do cartão, e de seguida o valor de valid a partir da função check_validity()
	 * @param number - número do cartão
	 */
	int get_balance() const;
	bool get_validity() const;
	string get_number() const;
};



