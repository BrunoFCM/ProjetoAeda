#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

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

System * lsystem = NULL;

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
			lsystem = new System();
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
			game_interface(add_game_interface());
			break;
		case 2:
			user_interface(add_user_interface());
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
			save_interface();
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

	std::cout << endl << "Title\nInput: ";
	string title;
	getline(cin,title);

	std::cout << endl << "Price\n";
	double price;
	input_receiver(price);
	price = (double)((int)(price*100))/100;

	Date release(1,1,1901);
	while(true){
		try{
			std::cout << endl << "Release date (in the DD/MM/YYYY format)\nInput: ";
			getline(cin,aux);
			release = Date(aux);
			break;
		}
		catch(InvalidDate &e){
			e.printInf();
		}
	}

	int age_min,age_hi;
	std::cout << endl << "Minimum age\n";
	input_receiver(age_min);
	std::cout << "Maximum recommended age\n";
	input_receiver(age_hi);
	while(age_min > age_hi){
		std::cout << endl << "Invalid age interval, please input your values again" << std::endl;
		std::cout << "Minimum age\n";
		input_receiver(age_min);
		std::cout << "Maximum recommended age\n";
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

	std::cout << endl << "Developer\nInput: ";
	string developer;
	getline(cin,developer);

	if(type == "Home"){
		Home *game = new Home(title, price, release, range, platforms, genres, developer);
		lsystem->addGame(game);
		return (game);
	}
	else if(type == "Variable Subscription"){
		std::cout << endl << "Subscription (by the hour)\nInput: ";
		double sub;
		input_receiver(sub);
		sub = (double)((int)(sub*100))/100;
		VariableSubsc * game = new VariableSubsc(title, price, release, range, platforms, genres, developer,sub);
		lsystem->addGame(game);
		return (game);
	}
	else{
		std::cout << endl << "Subscription\nInput: ";
		double sub;
		input_receiver(sub);
		sub = (double)((int)(sub*100))/100;
		FixedSubsc * game = new FixedSubsc(title, price, release, range, platforms, genres, developer,sub);
		lsystem->addGame(game);
		return (game);
	}

	return NULL;

}
	
User* add_user_interface(){
	std::cout << "Adding a user to the system\nPlease input the following parameters:\n";

	std::cout << endl << "Name\nInput: ";
	string name;
	getline(cin,name);

	std::cout << endl << "E-mail\n";
	string email;
	input_receiver(email);

	std::cout << endl << "Age\n";
	unsigned int age;
	input_receiver(age);

	std::cout << endl << "Address\nInput: ";
	string address;
	getline(cin,address);

	User * user = new User(name,email,age,address);
	lsystem->addUser(user);
	return (user);

}

void game_interface(Game *game){
	draw_header("GAME");

	game->printInfoGame();

		while(true){
			print_game_interface(game->isHomeTitle());
			switch(prompt_game_interface()){
			case 1:
				game->printInfoGame();
				break;
			case 2:{
				vector<double> prc_his(game->getPriceHist());
				std::cout << "\n\nInsert the number of prices to see (0 shows every price)";
				unsigned int lim_prc;
				input_receiver(lim_prc);
				if (lim_prc == 0 || lim_prc > prc_his.size())
					lim_prc = prc_his.size();
				std::cout << endl << endl;
				for (unsigned int i = 0; i < lim_prc; ++i){
					std::cout << setprecision(2) << prc_his[i] << endl;
				}
				std::cout << endl << endl;
				break;
			}
			case 3:{
				std::cout << "\n\nInsert a value (in %) of the discount\n";
				unsigned int input_dis;
				input_receiver(input_dis);
				while((input_dis == 0) || (input_dis >= 100)){
					std::cout << "\nInsert a positive non-zero value below 100\n";
					input_receiver(input_dis);
				}
				game->discountPrice(input_dis);
				break;
			}
			case 4:{
				double input_base;
				std::cout << "\n\nInsert the new value for the base price\n";
				input_receiver(input_base);
				while(input_base <= 0){
					std::cout << "\nInsert a positive non-zero value for the base price\n";
					input_receiver(input_base);
				}
				input_base = (double)((int)(input_base*100))/100;
				game->changeBasePrice(input_base);
				break;
			}
			case 5:{
				game->revertToPrice();
				break;
			}
			case 6:{
				if (game->isHomeTitle()){
					std::string aux;
					Date update(1,1,1901);
					while(true){
						try{
							std::cout << endl << "\n\nUpdate date (in the DD/MM/YYYY format)\nInput: ";
							getline(cin,aux);
							update = Date(aux);
							break;
						}
						catch(InvalidDate &e){
							e.printInf();
						}
					}
					game->addUpdate(update);
				}
				else {
					vector<PlaySession*> play_his(game->getPlayHistory());
					std::cout << "\n\nInsert the number of sessions to see (0 shows every session)";
					unsigned int lim_ssn;
					input_receiver(lim_ssn);
					if (lim_ssn == 0 || lim_ssn > play_his.size())
						lim_ssn = play_his.size();
					std::cout << endl << endl;
					for (unsigned int i = 0; i < lim_ssn; ++i){
						play_his[i]->printInfoSession();
						std::cout << endl;
					}
					std::cout << endl << endl;
				}
				break;
			}
			case 0:
				return;
			}
		}
}

void print_game_interface(const bool &home){
	std::cout << "Would you like to: " << std::endl << std::endl;
	std::cout << "\t1: See game info" << std::endl;
	std::cout << "\t2: See price history" << std::endl;
	std::cout << "\t3: Make a discount" << std::endl;
	std::cout << "\t4: Change the base price" << std::endl;
	std::cout << "\t5: Revert price (nullify discounts)" << std::endl;
	if (home) std::cout << "\t6: Add an update" << std::endl;
	else std::cout << "\t6: See play history" << std::endl;
	std::cout << "\t0: Leave the game editor" << std::endl << std::endl;
}

int prompt_game_interface(){
	int input = -1;
	input_receiver(input);
	while(input < 0 || input > 6){
		std::cout << "Please insert an integer between 0 and 6" << std::endl;
		input_receiver(input);
	}
	return input;
}


void user_interface(User *user){
	draw_header("USER");

	user->printInfoUser();

	while(true){
		print_user_interface();
		switch(prompt_user_interface()){
		case 1:{
			user->printInfoUser();
			break;
		}
		case 2:{
			string card_number;
			std::cout << "\n\nInsert the card's identification number\n";
			input_receiver(card_number);
			Card card(card_number);

			if(card.getValidity()){
				std::cout << "\nInsert the card's balance\n";
				double balance;
				input_receiver(balance);
				while(balance < 0){
					std::cout << "\nInsert a non-negative value\n";
					input_receiver(balance);
				}
				balance = (double)((int)(balance*100))/100;
				card.setBalance(balance);
			}
			else
				std::cout << "Warning: the card number is not valid (you can change the number afterwards)" << endl << endl;

			try{
				user->addCard(card);
			}
			catch(RepeatedCard &rc){
				std::cout << "\nThis card has already been added\n";
			}

			break;
		}
		case 3:{
			std::cout << "\n\nInsert the number of cards to see (0 shows every card)";
			unsigned int lim_crd;
			input_receiver(lim_crd);
			user->printCardsUser(lim_crd);
			std::cout << "\n\nWould you like to edit a card? (if yes, input the index of the card, otherwise input 0)";
			unsigned int card_ind;
			input_receiver(card_ind);
			while(card_ind >= user->getCards().size()){
				std::cout << "\nInvalid Index\n";
				input_receiver(card_ind);
			}
			card_interface(user->getCardRef(card_ind));
			break;
		}
		case 4:{
			if(user->getLibrary().size() == 0){
				std::cout << std::endl << std::endl << "Warning: this user has no games" << std::endl << std::endl;
				break;
			}

			std::cout << endl << "Input the title of the game\nInput: ";
			string title;
			getline(cin,title);

			Game * game;

			while(true){
				try{
					game = lsystem->searchGame(title);
					break;
				}
				catch(NonExistingGame &e){
					e.printInf();
					std::cout << endl << "Input the title of the game\nInput: ";
					string title;
					getline(cin,title);
				}
			}

			vector<string> platforms(game->getPlatforms());
			std::cout << endl << "Input the platform of the game\nInput: ";
			string platform = "";
			while (true){
				getline(cin,platform);
				for(unsigned int i = 0; i < platforms.size(); ++i){
					if (platforms[i] == platform)
						break;
					if (i == platforms.size() - 1)
						platform = "";
				}
				if (platform == "")
					std::cout << "\nThe game cannot be played in this platform\nInput again: " ;
				else
					break;
			}

			std::string aux;
			Date update(1,1,1901);
			while(true){
				try{
					std::cout << "\n\nSession date (in the DD/MM/YYYY format)\nInput: ";
					getline(cin,aux);
					update = Date(aux);
					break;
				}
				catch(InvalidDate &e_date){
					e_date.printInf();
				}
			}
			std::cout << "\n\nInsert the session's duration (in hours)\n";
			unsigned int hours;
			input_receiver(hours);

			PlaySession *session = new PlaySession(update,hours,platform,user,game);
			user->addSession(session);
			game->addSession(session);
			break;
		}
		case 5:{
			vector<PlaySession *> sessions(user->getSessions());
			std::cout << "\n\nInsert the number of sessions to see (0 shows every session)";
			unsigned int lim_ssn;
			input_receiver(lim_ssn);
			user->printSessionsUser(lim_ssn);
			break;
		}
		case 6:{
			std::cout << endl << "Input the title of the game to buy\nInput: ";
			string title;
			getline(cin,title);

			Game * game;

			while(true){
				try{
					game = lsystem->searchGame(title);
					break;
				}
				catch(NonExistingGame &e){
					e.printInf();
					std::cout << endl << "Input the title of the game\nInput: ";
					string title;
					getline(cin,title);
				}
			}

			std::cout << "\n\nInput the index of the card that will be used for the purchase";
			unsigned int card_ind;
			input_receiver(card_ind);
			while(card_ind > user->getCards().size()){
				std::cout << "\nInvalid Index\n";
				input_receiver(card_ind);
			}

			try{
				lsystem->buyGame(user,game,card_ind - 1);
			}
			catch(GameAlreadyOwned &e){
				e.printInf();
				std::cout << "\n\n";
			}
			catch(UserTooYoung &e){
				e.printInf();
				std::cout << "\n\n";
			}
			catch(InvalidCard &e){
				e.printInf();
				std::cout << "\n\n";
			}
			catch(NotEnoughFunds &e){
				e.printInf();
				std::cout << "\n\n";
			}
			break;
		}
		case 7:{
			std::cout << "\n\nInsert the number of updates to see (0 shows most recent update for every game)";
			unsigned int lim_upd;
			input_receiver(lim_upd);
			user->printUpdates(lim_upd);
			break;
		}
		case 8:{
			std::cout << endl << "Input the title of the game to update\nInput: ";
			string title;
			getline(cin,title);

			Game * game;

			while(true){
				try{
					game = lsystem->searchGame(title);
					break;
				}
				catch(NonExistingGame &e){
					e.printInf();
					std::cout << endl << "Input the title of the game\nInput: ";
					string title;
					getline(cin,title);
				}
			}

			try{
				if(user->installUpdates(game))
					std::cout << endl << "Game successfully updated\n";
				else
					std::cout << endl << "Game successfully updated\n";
			}
			catch(GameNotOwned &e){
				std::cout << "Warning: ";
				e.printInf();
				std::cout << "\n\n";
			}
			break;
		}
		case 0:
			return;
		}
	}
}

void print_user_interface(){
	std::cout << "Would you like to: " << std::endl << std::endl;
	std::cout << "\t1: See the game library" << std::endl;
	std::cout << "\t2: Add a card" << std::endl;
	std::cout << "\t3: See cards" << std::endl;
	std::cout << "\t4: Add a game session" << std::endl;
	std::cout << "\t5: See game session history" << std::endl;
	std::cout << "\t6: Buy a game" << std::endl;
	std::cout << "\t7: See installed updates" << std::endl;
	std::cout << "\t8: Update a game" << std::endl;
	std::cout << "\t0: Leave the user editor" << std::endl << std::endl;
}

int prompt_user_interface(){
	int input = -1;
	input_receiver(input);
	while(input < 0 || input > 8){
		std::cout << "Please insert an integer between 0 and 8" << std::endl;
		input_receiver(input);
	}
	return input;
}

void card_interface(Card &card){
 	draw_header("CARD");
 	while(true){
		print_card_interface();
		switch(prompt_card_interface()){
		case 1:{
			std::cout << "Insert the new card number\n";
			string new_number;
			input_receiver(new_number);

			card.setNumber(new_number);

			if(!card.getValidity())
				std::cout << "Warning: the card number is not valid" << endl << endl;

			break;
		}
		case 2:{
			std::cout << "Insert the new card balance: ";
			double new_balance;
			input_receiver(new_balance);

			if (!card.setBalance(new_balance))
				std::cout << "Warning: the card number is not valid" << endl << endl;
 			break;
		}
		case 0:
			return;
		}
	}
}
 void print_card_interface(){
 	std::cout << "Would you like to: " << std::endl << std::endl;
	std::cout << "\t1: Change card number" << std::endl;
	std::cout << "\t2: Change card balance" << std::endl;
	std::cout << "\t0: Exit the card interface" << std::endl << std::endl;
}
 int prompt_card_interface(){
	int input = -1;
	input_receiver(input);
	while(input < 0 || input > 2){
		std::cout << "Please insert an integer between 0 and 2" << std::endl;
		input_receiver(input);
	}
	return input;
}

void save_interface(){
 	draw_header("EXPORT");
 	std::cout << "To save the system to a file, input the file name (if you don't want to save to a file input an empty string):" << std::endl;
	std::string input;
	getline(cin,input);
	if(input.length()){
		fstream file;
		file.open(input);
		if (file.fail()){
			cerr << "Error opening file" << endl;
		}
		else{
			lsystem->giveInfoSystem(file);
		}
	}

	delete lsystem;

}





