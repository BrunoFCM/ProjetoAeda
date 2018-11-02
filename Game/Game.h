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
	int id;							//identificador único
	string title;					//nome
	int price;						//preço de aquisição
	Date release;					//data de lançamento
	Interval age_range;				//intervalo de idades
	vector<string> platform;		//plataformas disponíveis
	char genre;						//género
	string developer;				//empresa que o desenvolveu
	vector<int> price_history;		//historial de preços de aquisição
public:

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
