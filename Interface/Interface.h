#include <iostream>
#include <iomanip>

#include "Card.h"
#include "Date.h"
#include "Exceptions.h"
#include "Game.h"
#include "Interval.h"
#include "PlaySession.h"
#include "Restricts.h"
#include "Sorts.h"
#include "System.h"
#include "User.h"

#define HEADER_SIZE 80

/**
 * @brief Funcao que passa a informacao introduzida pelo utilizador para uma variavel, depois de verificar se e adequada
 * @param input Variavel que adota o valor do input dado pelo utilizador
 */
template<typename T>
void input_receiver(T &input){
	std::cout << "Input: ";
	std::cin >> input;
	while (std::cin.fail() || std::cin.eof())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input! Try again." << std::endl;
		std::cout << "Input: ";
		std::cin >> input;
	}

	std::cin.ignore(1000, '\n');
}

/**
 * @brief Funcao que imprime no ecra um cabecalho com um titulo
 * @param message Titulo do cabecalho
 */
void draw_header(std::string message);

/**
 * @brief Funcao que gere o menu principal e chama restantes menus
 */
void main_menu_interface();

/**
 * @brief Funcao que imprime no ecra o menu principal e suas opcoes
 */
void print_main_menu();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_main_menu();

/**
 * @brief Funcao que gere o menu de um sistema
 */
void system_menu_interface();

/**
 * @brief Funcao que imprime no ecra o menu de um sistema
 */
void print_system_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_system_interface();

/**
 * @brief Funcao que possibilita a adicao de um jogo a um sistema por parte do utilizador
 * @return Retorna o jogo adicionado ao sistema
 */
Game * add_game_interface();

/**
 * @brief Funcao que possibilita a adicao de um usuario a um sistema por parte do utilizador
 * @return Retorna o usuario adicionado ao sistema
 */
User * add_user_interface();

/**
 * @brief Funcao que possibilita a adicao de um cartao bancario a um sistema por parte do utilizador
 * @return Retorna o cartao adicionado ao sistema
 */
Card add_card_interface();

/**
 * @brief
 * @param
 */
void game_interface(Game *game);

/**
 * @brief
 * @param
 */
void print_game_interface(const bool &home);

/**
 * @brief
 * @return
 */
int prompt_game_interface();

/**
 * @brief
 * @param
 */
void user_interface(User *user);

/**
 * @brief
 */
void print_user_interface();

/**
 * @brief
 * @return
 */
int prompt_user_interface();

/**
 * @brief
 * @param
 */
void card_interface(Card &card);

/**
 * @brief
 */
void print_card_interface();

/**
 * @brief
 * @return
 */
int prompt_card_interface();

/**
 * @brief
 */
void save_interface();

/**
 * @brief
 */
void sort_game_interface();

/**
 * @brief
 */
void print_sort_game_interface();

/**
 * @brief
 * @return
 */
int prompt_sort_game_interface();

/**
 * @brief
 */
void sort_user_interface();

/**
 * @brief
 */
void print_sort_user_interface();

/**
 * @brief
 * @return
 */
int prompt_sort_user_interface();

/**
 * @brief
 * @param
 */
void sort_game_vector_interface(vector<Game *> &vec);

/**
 * @brief
 * @param
 */
void sort_user_vector_interface(vector<Game *> &vec);
