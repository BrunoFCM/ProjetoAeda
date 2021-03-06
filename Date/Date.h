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
	 * @param date String de uma data no formato DD/MM/AAAA
	 */
	Date(const std::string &date);

	/**
	 * @brief Construtor da classe Date usando numeros inteiros
	 * @param d Dia de uma data
	 * @param m Mes de uma data
	 * @param y Ano de uma data
	 */
	Date(const unsigned int &d, const unsigned int &m, const unsigned int &y);

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
	 * @brief Membro funcao que permite obter uma data no formato DD/MM/AAAA
	 * @return Retorna string de uma data no formato DD/MM/AAAA
	 */
	std::string toStr() const;

	/**
	 * @brief Compara se uma data e anterior a outra
	 * @return True se for anterior, false se for posterior
	 */
	bool operator< (const Date &date2) const;

	/**
	 * @brief Compara se uma data e igual a outra
	 * @return True se forem iguais, false se nao forem
	 */
	bool operator== (const Date &date2) const;

	/**
	* @brief Função que altera o dia de uma data
	* @param days Novo dia da data
	*/
	void setDays(unsigned int days);

	/**
	* @brief Função que altera o mes de uma data
	* @param months Novo mes da data
	*/
	void setMonths(unsigned int months);

	/**
	* @brief Funcao que altera uma data
	* @param day 	Novo dia
	* @param month 	Novo mes
	* @param year 	Novo ano
	*/
	void setDate(unsigned int day, unsigned int month, unsigned int year);
};

#endif /* DATE_H_ */
