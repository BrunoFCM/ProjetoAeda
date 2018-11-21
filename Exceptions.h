#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <string>
#include <iostream>

/*
 * Classe abstrata que cont�m todas as exce��es tratadas no programa
 */
class Exception {
private:
	std::string info;			//informa��o relativamente � instru��o que gerou uma exce��o

public:
	/**
	 * @brief Construtor default da classe Exception
	 */
	Exception() {}

	/**
	 * @brief Construtor da classe Exception
	 * @param info - informa��o relativamente � instru��o que gerou uma exce��o, do tipo de dados adequado
	 */
	Exception(const std::string &info): info(info) {}

	/**
	 * @brief Membro fun��o que retorna a intru��o que gerou uma exce��o
	 * @return Retorna a instru��o que gerou uma exce��o
	 */
	std::string getInf() const {return info;}

	/*
	 * @brief Membro fun��o virtual puro que imprime informa��o relativamente a uma dada exce��o
	 */
	virtual void printInf() const = 0;

	/*
	 * @brief Destrutor da classe Exception
	 */
	virtual ~Exception() {}
};



/*
 * Classe que gera exce��es de datas inv�lidas
 */
class InvalidDate: public Exception {
public:
	/*
	 * @brief Construtor da classe InvalidDate
	 * @param info - informa��o relativamente � instru��o que gerou uma exce��o, do tipo de dados adequado
	 */
	InvalidDate(const std::string &info): Exception(info) {}

	/*
	 * @brief Membro fun��o que imprime informa��o relativamente � exce��o
	 */
	void printInf() const {
		std::cout << "Data inv�lida : '" << getInf() << "'" << std::endl;
	}
};



/*
 * Classe que gera exce��es de jogos j� existentes
 */
class RepeatedGame: public Exception{
public:
	/*
	 * @brief Construtor da classe RepeatedGame
	 * @param info - informa��o relativamente � instru��o que gerou uma exce��o, do tipo de dados adequado
	 */
	RepeatedGame(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro fun��o que imprime informa��o relativamente � exce��o
	 */
	void printInf() const {
		std::cout << "Jogo Repetido: 'ID " << getInf() << "'" << std::endl;
	}
};

/*
 * Classe que gera exce��es de utilizadores j� existentes (em termos de user ID)
 */
class RepeatedUser: public Exception {
public:
	/*
	 * @brief Construtor da classe RepeatedUser
	 * @param info - informa��o relativamente � instru��o que gerou uma exce��o, do tipo de dados adequado
	 */
	RepeatedUser(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro fun��o que imprime informa��o relativamente � exce��o
	 */
	void printInf() const {
		std::cout << "Utilizador repetido: 'ID " << getInf() << "'" << std::endl;
	}
};


/*
 * Classe que gera exce��es de comparadores inv�lidos
 */
class InvalidComparer: public Exception{
public:
	/*
	 * @brief Construtor da classe InvalidComparer
	 */
	InvalidComparer() {}

	/**
	 * @brief Membro fun��o que imprime informa��o relativamente � exce��o
	 */
	void printInf() const {
		std::cout << "Comparador Inv�lido" << std::endl;
	};
};

class InvalidRestrictor: public Exception{
public:
	/*
	 * @brief Construtor da classe InvalidRestrictor
	 */
	InvalidRestrictor() {}

	/**
	 * @brief Membro fun��o que imprime informa��o relativamente � exce��o
	 */
	void printInf() const {
		std::cout << "Comparador Inv�lido" << std::endl;
	};
};
class InvalidArgument: public Exception{
public:
	/*
	 * @brief Construtor da classe InvalidArgument
	 */
	InvalidArgument() {}

	/**
	 * @brief Membro fun��o que imprime informa��o relativamente � exce��o
	 */
	void printInf() const {
		std::cout << "Comparador Inv�lido"<< std::endl;
	};
};


#endif /* EXCEPTIONS_H_ */

