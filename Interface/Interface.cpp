#include <iostream>
#include <iomanip>
#include <vector>

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
#include "Interface.h"

void draw_header(std::string message){
	for (unsigned int i=0 ; i<HEADER_SIZE ; i++) { std::cout << '*'; }
	std::cout << std::endl;
	for (unsigned int i=0 ; i<HEADER_SIZE ; i++) { std::cout << '*'; }
	std::cout << std::endl << "**";
	for (unsigned int i=0 ; i<HEADER_SIZE - 4 ; i++) { std::cout << ' '; }
	std::cout << "**" << std::endl << "**";
	for (unsigned int i=0 ; i<(HEADER_SIZE-message.size())/2 - 2 ; i++) { std::cout << ' '; }
	std::cout << message;
	for (unsigned int i=0 ; i<(HEADER_SIZE-message.size())/2 - 2 ; i++) { std::cout << ' '; }
	std::cout << "**" << std::endl << "**";
	for (unsigned int i=0 ; i<HEADER_SIZE - 4 ; i++) { std::cout << ' '; }
	std::cout << "**" << std::endl;
	for (unsigned int i=0 ; i<HEADER_SIZE ; i++) { std::cout << '*'; }
	std::cout << std::endl;
	for (unsigned int i=0 ; i<HEADER_SIZE ; i++) { std::cout << '*'; }
	std::cout << std::endl << std::endl;
}

void main_menu_interface(){

	draw_header("GAME LIBRARY");

	while(true){
		print_main_menu();
		switch(prompt_main_menu()){
		case 1:
			//loader
		case 2:
			system_menu_interface();
			break;
		case 3:
			std::cout << "\n\nExiting...\n\n";
			return;
		}
	}
}

void print_main_menu(){
	
	std::cout << "Would you like to: " << std::endl << std::endl;
	std::cout << "\t1: Start a new game library system" << std::endl;
	std::cout << "\t2: Load a previously made system from a file" << std::endl;
	std::cout << "\t3: Exit the program" << std::endl << std::endl;
}

int prompt_main_menu(){
	int input = 0;
	input_receiver(input);
	while(input != 1 && input != 2 && input != 3){
		std::cout << "Please insert an integer between 1 and 3" << std::endl;
		input_receiver(input);
	}
	return input;
}

void system_menu_interface(){

	draw_header("SYSTEM");

	while(true){
		print_system_interface();
		switch(prompt_system_interface()){
		case 1:
			add_game_interface();
			break;
		case 2:
			add_user_interface();
			break;
		case 3:
			//sorts
		case 4:
			//sorts
		case 5:
			//search
		case 6:
			//search
		case 7:
			//vector
		case 8:
			//vector
		case 0:
			//hol' up
		}
	}
}

void print_system_interface(){

	std::cout << "Would you like to: " << std::endl << std::endl;
	std::cout << "\t1: Add a new game to the system" << std::endl;
	std::cout << "\t2: Add a new user to the system" << std::endl;
	std::cout << "\t3: Sort the game library" << std::endl;
	std::cout << "\t4: Sort the user library" << std::endl;
	std::cout << "\t5: Search for a game (direct)" << std::endl;
	std::cout << "\t6: Search for a user (direct)" << std::endl;
	std::cout << "\t7: Search for a game (tag search)" << std::endl;
	std::cout << "\t8: Search for a user (tag search)" << std::endl;
	std::cout << "\t0: Leave the system editor" << std::endl << std::endl;
}

int prompt_system_interface(){
	int input = -1;
	input_receiver(input);
	while(input < 0 || input > 8){
		std::cout << "Please insert an integer between 0 and 8" << std::endl;
		input_receiver(input);
	}
	return input;
}
	
	

	
	
