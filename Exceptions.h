#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <string>
#include <iostream>

/*
 * Classe abstrata que contém todas as exceções tratadas no programa
 */
template <class C>
class Exception {
private:
	const C info;			//informação relativamente à instrução que gerou uma exceção

public:
	/**
	 * @brief Construtor da classe Exception
	 * @param info - informação relativamente à instrução que gerou uma exceção, do tipo de dados adequado
	 */
	Exception(const C &info): info(info) {}

	/**
	 * @brief Membro função que retorna a intrução que gerou uma exceção
	 * @return Retorna a instrução que gerou uma exceção
	 */
	const C getInf() const {return info;}

	/*
	 * @brief Membro função virtual puro que imprime informação relativamente a uma dada exceção
	 */
	virtual void printInf() const = 0;

	/*
	 * @brief Destrutor da classe Exception
	 */
	virtual ~Exception() {}
};



/*
 * Classe que gera exceções de datas inválidas
 */
template <class C>
class InvalidDate: public Exception<C> {
public:
	/*
	 * @brief Construtor da classe InvalidDate
	 * @param info - informação relativamente à instrução que gerou uma exceção, do tipo de dados adequado
	 */
	InvalidDate(const C &info): Exception<C>(info) {}

	/*
	 * @brief Membro função que imprime informação relativamente à exceção
	 */
	void printInf() const {
		std::cout << "Data inválida : '" << info << "'" << std::endl;
	}
};



/*
 * Classe que gera exceções de jogos já existentes
 */
class RepeatedGame: public Exception<unsigned int> {
public:
	/*
	 * @brief Construtor da classe RepeatedGame
	 * @param info - informação relativamente à instrução que gerou uma exceção, do tipo de dados adequado
	 */
	RepeatedGame(const unsigned int &info): Exception<unsigned int>(info) {}

	/**
	 * @brief Membro função que imprime informação relativamente à exceção
	 */
	void printInf() const {
		std::cout << "Jogo Repetido: 'ID " << info << "'" << std::endl;
	}
};


#endif /* EXCEPTIONS_H_ */