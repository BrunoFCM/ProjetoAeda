#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <string>
#include <iostream>

/*
 * Classe abstrata que contﾃｩm todas as exceﾃｧﾃｵes tratadas no programa
 */
class Exception {
private:
	std::string info;			//informaﾃｧﾃ｣o relativamente ﾃ� instruﾃｧﾃ｣o que gerou uma exceﾃｧﾃ｣o

public:
	/**
	 * @brief Construtor da classe Exception
	 * @param info - informaﾃｧﾃ｣o relativamente ﾃ� instruﾃｧﾃ｣o que gerou uma exceﾃｧﾃ｣o, do tipo de dados adequado
	 */
	Exception(const std::string &info): info(info) {}

	/**
	 * @brief Membro funﾃｧﾃ｣o que retorna a intruﾃｧﾃ｣o que gerou uma exceﾃｧﾃ｣o
	 * @return Retorna a instruﾃｧﾃ｣o que gerou uma exceﾃｧﾃ｣o
	 */
	std::string getInf() const {return info;}

	/*
	 * @brief Membro funﾃｧﾃ｣o virtual puro que imprime informaﾃｧﾃ｣o relativamente a uma dada exceﾃｧﾃ｣o
	 */
	virtual void printInf() const = 0;

	/*
	 * @brief Destrutor da classe Exception
	 */
	virtual ~Exception() {}
};



/*
 * Classe que gera exceﾃｧﾃｵes de datas invﾃ｡lidas
 */
class InvalidDate: public Exception {
public:
	/*
	 * @brief Construtor da classe InvalidDate
	 * @param info - informaﾃｧﾃ｣o relativamente ﾃ� instruﾃｧﾃ｣o que gerou uma exceﾃｧﾃ｣o, do tipo de dados adequado
	 */
	InvalidDate(const std::string &info): Exception(info) {}

	/*
	 * @brief Membro funﾃｧﾃ｣o que imprime informaﾃｧﾃ｣o relativamente ﾃ� exceﾃｧﾃ｣o
	 */
	void printInf() const {
		std::cout << "Data invﾃ｡lida : '" << getInf() << "'" << std::endl;
	}
};



/*
 * Classe que gera exceﾃｧﾃｵes de jogos jﾃ｡ existentes
 */
class RepeatedGame: public Exception{
public:
	/*
	 * @brief Construtor da classe RepeatedGame
	 * @param info - informaﾃｧﾃ｣o relativamente ﾃ� instruﾃｧﾃ｣o que gerou uma exceﾃｧﾃ｣o, do tipo de dados adequado
	 */
	RepeatedGame(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funﾃｧﾃ｣o que imprime informaﾃｧﾃ｣o relativamente ﾃ� exceﾃｧﾃ｣o
	 */
	void printInf() const {
		std::cout << "Jogo Repetido: 'ID " << getInf() << "'" << std::endl;
	}
};

/*
 * Classe que gera exceﾃｧﾃｵes de utilizadores jﾃ｡ existentes (em termos de user ID)
 */
class RepeatedUser: public Exception {
public:
	/*
	 * @brief Construtor da classe RepeatedUser
	 * @param info - informaﾃｧﾃ｣o relativamente ﾃ� instruﾃｧﾃ｣o que gerou uma exceﾃｧﾃ｣o, do tipo de dados adequado
	 */
	RepeatedUser(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funﾃｧﾃ｣o que imprime informaﾃｧﾃ｣o relativamente ﾃ� exceﾃｧﾃ｣o
	 */
	void printInf() const {
		std::cout << "Utilizador repetido: 'ID " << getInf() << "'" << std::endl;
	}
};

class InvalidComparer{
public:
	void printInf() const {
		std::cout << "Comparador Inválido" << std::endl;
	};
};

class InvalidRestrictor{
public:
	void printInf() const {
		std::cout << "Comparador Inválido" << std::endl;
	};
};
class InvalidArgument{
public:
	void printInf() const {
		std::cout << "Comparador Inválido" << std::endl;
	};
};


#endif /* EXCEPTIONS_H_ */
