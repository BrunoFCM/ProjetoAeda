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
 * @brief
 * @param
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
 * @brief
 * @param
 */
void draw_header(std::string message);

/**
 * @brief
 */
void main_menu_interface();

/**
 * @brief
 */
void print_main_menu();

/**
 * @brief
 * @param
 */
int prompt_main_menu();

/**
 * @brief
 */
void system_menu_interface();

/**
 * @brief
 */
void print_system_interface();

/**
 * @brief
 * @return
 */
int prompt_system_interface();

/**
 * @brief
 * @return
 */
Game * add_game_interface();

/**
 * @brief
 * @return
 */
User * add_user_interface();

/**
 * @brief
 * @return
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
