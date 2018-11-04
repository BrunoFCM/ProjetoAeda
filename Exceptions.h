#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <string>
#include <iostream>

/*
 * Classe abstrata que contém todas as exceções tratadas no programa
 */
class Exception {
private:
	std::string info;			//informação relativamente à instrução que gerou uma exceção

public:
	/**
	 * @brief Construtor da classe Exception
	 * @param info - informação relativamente à instrução que gerou uma exceção, do tipo de dados adequado
	 */
	Exception(const std::string &info): info(info) {}

	/**
	 * @brief Membro função que retorna a intrução que gerou uma exceção
	 * @return Retorna a instrução que gerou uma exceção
	 */
	std::string getInf() const {return info;}

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
class InvalidDate: public Exception {
public:
	/*
	 * @brief Construtor da classe InvalidDate
	 * @param info - informação relativamente à instrução que gerou uma exceção, do tipo de dados adequado
	 */
	InvalidDate(const std::string &info): Exception(info) {}

	/*
	 * @brief Membro função que imprime informação relativamente à exceção
	 */
	void printInf() const {
		std::cout << "Data inválida : '" << getInf() << "'" << std::endl;
	}
};



/*
 * Classe que gera exceções de jogos já existentes
 */
class RepeatedGame: public Exception{
public:
	/*
	 * @brief Construtor da classe RepeatedGame
	 * @param info - informação relativamente à instrução que gerou uma exceção, do tipo de dados adequado
	 */
	RepeatedGame(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro função que imprime informação relativamente à exceção
	 */
	void printInf() const {
		std::cout << "Jogo Repetido: 'ID " << getInf() << "'" << std::endl;
	}
};

/*
 * Classe que gera exceções de utilizadores já existentes (em termos de user ID)
 */
class RepeatedUser: public Exception {
public:
	/*
	 * @brief Construtor da classe RepeatedUser
	 * @param info - informação relativamente à instrução que gerou uma exceção, do tipo de dados adequado
	 */
	RepeatedUser(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro função que imprime informação relativamente à exceção
	 */
	void printInf() const {
		std::cout << "Utilizador repetido: 'ID " << getInf() << "'" << std::endl;
	}
};


#endif /* EXCEPTIONS_H_ */
