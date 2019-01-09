#include <iostream>
#include <iomanip>

#include "../Card/Card.h"
#include "../Date/Date.h"
#include "../Exceptions.h"
#include "../Game/Game.h"
#include "../Interval/Interval.h"
#include "../PlaySession/PlaySession.h"
#include "../Restricts/Restricts.h"
#include "../Sorts/Sorts.h"
#include "../System/System.h"
#include "../User/User.h"

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
 * @brief Funcao que gere o menu de um jogo
 * @param game Jogo sobre o qual o utilizador vai operar
 */
void game_interface(Game *game);

/**
 * @brief Funcao que imprime no ecra o menu de um jogo
 * @param home Variavel boolean que e true se o jogo e Home, false caso seja online
 */
void print_game_interface(const bool &home);

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_game_interface();

/**
 * @brief Funcao que gere o menu de um utilizador de jogos
 * @param user Utilizador a ser analisado
 */
void user_interface(User *user);

/**
 * @brief Funcao que imprime no ecra o menu de um utilizador
 */
void print_user_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_user_interface();

/**
 * @brief Funcao que gere o menu de um cartao bancario
 * @param card Cartao a ser analisado
 */
void card_interface(Card &card);

/**
 * @brief Funcao que imprime no ecra o menu de um cartao bancario
 */
void print_card_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_card_interface();

/**
 * @brief Funcao que guarda o sistema criado num ficheiro de texto
 */
void save_interface();

/**
 * @brief Funcao que gere um menu de opcoes, para o utilizador escolher como ordenar o vetor store de jogos
 */
void sort_game_interface();

/**
 * @brief Funcao que imprime no ecra o menu de opcoes de ordenacao de store
 */
void print_sort_game_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_sort_game_interface();

/**
 * @brief Funcao que gere um menu de opcoes, para o utilizador escolher como ordenar o vetor user_library
 */
void sort_user_interface();

/**
 * @brief Funcao que imprime no ecra o menu de opcoes de ordenacao de user_library
 */
void print_sort_user_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_sort_user_interface();

/**
 * @brief Funcao que gere um menu de opcoes, para o utilizador escolher como ordenar um vetor de jogos
 * @param vec Vetor de jogos a ser ordenado
 */
void sort_game_vector_interface(vector<Game *> &vec);

/**
 * @brief Funcao que gere um menu de opcoes, para o utilizador escolher como ordenar um vetor de utilizadores
 * @param vec Vetor de utilizadores a ser ordenado
 */
void sort_user_vector_interface(vector<Game *> &vec);

/**
 * @brief Funcao que permite pesquisar jogos atraves de tags na store
 * @return Retorna o vetor de jogos resultante da pesquisa
 */
vector<Game *> restrict_game_interface();

/**
 * @brief Funcao que imprime o menu de pesquisas de jogos por tags na store
 */
void print_restrict_game_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_restrict_game_interface();

/**
 * @brief Funcao que permite pesquisar utilizadores atraves de tags na user_library
 * @return Retorna o vetor de utilizadores resultante da pesquisa
 */
vector<User *> restrict_user_interface();

/**
 * @brief Funcao que imprime o menu de pesquisas de utilizadores por tags na user_library
 */
void print_restrict_user_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_restrict_user_interface();

/**
 * @brief Funcao que permite pesquisar jogos atraves de tags
 * @param vec Vetor de jogos a ser usado na pesquisa
 * @return Retorna o vetor de jogos resultante da pesquisa
 */
vector<Game*> restrict_game_interface(vector<Game*> vec);

/**
 * @brief Funcao que permite pesquisar utilizadores atraves de tags
 * @param vec Vetor de utilizadores a ser usado na pesquisa
 * @return Retorna o vetor de utilizadores resultante da pesquisa
 */
vector<User*> restrict_user_interface(vector<User*> vec);

/**
 * @brief Funcao que imprime no ecra o menu gestao dos resultados da pesquisa
 */
void print_vector_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_vector_interface();

/**
 * @brief Funcao que gere os resultados de uma pesquisa de jogos
 * @param vec Vetor resultante da pesquisa de jogos
 */
void game_vector_interface(vector<Game*> &vec);

/**
 * @brief Funcao que gere os resultados de uma pesquisa de utilizadores
 * @param vec Vetor resultante da pesquisa de utilizadores
 */
void user_vector_interface(vector<User*> &vec);

/**
 * @brief Funcao que importa um sistema de um ficheiro de texto
 */
void load_interface();

/**
 * @brief Funcao que possibilita a adicao de uma empresa a um sistema por parte do utilizador
 * @return Retorna a empresa adicionada ao sistema
 */
Developer* add_developer_interface();

/**
 * @brief Funcao que imprime no ecra o menu de uma empresa
 */
void print_developer_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_developer_interface();

/**
 * @brief Funcao que gere o menu de uma empresa
 * @param developer Empresa sobre a qual o utilizador vai operar
 */
void developer_interface(Developer* developer);

/**
 * @brief Funcao que gere o menu da Wish list de um utilizador
 * @param user Utilizador a ser analisado
 */
void wishlist_interface(User *user);

/**
 * @brief Funcao que imprime no ecra o menu da Wish list de um utilizador
 */
void print_wishlist_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_wishlist_interface();

/**
 * @brief Funcao que gere o menu da data atual do sistema
 */
void date_interface();

/**
 * @brief Funcao que imprime no ecra o menu da data atual do sistema
 */
void print_date_interface();

/**
 * @brief Funcao que analisa o input do utilizador e o retorna se for valido, ou mostra uma mensagem de erro enquanto for invalido
 * @return Retorna o input dado pelo utilizador
 */
int prompt_date_interface();

/**
 * @brief Funcao que gere o menu de utilizadores adormecidos de um jogo do sistema
 */
void sleeping_interface();

