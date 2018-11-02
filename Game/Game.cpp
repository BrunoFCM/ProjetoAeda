#include "Game.h"

using namespace std;

static unsigned int id_Seq = 0;

Game::Game(string title, double price, Date release, Interval age_range, vector<string> platform, vector<string> genre, string developer)
{
	id = id_Seq;
	id_Seq++;

}