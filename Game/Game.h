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
	int id;							//identificador �nico
	string title;					//nome
	int price;						//pre�o de aquisi��o
	Date release;					//data de lan�amento
	Interval age_range;				//intervalo de idades
	vector<string> platform;		//plataformas dispon�veis
	char genre;						//g�nero
	string developer;				//empresa que o desenvolveu
	vector<int> price_history;		//historial de pre�os de aquisi��o
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
	int fixed_price;				 //pre�o fixo
public:

};

class Variable_Subsc : public Online
{
private:
	int price_hour;					 //pre�o vari�vel: custo do jogo por hora
public:

};

class Home : public Game
{
private:
	Date updates;					 //data das atualiza��es em que o utilizador fez download do respetivo t�tulo (1� cada)
public:

};
