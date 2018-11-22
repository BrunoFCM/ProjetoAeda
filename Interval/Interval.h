#ifndef INTERVAL_H_
#define INTERVAL_H_
#include <string>

/**
 *  Classe Interval que contem o intervalo de idades sugerido para um certo jogo
 */
class Interval {
private:
	unsigned int lower;				//limite inferior do intervalo de idades(inclusive)
	unsigned int upper;				//limite superior do intervalo de idades(inclusive)
public:
	/**
	 * @brief Construtor da classe Interval
	 * @param low Limite inferior do intervalo de idades(inclusive)
	 * @param up Limite superior do intervalor de idades(inclusive)
	 */
	Interval(const unsigned int &low, const unsigned int &up);

	/**
	 * @brief Membro funcao que retorna o limite inferior de um intervalo de idades
	 * @return Membro inferior de um intervalo de idades
	 */
	unsigned int getLower() const;

	/**
	 * @brief Membro funcao que retorna o limite superior de um intervalo de idades
	 * @return Intervalo superior de um intervalo de idades
	 */
	unsigned int getUpper() const;

	/**
	 * @brief Membro funcao que retorna uma string de um intervalo no formato 'lower-upper'
	 * @return Intervalo no formato string
	 */
	string toStr() const;

	/**
	 * @brief Membro funcao que avalia se uma pessoa de uma certa idade pode jogar o jogo
	 * @param value Idade da pessoa
	 * @return True se puder jogar, falso se nao puder
	 */
	bool contains(const unsigned int &value) const;

	/**
	 * @brief Operador < que avalia se um intervalo e menor do que outro
	 * @param inter2 Intervalo de comparacao
	 * @return True se for menor, falso se nao for
	 */
	bool operator<(const Interval &inter2) const;

	/**
	 * @brief Operador == que avalia se dois intervalos sao iguais
	 * @param inter2 Intervalo de comparacao
	 * @return True se forem iguais, false se nao forem
	 */
	bool operator==(const Interval &inter2) const;

	/**
	 * @brief Membro funcao que avalia se dois intervalos tem dados coincidentes
	 * @param inter2 Intervalo de comparacao
	 * @return True se tiverem dados coincidentes, false se nao tiverem
	 */
	bool coincide(const Interval &inter2) const;

};

#endif /* INTERVAL_H_ */
