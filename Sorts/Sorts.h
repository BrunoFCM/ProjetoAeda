#pragma once

#include "Game.h"
#include "User.h"
#include "Exceptions.h"
#include <type_traits>

typedef bool (*GameComparer)(Game*,Game*);
typedef bool (*UserComparer)(User*,User*);

/**
 * @brief Funcao que verifica se o nome de user1 e menor que o nome de user2
 * @param user1 Primeiro utilizador
 * @param user2 Segundo utilizador
 * @return Retorna true se o nome de user1 e menor que o nome de user2, false caso contrario
 */
bool userNameAscend(User* user1,User* user2);

/**
 * @brief Funcao que verifica se o nome de user1 e maior que o nome de user2
 * @param user1 Primeiro utilizador
 * @param user2 Segundo utilizador
 * @return Retorna true se o nome de user1 e maior que o nome de user2, false caso contrario
 */
bool userNameDescend(User* user1,User* user2);

/**
 * @brief Funcao que verifica se a idade de user1 e menor que a idade de user2
 * @param user1 Primeiro utilizador
 * @param user2 Segundo utilizador
 * @return Retorna true se a idade de user1 e menor que a idade de user2, false caso contrario
 */
bool userAgeAscend(User* user1,User* user2);

/**
 * @brief Funcao que verifica se a idade de user1 e maior que a idade de user2
 * @param user1 Primeiro utilizador
 * @param user2 Segundo utilizador
 * @return Retorna true se a idade de user1 e maior que a idade de user2, false caso contrario
 */
bool userAgeDescend(User* user1,User* user2);


/**
 * @brief Funcao que verifica se o id de um jogo e menor que o id de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se o id de user1 e menor que o id de user2, false caso contrario
 */
bool gameIdAscend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se o id de um jogo e maior que o id de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se o id de user1 e maio que o id de user2, false caso contrario
 */
bool gameIdDescend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se o titulo de um jogo e menor que o titulo de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se o titulo de user1 e menor que o titulo de user2, false caso contrario
 */
bool gameTitleAscend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se o titulo de um jogo e maior que o titulo de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se o titulo de user1 e maior que o titulo de user2, false caso contrario
 */
bool gameTitleDescend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se o preco de um jogo e menor que o preco de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se o preco de user1 e menor que o preco de user2, false caso contrario
 */
bool gamePriceAscend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se o preco de um jogo e maior que o preco de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se o preco de user1 e maior que o preco de user2, false caso contrario
 */
bool gamePriceDescend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se o preco base de um jogo e menor que o preco base de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se o preco base de user1 e menor que o preco base de user2, false caso contrario
 */
bool gameBasePriceAscend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se o preco base de um jogo e maior que o preco base de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se o preco base de user1 e maior que o preco base de user2, false caso contrario
 */
bool gameBasePriceDescend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se a data de lancamento de um jogo e anterior a data de lancamento de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se a data de lancamento de user1 e anterior a data de lancamento de user2, false caso contrario
 */
bool gameReleaseAscend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se a data de lancamento de um jogo e posterior a data de lancamento de outro jogo
 * @param user1 Primeiro jogo
 * @param user2 Segundo jogo
 * @return Retorna true se a data de lancamento de user1 e posterior a data de lancamento de user2, false caso contrario
 */
bool gameReleaseDescend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se a idade minima apropriada de um jogo e menor que a de outro jogo, ou, no caso de igualdade, verifica a idade maxima
 * @param user1 Primeiro intervalo de idades
 * @param user2 Segundo intervalo de idades
 * @return Retorna true se user1 e menor que user2, false caso contrario
 */
bool gameAgeRangeAscend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se a idade minima apropriada de um jogo e maior que a de outro jogo, ou, no caso de igualdade, verifica a idade maxima
 * @param user1 Primeiro intervalo de idades
 * @param user2 Segundo intervalo de idades
 * @return Retorna true se user1 e maior que user2, false caso contrario
 */
bool gameAgeRangeDescend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se o nome do criador de um jogo e menor que o nome do criador de outro jogo
 * @param user1 Primeiro criador
 * @param user2 Segundo criador
 * @return Retorna true se o nome de user1 e menor que o nome de user2, false caso contrario
 */
bool gameDeveloperAscend(Game* user1,Game* user2);

/**
 * @brief Funcao que verifica se o nome do criador de um jogo e maior que o nome do criador de outro jogo
 * @param user1 Primeiro criador
 * @param user2 Segundo criador
 * @return Retorna true se o nome de user1 e maior que o nome de user2, false caso contrario
 */
bool gameDeveloperDescend(Game* user1,Game* user2);



template <class T>
/**
 * @brief Funcao que verifica se func e uma funcao que serve para comparar utilizadores
 * @param func Funcao que compara dois elementos
 * @return Retorna true se func serve para comparar utilizadores, false caso contrario
 */
bool isUserComparer(const T &func){
	return (std::is_same<T,UserComparer>::value);
}

template <class T>
/**
 * @brief Funcao que verifica se func e uma funcao que serve para comparar jogos
 * @param func Funcao que compara dois elementos
 * @return Retorna true se func serve para comparar jogos, false caso contrario
 */
bool isGameComparer(const T &func){
	return (std::is_same<T,GameComparer>::value);
}



template <class Comparable, class Comparator>
/**
 * @brief Algoritmo de ordenacao por insercao
 * @param func Funcao utilizada para comparar os elementos
 */
void insertionSort(vector<Comparable> &v, Comparator func)
{
    for (unsigned int p = 1; p < v.size(); p++)
    {
    	Comparable tmp = v[p];
    	int j;
    	for (j = p; j > 0 && func(tmp, v[j-1]); j--)
    		v[j] = v[j-1];
    	v[j] = tmp;
    }
}
