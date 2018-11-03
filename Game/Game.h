#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Interval.h"
#include "User.h"
#include "PlaySession.h"

using namespace std;

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
	static unsigned int id_seq = 0;
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
	Game(string title, double price, Date release, Interval age_range, vector<string> platform, vector<string> genre, string developer);

	/**
	* @brief Membro-funcao que retorna o identificador Ãºnico de um jogo
	* @return Retorna o identificador Ãºnico de um jogo
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
	vector<unsigned int> getPriceHist() const;

	/**
	* @brief Overload do operador == para jogos
	* @return Retorna true se o id dos dois jogos for igual e false caso contrario
	*/
	bool operator==(Game &game);
};

class Online : public Game
{
private:
	vector<User*> users;			//conjunto de utilizadores
	int play_time;					//tempo jogado
	PlaySession play_history;		//historial para cada jogo online que inclui: quando foi jogado, por quanto tempo e em que plataforma
public:

};

class Fixed_Subsc : public Online
{
private:
	int fixed_price;				 //preÃ§o fixo
public:

};

class Variable_Subsc : public Online
{
private:
	int price_hour;					 //preÃ§o variÃ¡vel: custo do jogo por hora
public:

};

class Home : public Game
{
private:
	Date updates;					 //data das atualizaÃ§Ãµes em que o utilizador fez download do respetivo tÃ­tulo (1â‚¬ cada)
public:

};




