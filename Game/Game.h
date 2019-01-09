#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_set>
#include "../Date/Date.h"
#include "../Interval/Interval.h"
#include "../PlaySession/PlaySession.h"

using namespace std;

class Date;
class Interval;
class PlaySession;


/**
 * @brief Struct auxiliar para a tabela de hash
 */
struct UserHash {
	int operator() (const string &em) const		//temporary hash function
	{
		int hash = 0;
		for(auto c : em) {
			hash += 37*c;
		}
		return hash;
	}

	bool operator() (const string &em1, const string &em2) const
	{
		return em1 == em2;
	}
};

typedef unordered_set<string, UserHash, UserHash> HashTabUser;


/**
 * Classe base Game
 */
class Game
{
protected:
	unsigned int id;				//identificador unico
	string title;					//nome
	double price;					//preco de aquisicao
	double base_price;				//preco de aquisicao base
	Date release;					//data de lancamento
	Interval age_range;				//intervalo de idades
	vector<string> platform;			//plataformas disponiveis
	vector<string> genre;				//genero
	string developer;				//empresa que o desenvolveu
	vector<double> price_history;			//historial de precos de aquisicao
	unsigned int player_base; 			//numero de jogadores
	
	/********				  ********/
	/********            PARTE 2              ********/
	/********				  ********/

	HashTabUser sleepingUsers;			//tabela de hash de utilizadores adormecidos
	
public:

	/**
	 * @brief Construtor da classe Game
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 */
	Game(const string &title,const double &price,const Date &release,const Interval &age_range,const vector<string> &platforms,const vector<string> &genres,const string &developer);

	/**
	 * @brief Destrutor da classe Game
	 */
	virtual ~Game(){}

	/**
	* @brief Membro-funcao que retorna o identificador unico de um jogo
	* @return Retorna o identificador unico de um jogo
	*/
	unsigned int getId() const;

	/**
	* @brief Membro-funcao que retorna o titulo de um jogo
	* @return Retorna o titulo de um jogo
	*/
	string getTitle() const;

	/**
	* @brief Membro-funcao que retorna o preco de aquisicao de um jogo
	* @return Retorna o preco de aquisicao de um jogo
	*/
	double getPrice() const;

	/**
	* @brief Membro-funcao que retorna o preco de aquisicao base de um jogo
	* @return Retorna o preco de aquisicao base de um jogo
	*/
	double getBasePrice() const;

	/**
	* @brief Membro-funcao que retorna a data de lancamento de um jogo
	* @return Retorna a data de lancamento de um jogo
	*/
	Date getRelease() const;

	/**
	* @brief Membro-funcao que retorna a faixa etaria a que se tem de pertencer para se poder jogar
	* @return Retorna um intervalo de idades
	*/
	Interval getAge() const;

	/**
	* @brief Membro-funcao que retorna um vetor de plataformas para as quais o jogo se encontra disponivel
	* @return Retorna um vetor de plataformas
	*/
	vector<string> getPlatforms() const;

	/**
	* @brief Membro-funcao que retorna um vetor de strings correspondentes aos generos dos jogos
	* @return Retorna um vetor de strings correspondentes aos generos dos jogos
	*/
	vector<string> getGenre() const;

	/**
	* @brief Membro-funcao que retorna uma string correspondente ao nome da empresa que desenvolveu o jogo
	* @return Retorna o nome da empresa
	*/
	string getDeveloper() const;

	/**
	* @brief Membro-funcao que retorna o historial de precos de aquisicao do jogo
	* @return Retorna o historial de precos de aquisicao do jogo
	*/
	vector<double> getPriceHist() const;

	/**
	* @brief Membro-funcao que retorna um vetor de strings correspondentes ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â  base de jogadores do jogo
	* @return Retorna o valor de player_base, correspondente ao numero de jogadores
	*/
	unsigned int getPlayerBase() const;

	/**
	 * @brief Devolve um vetor com todos os updates feitos ao jogo
	 * @return Retorna um vetor vazio
	 */
	virtual vector<Date> getUpdates() const;

	/**
	* @brief Overload do operador == para jogos
	* @param game Jogo com qual e comparado
	* @return Retorna true se o id dos dois jogos for igual e false caso contrario
	*/
	bool operator==(Game &game);

	/**
	* @brief Altera o preco atual do jogo
	* @param newPrice Novo preco do jogo
	*/
	void changePrice(const double &newPrice);

	/**
	* @brief Define um desconto para um jogo
	* @param percentage Desconto a definir
	*/
	void discountPrice(const unsigned int &percentage);

	/**
	* @brief Altera o preÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§o base do jogo
	* @param newPrice Novo preco base do jogo
	*/
	void changeBasePrice(const double &newPrice);

	/**
	* @brief Altera o preco para o preco base
	*/
	void revertToPrice();

	/**
	* @brief Adiciona um utilizador a base de jogadores de jogo
	*/
	void addUser();

	/**
	 * @brief Membro puramente virtual que permite obter informacao sobre um determinado jogo. Encontra-se implementado nas classes derivadas Home e Online
	 */
	virtual void printInfoGame() const = 0;

	/**
	 * @brief Membro puramente virtual que permite obter informacao relativamente ao jogo ser Home ou Online
	 */
	virtual bool isHomeTitle() const = 0;

	/**
	 * @brief Membro virtual utilizavel apenas pela classe derivada Home
	 */
	virtual void addUpdate(Date date);

	/**
	 * @brief Membro puramente virtual utilizavel apenas pela classe derivada Online (e respetivas derivadas), devolvendo um vetor vazio para outras classes
	 */
	virtual vector<PlaySession*> getPlayHistory() const;

	/**
	 * @brief Acrescenta uma PlaySession ao vetor de sessoes ao jogo online (nas outras classes, a funcao retorna sem executar nada)
	 * @param sess Pointer para a PlaySession a adicionar
	 */
	virtual void addSession(PlaySession *sess);

	/**
	* @brief Funcao virtual que passa para uma ostream a informacao de um jogo
	* @param info Ostream para onde e passada a informacao de um jogo
	*/
	virtual void giveInfoGame(ostream &info) const;

	
/********				  ********/
/********     PARTE 2     ********/
/********				  ********/

	/**
	 * @brief Funcao que adiciona um jogador adormecido a hash
	 * @param em String do email do utilizador
	 */
	void addSleepingUser(string em);

	/**
	 * @brief Funcao que remove um jogador adormecido da hash
	 * @param em String do email do utilizador
	 */
	void removeSleepingUser(string em);

	/**
	 * @brief Apaga a hash table de jogadores adormecidos
	 */
	void deleteSleepingUsers();

	/**
	* @brief Função que imprime os utilizadores adormecidos no ecra
	*/
	void printSleepingUsers();

	/**
	* @brief Funcao que passa para uma ostream os utilizadores adormecidos
	* @param info Ofstream para onde sao passados os utilizadores adormecidos
	*/
	void giveInfoSleepingUsers(ostream &info);

};





/**
 * Classe Online derivada da classe Game
 */
class Online : public Game
{
private:
	int play_time;					//tempo jogado
	vector<PlaySession*> play_history;		//historial para cada jogo online que inclui: quando foi jogado, por quanto tempo e em que plataforma
public:
	/**
	 * @brief Construtor da classe Online
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 */
	Online(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer);

	/**
	 * @brief Destrutor da classe Online
	 */
	virtual ~Online() {};

	/**
	 * @brief Devolve o tempo total jogado
	 */
	int getPlayTime() const;

	/**
	 * @brief Devolve o valor 0
	 */
	virtual double getPrice() const;

	/**
	 * @brief Permite aceder ao conjunto de sessoes efetuadas no jogo
	 * @return Vetor apontador para o conjunto de objetos de classe PlaySession
	 */
	vector<PlaySession*> getPlayHistory() const;

	/**
	 * @brief Acrescenta uma PlaySession ao vetor de sessoes ao jogo online (nas outras classes, a funcao retorna sem executar nada)
	 * @param sess Pointer para a PlaySession a adicionar
	 */
	void addSession(PlaySession *sess);

	/**
	 * @brief Funcao que permite obter informacao relativamente ao jogo ser Home ou Online
	 * @return True se o jogo for Home
	 */
	bool isHomeTitle() const;

	/**
	* @brief Funcao virtual que passa para uma ofstream a informacao de um jogo online
	* @param info Ostream para onde e passada a informacao de um jogo online
	*/
	virtual void giveInfoGame(ofstream &info) const{};
};



/**
 * Classe FixedSubsc derivada da classe Online
 */
class FixedSubsc : public Online
{
private:
	double fixed_price;				 //preco fixo
public:

	/**
	 * @brief Construtor da classe FixedSubsc
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 * @param fixed_price Preco de subscricao fixa
	 */
	FixedSubsc(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const double &fixed_price);

	/**
	 * @brief Devolve o preco da subscricao fixa
	 * @return Preco da subscricao fixe
	 */
	double getPrice() const;

	/**
	 * @brief Imprime informacao relativamente ao jogo
	 */
	void printInfoGame() const;

	/**
	* @brief Funcao virtual que passa para uma fstream a informacao de um jogo online de subscricao fixa
	* @param info Ofstream para onde e passada a informacao de um jogo online de subscricao fixa
	*/
	void giveInfoGame(ofstream &info) const;
};



/**
 * Classe VariableSubsc derivada da classe Online
 */
class VariableSubsc : public Online
{
private:
	double price_hour;					 //preco variavel: custo do jogo por hora
public:

	/**
	 * @brief Construtor da classe VariableSubsc
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 * @param price_hour Preco pago por cada hora jogada
	 */
	VariableSubsc(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer, const double &price_hour);

	/**
	 * @brief Devolve o preco pago atual, dependente do preco por hora e pelo tempo jogado
	 * @return Preco pago atual
	 */
	double getPriceHour() const;

	/**
	 * @brief Imprime informacao relativamente ao jogo
	 */
	void printInfoGame() const ;

	/**
	* @brief Funcao virtual que passa para uma fstream a informacao de um jogo online de subscricao variavel
	* @param info Ofstream para onde e passada a informacao de um jogo online de subscricao variavel
	*/
	void giveInfoGame(ofstream &info) const;
};





/**
 * Classe Home derivada da classe Game
 */
class Home : public Game
{
private:
	vector<Date> updates;					 //data das atualizacoes em que o utilizador fez download do respetivo titulo (1 euro cada)
public:
	/**
	 * @brief Construtor da classe Home
	 * @param title Nome do jogo
	 * @param price Preco de aquisicao do jogo
	 * @param release Data de lancamento do jogo
	 * @param age_range Faixa etaria a que se tem de pertencer para se poder jogar
	 * @param platforms Vetor de plataformas para as quais o jogo se encontra disponivel
	 * @param genres Vetor de generos dos jogos
	 * @param developer Empresa responsavel pela criacao do jogo
	 */
	Home(const string &title, const double &price, const Date &release, const Interval &age_range, const vector<string> &platforms, const vector<string> &genres, const string &developer);

	/**
	 * @brief Devolve um vetor com todos os updates feitos ao jogo
	 * @return Vetor de datas de update
	 */
	vector<Date> getUpdates() const;

	/**
	 * @brief Acrescenta um update ao vetor de update
	 * @param date Data do update a acrescentar
	 */
	void addUpdate(Date date);

	/**
	 * @brief Imprime informacao relativamente ao jogo
	 */
	void printInfoGame() const;

	/**
	 * @brief Funcao que permite obter informacao relativamente ao jogo ser Home ou Online
	 * @return True se o jogo for Home
	 */
	bool isHomeTitle() const;

	/**
	* @brief Funcao virtual que passa para uma fstream a informacao de um jogo home
	* @param info Ofstream para onde e passada a informacao de um jogo home
	*/
	void giveInfoGame(ofstream &info) const;
};


#endif /* SRC_GAME_H_ */
