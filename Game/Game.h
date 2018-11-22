#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Interval.h"
#include "User.h"
#include "PlaySession.h"

using namespace std;

class Date;
class User;
class Interval;

class Game
{
private:
	unsigned int id;						//identificador unico
	string title;							//nome
	double price;							//preco de aquisicao
	double base_price;
	Date release;							//data de lancamento
	Interval age_range;						//intervalo de idades
	vector<string> platform;				//plataformas disponiveis
	vector<string> genre;					//genero
	string developer;						//empresa que o desenvolveu
	vector<double> price_history;			//historial de precos de aquisicao
	vector<User*> users;				    //vetor de utilizadores
	static unsigned int id_seq;
public:

	/**
	 * @brief Construtor da classe Game
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 */
	Game(const string &title,const double &price,const Date &release,const Interval &age_range,const vector<string> &platforms,const vector<string> &genres,const string &developer);

	/**
	 * @brief Destrutor da classe Game
	 */
	~Game();

	/**
	* @brief Membro-funcao que retorna o identificador unico de um jogo
	* @return Retorna o identificador unico de um jogo
	*/
	unsigned int getId() const;

	/**
	* @brief Membro-funcao que retorna o titulo de um jogo
	* @return Retorna o titulo de um jogo
	*/
	string getTitle() const;

	/**
	* @brief Membro-funcao que retorna o preco de aquisicao de um jogo
	* @return Retorna o preco de aquisicao de um jogo
	*/
	double getPrice() const;

	/**
	* @brief Membro-funcao que retorna o preco de aquisicao base de um jogo
	* @return Retorna o preco de aquisicao base de um jogo
	*/
	double getBasePrice() const;

	/**
	* @brief Membro-funcao que retorna a data de lancamento de um jogo
	* @return Retorna a data de lancamento de um jogo
	*/
	Date getRelease() const;

	/**
	* @brief Membro-funcao que retorna a faixa etaria a que se tem de pertencer para se poder jogar
	* @return Retorna um intervalo de idades
	*/
	Interval getAge() const;

	/**
	* @brief Membro-funcao que retorna um vetor de plataformas para as quais o jogo se encontra disponivel
	* @return Retorna um vetor de plataformas
	*/
	vector<string> getPlatforms() const;

	/**
	* @brief Membro-funcao que retorna um vetor de strings correspondentes aos generos dos jogos
	* @return Retorna um vetor de strings correspondentes aos generos dos jogos
	*/
	vector<string> getGenre() const;

	/**
	* @brief Membro-funcao que retorna uma string correspondente ao nome da empresa que desenvolveu o jogo
	* @return Retorna o nome da empresa
	*/
	string getDeveloper() const;

	/**
	* @brief Membro-funcao que retorna o historial de precos de aquisicao do jogo
	* @return Retorna o historial de precos de aquisicao do jogo
	*/
	vector<double> getPriceHist() const;

	/**
	* @brief Overload do operador == para jogos
	* @param game Jogo com qual e comparado
	* @return Retorna true se o id dos dois jogos for igual e false caso contrario
	*/
	bool operator==(Game &game);

	/**
	* @brief Altera o preço atual do jogo
	* @param newPrice Novo preco do jogo
	*/
	void changePrice(const double &newPrice);

	/**
	* @brief Define um desconto para um jogo
	* @param percentage Desconto a definir
	*/
	void discountPrice(const unsigned int &percentage);

	/**
	* @brief Altera o preço base do jogo
	* @param newPrice Novo preco base do jogo
	*/
	void changeBasePrice(const double &newPrice);

	/**
	* @brief Altera o preço para o preco base
	*/
	void revertToPrice();

	/**
	* @brief Adiciona um utilizador a base de jogadores de jogo
	* @param user Utilizador a adicionar
	*/
	void addUser(User* user);


	/**
	 * @brief Membro puramente virutal que permite obter informacao sobre um determinado jogo. Encontra-se implementado nas classes derivadas Home e Online
	 */
	virtual void printInfoGame() const = 0;
};



class PlaySession;

/**
 * Classe Online derivada da classe Game
 */
class Online : public Game
{
private:
	int play_time;					//tempo jogado
	PlaySession play_history;		//historial para cada jogo online que inclui: quando foi jogado, por quanto tempo e em que plataforma
public:
	/**
	 * @brief Construtor da classe Online
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 */
	Online(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer);

	/**
	 *
	 */
	virtual ~Online() {};

	/**
	 * @brief Devolve o tempo total jogado
	 */
	int getPlayTime() const;

	/**
	 * @brief Devolve o valor 0
	 */
	virtual double getPrice() const;

	/**
	 * @brief Permite aceder ao conjunto de sessoes efetuadas no jogo
	 * @return Vetor apontador para o conjunto de objetos de classe PlaySession
	 */
	vector<PlaySession*> getPlayHistory() const;
};



/**
 * Classe FixedSubsc derivada da classe Online
 */
class FixedSubsc : public Online
{
private:
	int fixed_price;				 //preco fixo
public:

	/**
	 * @brief Construtor da classe FixedSubsc
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 * @param fixed_price Preco de subscricao fixa
	 */
	FixedSubsc(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const double &fixed_price);

	/**
	 * @brief Devolve o preco da subscricao fixa
	 * @return Preco da subscricao fixe
	 */
	double getPrice() const;

	/**
	 * @brief Imprime informacao relativamente ao jogo
	 */
	void printInfoGame() const;

};



/**
 * Classe VariableSubsc derivada da classe Online
 */
class VariableSubsc : public Online
{
private:
	int price_hour;					 //preco variavel: custo do jogo por hora
public:

	/**
	 * @brief Construtor da classe VariableSubsc
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 * @param price_hour Preco pago por cada hora jogada
	 */
	VariableSubsc(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const double &price_hour);

	/**
	 * @brief Devolve o preco pago atual, dependente do preco por hora e pelo tempo jogado
	 * @return Preco pago atual
	 */
	double getPrice() const;

	/**
	 * @brief Imprime informacao relativamente ao jogo
	 */
	void printInfoGame() const;

};





/**
 * Classe Home derivada da classe Game
 */
class Home : public Game
{
private:
	vector<Date> updates;					 //data das atualizacoes em que o utilizador fez download do respetivo titulo (1 euro cada)
public:
	/**
	 * @brief Construtor da classe Home
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 */
	Home(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer);

	/**
	 * @brief Devolve um vetor com todos os updates feitos ao jogo
	 * @return Vetor de datas de update
	 */
	vector<Date> getUpdates() const;

	/**
	 * @brief Acrescenta um update ao vetor de update
	 * @param date Data do update a acrescentar
	 */
	void addUpdate(Date date) const;

	/**
	 * @brief Imprime informacao relativamente ao jogo
	 */
	void printInfoGame() const;
};


#endif /* SRC_GAME_H_ */
