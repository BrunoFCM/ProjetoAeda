#include "../Developer/Developer.h"

Developer::Developer(const std::string &name, const long int &nif, const std::string &eMail) {
	this->name = name;
	this->nif = nif;
	this->eMail = eMail;
	numGames = 0;
}

Developer::Developer() {
	name = "";
	nif = 0;
	eMail = "";
	numGames = 0;
}

std::string Developer::getName() const {
	return name;
}

long unsigned Developer::getNif() const {
	return nif;
}

std::string Developer::getEMail() const {
	return eMail;
}

vector<Game*> Developer::getGames() const {
	return games;
}

void Developer::addGame(Game* game) {
	games.push_back(game);
}

unsigned Developer::getNumGames() const {
	return numGames;
}

void Developer::incrementNumGames() {
	numGames++;
}

bool Developer::operator< (const Developer &dev2) const {
	if(numGames == dev2.numGames)
		return name < dev2.name;

	return numGames < dev2.numGames;
}

bool Developer::operator== (const Developer &dev2) const {
	return (name == dev2.getName() || nif == dev2.getNif() || eMail == dev2.getEMail());
}

void Developer::printDeveloper() const {
	cout << "Name: " << name << endl;
	cout << "NIF: " << nif << endl;
	cout << "Email: " << eMail << endl;
	cout << "Number of games created: " << numGames << endl;
}

void Developer::giveInfoDeveloper(ostream &info) const {
	info << name << "\n";
	info << nif << "\n";
	info << eMail << "\n";
	info << numGames << "\n";

	for (unsigned int i = 0; i < games.size(); i++)
		if(i != games.size() - 1)
		{
			games[i]->giveInfoGame(info);
			info << ",\n";
		}
		else {
			games[i]->giveInfoGame(info);
			info << ".\n";
		}
}

void Developer::printDevGames() const {
	for (unsigned int i = 0; i < games.size(); i++)
	{
		games[i]->printInfoGame();
	}
}
