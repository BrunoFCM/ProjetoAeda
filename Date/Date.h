#ifndef DATE_H_
#define DATE_H_
#include <string>

/**
 *  Classe Date com várias implementações: data de lançamento de um jogo, data em que um utilizador jogou um determinado jogo, etc. (ALTERAR DEPOIS)
 */
class Date {
private:
	unsigned int day;			//Dia referente a uma data
	unsigned int month;			//Mês referente a uma data
	unsigned int year;			//Ano referente a uma data

public:
	/**
	 * @brief Construtor da classe Date usando strings
	 * @param date - string de uma data no formato DD-MM-AAAA
	 */
	Date(const std::string &date);

	/**
	 * @brief Construtor da classe Date usando números inteiros
	 * @param d - dia de uma data
	 * @param m - mês de uma data
	 * @param y - ano de uma data
	 */
	Date(unsigned int d, unsigned int m, unsigned int y);

	/**
	 * @brief Membro função que retorna o dia de uma data
	 * @return Retorna o dia de uma data
	 */
	unsigned int getDay() const;

	/**
	 * @brief Membro função que retorna o mês de uma data
	 * @return Retorna o mês de uma data
	 */
	unsigned int getMonth() const;

	/**
	 * @brief Membro função que retorna o ano de uma data
	 * @return Retorna o ano de uma data
	 */
	unsigned int getYear() const;

	/**
	 * @brief Membro função que permite obter uma data no formato DD-MM-AAAA
	 * @return Retorna string de uma data no formato DD-MM-AAAA
	 */
	std::string getDate() const;

#endif /* DATE_H_ */
