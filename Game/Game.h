#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Interval.h"
#include "User.h"
#include "PlaySession.h"

using namespace std;

class User;


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
	* @param title - nome do jogo
	* @param price - preco de aquisicao do jogo
	* @param release - data de lancamento do jogo
	* @param age_range - faixa etaria a que se tem de pertencer para se poder jogar 
	* @param platform - vetor de plataformas para as quais o jogo se encontra disponivel
	* @param genre - vetor de generos dos jogos
	* @param developer - empresa respnsavel pela criacao do jogo
	*/
	Game(string title, double price, Date release, Interval age_range, vector<string> platforms, vector<string> genres, string developer);

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
	* @return Retorna true se o id dos dois jogos for igual e false caso contrario
	*/
	bool operator==(Game &game);

	void changePrice(const double &newPrice);

	void discountPrice(const unsigned int &percentage);

	void changeBasePrice(const double &newPrice);

	void revertToPrice(const unsigned int &number);

	void addUser(User* user);
};


class PlaySession;

class Online : public Game
{
private:
	int play_time;					//tempo jogado
	PlaySession play_history;		//historial para cada jogo online que inclui: quando foi jogado, por quanto tempo e em que plataforma
public:
	Online(string title, double price, Date release, Interval age_range, vector<string> platforms, vector<string> genres, string developer, int play_time, PlaySession play_history);
	int getPlayTime() const;
	vector<PlaySession*> getPlayHistory() const;
	virtual double getPrice() const;
};

class Fixed_Subsc : public Online
{
private:
	int fixed_price;				 //preco fixo
public:

};

class Variable_Subsc : public Online
{
private:
	int price_hour;					 //preco variavel: custo do jogo por hora
public:

};

class Home : public Game
{
private:
	vector<Date> updates;					 //data das atualizacoes em que o utilizador fez download do respetivo titulo (1 euro cada)
public:
	Home(string title, double price, Date release, Interval age_range, vector<string> platforms, vector<string> genres, string developer);
	vector<Date> getUpdates() const;
};



