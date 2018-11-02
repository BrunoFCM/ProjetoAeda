#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Interval.h"
#include "User.h"
#include "Game_history_onl.h"

using namespace std;

class Game
{
private:
	unsigned int id;						//identificador único
	string title;							//nome
	unsigned int price;						//preco de aquisicao
	Date release;							//data de lancamento
	Interval age_range;						//intervalo de idades
	vector<string> platform;				//plataformas disponiveis
	char genre;								//genero
	string developer;						//empresa que o desenvolveu
	vector<unsigned int> price_history;		//historial de precos de aquisicao
public:

	/**
	* @brief Construtor da classe Game
	* @param title - nome do jogo
	* @param price - preco de aquisicao do jogo
	* @param release - data de lancamento do jogo
	* @param age_range - faixa etaria a que se tem de pertencer para se poder jogar 
	* @param platform - vetor de plataformas para as quais o jogo se encontra disponivel
	* @param genre - genero (F ou M) ao qual o jogo se destina (preferencialmente)
	* @param developer - empresa respnsavel pela criacao do jogo
	*/
	Game(string title, unsigned int price, Date release, Interval age_range, vector<string> platform, char genre, string developer);

	/**
	* @brief Membro-funcao que retorna o identificador único de um jogo
	* @return Retorna o identificador único de um jogo
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
	unsigned int getPrice() const;

	/**
	* @brief Membro-funcao que retorna a data de lancamento de um jogo
	* @return Retorna a data de lancamento de um jogo
	*/
	Data getRelease() const;

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
	* @brief Membro-funcao que retorna um caracter correspondente ao genero a que o jogo se destina
	* @return Retorna um caracter corrspondente ao genero
	*/
	char getGenre() const;

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

};

class Online : public Game
{
private:
	vector<User*> users;			//conjunto de utilizadores
	int play_time;					//tempo jogado
	Game_history_onl play_history;	//historial para cada jogo online que inclui: quando foi jogado, por quanto tempo e em que plataforma
public:

};

class Fixed_Subsc : public Online
{
private:
	int fixed_price;				 //preço fixo
public:

};

class Variable_Subsc : public Online
{
private:
	int price_hour;					 //preço variável: custo do jogo por hora
public:

};

class Home : public Game
{
private:
	Date updates;					 //data das atualizações em que o utilizador fez download do respetivo título (1€ cada)
public:

};
