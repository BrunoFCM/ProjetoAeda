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

void draw_header(std::string message);

void main_menu_interface();
void print_main_menu();
int prompt_main_menu();

void system_menu_interface();
void print_system_interface();
int prompt_system_interface();

Game * add_game_interface();

void add_user_interface();
Card add_card_interface();

void game_library_interface();
void game_library_interface(vector<Game*> vec);
void print_game_interface();
int prompt_game();

void user_library_interface(vector<User*> vec);
void print_user_interface();
int prompt_user();





