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
			//add_user_interface();
			break;
		case 3:
			//sorts
			break;
		case 4:
			//sorts
			break;
		case 5:
			//search
			break;
		case 6:
			//search
			break;
		case 7:
			//vector
			break;
		case 8:
			//vector
			break;
		case 0:
			//hol' up
			break;
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
	
Game* add_game_interface(){
	std::cout << "Adding a game to the system library\nPlease input the following parameters:\n";

	std::cout << endl << "Game type (Home, Variable Subscription, Fixed Subscription): ";
	string type;
	getline(cin,type);
	while(type != "Home" && type != "Variable Subscription" && type != "Fixed Subscription"){
		std::cout << "Please insert a correct type" << std::endl;
		getline(cin,type);
	}

	string aux;

	std::cout << endl << "Title: ";
	string title;
	getline(cin,title);

	std::cout << endl << "Price: ";
	double price;
	input_receiver(price);
	price = (double)((int)(price*100))/100;

	Date release(1,1,1901);
	while(true){
		try{
			std::cout << endl << "Release date (in the DD/MM/YYYY format): ";
			getline(cin,aux);
			std::cout << aux;
			release = Date(aux);
			break;
		}
		catch(InvalidDate &e){
			e.printInf();
		}
	}

	int age_min,age_hi;
	std::cout << endl << "Minimum age: ";
	input_receiver(age_min);
	std::cout << "Maximum recommended age: ";
	input_receiver(age_hi);
	while(age_min > age_hi){
		std::cout << endl << "Invalid age interval, please input your values again" << std::endl;
		std::cout << "Minimum age: ";
		input_receiver(age_min);
		std::cout << "Maximum recommended age: ";
		input_receiver(age_hi);
	}
	Interval range(age_min,age_hi);

	vector<string> platforms;
	std::cout << endl << "List of platforms (one input per platform, input '.' to end, at least one platform is necessary):\n";
	while(aux[0] != '.' || (!platforms.size())){
		getline(cin,aux);
		if (aux[0] != '.'){
			platforms.push_back(aux);
		}
	}

	vector<string> genres;
	std::cout << endl << "List of genres (one input per genre, input '.' to end, at least one genre is necessary):\n";
	while(aux[0] != '.' || (!genres.size())){
		getline(cin,aux);
		if (aux[0] != '.'){
			genres.push_back(aux);
		}
	}

	std::cout << endl << "Developer: ";
	string developer;
	getline(cin,developer);

	if(type == "Home")
		return (new Home(title, price, release, range, platforms, genres, developer));
	else if(type == "Variable Subscription"){
		std::cout << endl << "Subscription (by the hour): ";
		double sub;
		input_receiver(sub);
		sub = (double)((int)(sub*100))/100;
		return (new VariableSubsc(title, price, release, range, platforms, genres, developer,sub));
	}
	else{
		std::cout << endl << "Subscription: ";
		double sub;
		input_receiver(sub);
		sub = (double)((int)(sub*100))/100;
		return (new FixedSubsc(title, price, release, range, platforms, genres, developer,sub));
	}

	return NULL;

}
	

	
	
