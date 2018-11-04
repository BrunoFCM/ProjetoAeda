#ifndef INTERVAL_H_
#define INTERVAL_H_

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
	 * @param low - limite inferior do intervalo de idades(inclusive)
	 * @param up - limite superior do intervalor de idades(inclusive)
	 */
	Interval(const unsigned int &low, const unsigned int &up);

	/**
	 * @brief Membro funcao que retorna o limite inferior de um intervalo de idades
	 * @return Retorna o membro inferior de um intervalo de idades
	 */
	unsigned int getLower() const;

	/**
	 * @brief Membro funcao que retorna o limite superior de um intervalo de idades
	 * @return Retorna o intervalo superior de um intervalo de idades
	 */
	unsigned int getUpper() const;

	/**
	 * @brief Membro funcao que avalia se uma pessoa de uma certa idade pode jogar o jogo
	 * @param age - idade da pessoa
	 * @return Retorna true se puder jogar, falso se nao puder
	 */
	bool contains(const unsigned int &value) const;
};

#endif /* INTERVAL_H_ */
