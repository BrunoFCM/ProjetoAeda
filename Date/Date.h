#ifndef DATE_H_
#define DATE_H_
#include <string>

/**
 *  Classe Date com varias implementacoes: data de lancamento de um jogo, data em que um utilizador jogou um determinado jogo, etc. (ALTERAR DEPOIS)
 */
class Date {
private:
	unsigned int day;			//Dia referente a uma data
	unsigned int month;			//Mes referente a uma data
	unsigned int year;			//Ano referente a uma data

public:
	/**
	 * @brief Construtor da classe Date usando strings
	 * @param date - string de uma data no formato DD-MM-AAAA
	 */
	Date(const std::string &date);

	/**
	 * @brief Construtor da classe Date usando numeros inteiros
	 * @param d - dia de uma data
	 * @param m - mes de uma data
	 * @param y - ano de uma data
	 */
	Date(unsigned int d, unsigned int m, unsigned int y);

	/**
	 * @brief Membro funcao que retorna o dia de uma data
	 * @return Retorna o dia de uma data
	 */
	unsigned int getDay() const;

	/**
	 * @brief Membro funcao que retorna o mes de uma data
	 * @return Retorna o mes de uma data
	 */
	unsigned int getMonth() const;

	/**
	 * @brief Membro funcao que retorna o ano de uma data
	 * @return Retorna o ano de uma data
	 */
	unsigned int getYear() const;

	/**
	 * @brief Membro funcao que permite obter uma data no formato DD-MM-AAAA
	 * @return Retorna string de uma data no formato DD-MM-AAAA
	 */
	std::string getDate() const;
};

#endif /* DATE_H_ */

