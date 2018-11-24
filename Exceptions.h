#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <string>
#include <iostream>

/*
 * Classe abstrata que contem todas as excecoes tratadas no programa
 */
class Exception {
private:
	std::string info;			//informaco relativamente a instrucao que gerou uma excecao

public:
	/**
	 * @brief Construtor default da classe Exception
	 */
	Exception() {}

	/**
	 * @brief Construtor da classe Exception
	 * @param info Informacao relativamente a instrucao que gerou uma excecao, do tipo de dados adequado
	 */
	Exception(const std::string &info): info(info) {}

	/**
	 * @brief Membro funcao que retorna a intrucao que gerou uma excecao
	 * @return Retorna a instrucao que gerou uma excecao
	 */
	std::string getInf() const {return info;}

	/*
	 * @brief Membro funcao virtual puro que imprime informacao relativamente a uma dada excecao
	 */
	virtual void printInf() const = 0;

	/*
	 * @brief Destrutor da classe Exception
	 */
	virtual ~Exception() {}
};


/*
 * Classe que gera excecoes de datas invalidas
 */
class InvalidDate: public Exception {
public:
	/**
	 * @brief Construtor da classe InvalidDate
	 * @param info Informacao relativamente a instrucao que gerou uma excecao, do tipo de dados adequado
	 */
	InvalidDate(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Invalid Date: '" << getInf() << "'" << std::endl;
	}
};


/*
 * Classe que gera excecoes de jogos ja existentes
 */
class RepeatedGame: public Exception{
public:
	/**
	 * @brief Construtor da classe RepeatedGame
	 * @param info Informacao relativamente a instrucao que gerou uma excecao, do tipo de dados adequado
	 */
	RepeatedGame(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Repeated game: 'ID " << getInf() << "'" << std::endl;
	}
};

/**
 * Classe que gera excecoes de cartoes ja existentes
 */
class RepeatedCard: public Exception {
	/**
	 * @brief Construtor da classe RepeatedCard
	 */
public:
	RepeatedCard(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Repeated card: '" << getInf() << "'" << std::endl;
	}
};

/**
 * Classe que gera excecoes de utilizadores ja existentes (em termos de user ID)
 */
class RepeatedUser: public Exception {
public:
	/**
	 * @brief Construtor da classe RepeatedUser
	 * @param info Informacao relativamente a instrucao que gerou uma excecao, do tipo de dados adequado
	 */
	RepeatedUser(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Repeated user: 'ID " << getInf() << "'" << std::endl;
	}
};


/**
 * Classe que gera excecoes de jogos inexistentes
 */
class NonExistingGame: public Exception{
public:
	/**
	 * @brief Construtor da classe NonExistantGame
	 * @param info Informacao relativamente a instrucao que gerou uma excecao, do tipo de dados adequado
	 */
	NonExistingGame(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Non-existing game: '" << getInf() << "'" << std::endl;
	}
};


/**
 * Classe que gera excecoes de utilizadores inexistentes
 */
class NonExistingUser: public Exception {
public:
	/**
	 * @brief Construtor da classe NonExistantGame
	 * @param info - informacao relativamente a instrucao que gerou uma excecao, do tipo de dados adequado
	 */
	NonExistingUser(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Non-existing user: 'ID " << getInf() << "'" << std::endl;
	}
};


/**
 * Classe que gera excecoes de comparadores invalidos
 */
class InvalidComparer: public Exception{
public:
	/**
	 * @brief Construtor da classe InvalidComparer
	 */
	InvalidComparer() {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Invalid comparer" << std::endl;
	}
};


/**
 * Classe que gera excecoes de restritores invalidos
 */
class InvalidRestrictor: public Exception{
public:
	/**
	 * @brief Construtor da classe InvalidRestrictor
	 */
	InvalidRestrictor() {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Invalid restrictor" << std::endl;
	}
};


/**
 * Classe que gera excecoes de argumentos invalidos
 */
class InvalidArgument: public Exception{
public:
	/**
	 * @brief Construtor da classe InvalidArgument
	 */
	InvalidArgument() {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Invalid argument"<< std::endl;
	}
};

/**
 * Classe que gera excecoes de idades invalidas
 */
class UserTooYoung: public Exception {
public:
	/**
	 * @brief Construtor da classe UserTooYoung
	 */
	UserTooYoung(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "User is too young, must be at least " << getInf() << " years old" << std::endl;
	}
};

/**
 * Classe que gera excecoes de cartoes invalidos
 */
class InvalidCard: public Exception {
public:
	/**
	 * @brief Construtor da classe InvalidCard
	 */
	InvalidCard() {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "Card is not valid" << std::endl;
	}
};

class GameNotOwned: public Exception {
public:
	/**
	 * @brief Construtor da classe GameNotOwned
	 */
	GameNotOwned(const std::string &info): Exception(info) {}

	/**
	 * @brief Membro funcao que imprime informacao relativamente a excecao
	 */
	void printInf() const {
		std::cout << "The user does not own this game: " << getInf() << std::endl;
	}
};

#endif /* EXCEPTIONS_H_ */
