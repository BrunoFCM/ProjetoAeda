#ifndef DEVELOPER_H_
#define DEVELOPER_H_
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * Classe Developer que contem informacao sobre as empresas criadores de jogos de videos
 */
class Developer{
	std::string name;	//corresponde ao nome da empresa
	long unsigned nif;	//corresponde ao NIF da empresa
	std::string eMail;	//corresponde ao contacto da empresa (nesta caso, eMail)
	unsigned numGames; //corresponde ao numero de jogos criados por cada empresa

public:
	/**
	 * @brief Construtor da classe Developer
	 * @param name Nome da empresa
	 * @param nif NIF da empresa
	 * @param eMail EMail da empresa
	 */
	Developer(const std::string &name, const long int &nif, const std::string &eMail);

	/**
	 * @brief Construtor default da classe Developer
	 */
	Developer();

	/**
	 * @brief Funcao que retorna o nome da empresa
	 * @return Nome da empresa
	 */
	std::string getName() const;

	/**
	 * @brief Funcao que retorna o NIF da empresa
	 * @return NIF da empresa
	 */
	long unsigned getNif() const;

	/**
	 * @brief Funcao que retorna o eMail da empresa
	 * @return EMail da empresa
	 */
	std::string getEMail() const;

	/**
	* @brief Funcao que retorna o numero de jogos criados pela empresa
	* @return numGames Numero de jogos criados pela empresa
	*/
	unsigned getNumGames() const;

	/**
	 * @brief Funcao que incrementa o numero de jogos criados pela empresa
	 */
	void incrementNumGames();

	/**
	 * @brief Compara duas empresas pelo numero de jogos criados e se este for o mesmo, por ordem alfabetica
	 * @return True se tiver criado menos jogos, false se tiver criado mais jogos. Caso o numero de jogos seja igual, desempata por ordem alfabetica
	 */
	bool operator< (const Developer &dev2) const;

	/**
	* @brief Overload do operador == para duas empresas
	* @return True se um dos dados membro das empresas for igual ao da segunda empresa (exceto numGames)
	*/
	bool operator== (const Developer &dev2) const;

	/**
	 * @brief Imprime informacao relativamente a empresa
	 */
	void printDeveloper() const;

	/**
	* @brief Funcao que passa para uma ofstream a informacao de uma empresa
	* @param info Ofstream para onde e passada a informacao de uma empresa
	*/
	void giveInfoDeveloper(ofstream &info) const;
};


#endif /* DEVELOPER_H_ */
