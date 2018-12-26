#include "Developer.h"

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

void Developer::incrementNumGames() {
	numGames++;
}

bool Developer::operator< (const Developer &dev2) const {
	if(numGames == dev2.numGames)
		return name < dev2.name;

	return numGames < dev2.numGames;
}

//TO DO LATER
void Developer::printDeveloper() const {
	return;
}

