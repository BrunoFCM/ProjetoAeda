#pragma once

#include "Game.h"
#include "User.h"
#include "Interval.h"
#include "Date.h"
#include "Exceptions.h"
#include <string>
#include <type_traits>

#define USER_RESTRICTOR true
#define GAME_RESTRICTOR false

/**
 * @brief Funcao que verifica se o id de um jogo pertence a um intervalo de ids passado como argumento
 * @param g1 Jogo cujo id e analisado
 * @param inter Intervalo de ids
 * @return Retorna true se o id estiver contido no intervalo, false caso contrario
 */
bool gameIdInterval(Game* g1, const Interval &inter);

/**
 * @brief Funcao que verifica se o preco de um jogo esta a baixo de um preco limite
 * @param g1 Jogo cujo preco e analisado
 * @param max Preco limite
 * @return Retorna true se o preco estiver a baixo do preco limite, false caso contrario
 */
bool gamePriceMax(Game* g1, const double &max);

/**
 * @brief Funcao que verifica a data de lancamento de um jogo
 * @param g1 Jogo cuja data de lancamento e analisada
 * @param date Data de lancamento utilizada para a comparacao equalitaria
 * @return Retorna true se a data de g1 e igual a date, false caso contrario
 */
bool gameRelease(Game* g1, const Date &date);

/**
 * @brief Funcao que verifica se a faixa etaria do jogo tem valores coincidentes com o intervalo inter
 * @param g1 Jogo cuja faixa etaria e analisada
 * @param inter Intervalo de idades
 * @return Retorna true se tiverem alguns valores coincidentes, false caso contrario
 */
bool gameAgeRange(Game* g1, const Interval &inter);

/**
 * @brief
 * @param g1 -
 * @param platform -
 * @return
 */
bool gamePlatform(Game* g1, const std::string &platform);

/**
 * @brief Funcao que verifica se um jogo pertence a detreminado genero
 * @param g1 Jogo cujos generos serao analisados
 * @param genre Genero que e suposto verificar
 * @return Retorna true se o jogo pertencer ao genero, false caso contrario
 */
bool gameGenre(Game* g1, const std::string &genre);

/**
 * @brief Funcao que verifica o criador de um jogo
 * @param g1 Jogo cujo criador e analisado
 * @param developer Nome do criador do jogo para a comparacao equalitaria
 * @return Retorna true se o criador de g1 e igual a developer, false caso contrario
 */
bool gameDeveloper(Game* g1, const std::string &developer);


/**
 * @brief Funcao que verifica se a idade de um utilizador esta contida numa faixa etaria
 * @param u1 Utilizador cuja faixa etaria e analisada
 * @param inter Intervalo de idades
 * @return Retorna true se a idade de u1 esta contida numa faixa etaria, false caso contrario
 */
bool userAgeInterval(User* u1, const Interval &inter);

/**
 * @brief Funcao que verifica se o tamanho de uma biblioteca de jogos de um utilizador esta contido no intervalo inter
 * @param u1 Utilizador cujo tamanho da biblioteca e analisado
 * @param inter Intervalo de tamanhos
 * @return Retorna true se o tamanho da biblioteca de jogos de u1 esta contido no intervalo inter, false caso contrario
 */
bool userLibrarySize(User* u1, const Interval &inter);



template <class Restrictor>
/**
 * @brief Funcao que verifica se o restritor func e de jogos ou de utilizadores
 * @param func Restritor
 * @param is_user_restrictor Valor booleano que transmite a diferenciacao entre restritores
 * @return Retorna is_user_restrictor se o restritor e de users, !is_user_restrictor se e de games e false caso contrario
 */
bool properRestrictor(Restrictor func, const bool &is_user_restrictor){
	switch(func){
	case &gameIdInterval:
	case &gameAgeRange:
	case &gamePlatform:
	case &gameGenre:
	case &gameDeveloper:
	case &gamePriceMax:
	case &gameRelease:
		return !is_user_restrictor;
	case &userAgeInterval:
	case &userLibrarySize:
		return is_user_restrictor;
	default:
		return false;
	}
}


template <class Restrictor, class Argument>
/**
 * @brief Funcao que verifica se o argumento (arg) e do tipo necessario ao restritor (func)
 * @param func Restritor
 * @param arg Argumento
 * @return True se arg e do tipo necessario a func, false caso contrario
 */
bool properArgument(Restrictor func, Argument arg){
	switch(func){
	case &gameIdInterval:
	case &gameAgeRange:
	case &userAgeInterval:
	case &userLibrarySize:
		return (std::is_same<Argument,Interval>::value);
	case &gamePriceMax:
		return (std::is_same<Argument,double>::value);
	case &gameRelease:
		return (std::is_same<Argument,Date>::value);
	case &gamePlatform:
	case &gameGenre:
	case &gameDeveloper:
		return (std::is_same<Argument,std::string>::value);
	default:
		return false;
	}
}



template <class Comparable, class Restrictor, class Argument>
/**
 * @brief Funcao que retorna um vetor mais curto e restrito, extraido de um vetor maior
 * @param v Vetor maior de elementos comparaveis
 * @param func Funcao que executa a restricao
 * @param arg Argumnto da funcao func
 * @return Retorna um vetor mais curto e restrito
 */
vector<Comparable> restrictedVector(const vector<Comparable> &v, Restrictor func, Argument arg)
{
	vector <Comparable> out;
    for (unsigned int i = 0; i < v.size(); i++)
    	if (func(v[i], arg))
    		out.push_back(v[i]);
    return out;
}
