#include "Restricts.h"

bool gameIdInterval(Game* g1, const Interval &inter){
	return (inter.contains(g1->getId()));
}

bool gamePriceMax(Game* g1, const double &max){
	return (g1->getPrice() < max);
}

bool gameRelease(Game* g1, const Date &date){
	return (g1->getRelease() == date);
}

bool gameAgeRange(Game* g1, const Interval &inter){
	return (inter.coincide(g1->getAge()));
}

bool gamePlatform(Game* g1, const std::string &platform){
	return (g1->getTitle() == platform);
}

bool gameGenre(Game* g1, const std::string &genre){
	vector <string> vec(g1->getGenre());
	for (unsigned int i = 0; i < vec.size(); ++i){
		if (vec[i] == genre)
			return true;
	}
	return false;
}

bool gameDeveloper(Game* g1, const std::string &developer){
	return (g1->getDeveloper() == developer);
}




bool userAgeInterval(User* u1, const Interval &inter){
	return (inter.contains(u1->getAge()));
}

bool userLibrarySize(User* u1, const Interval &inter){
	return (inter.contains(u1->getLibrary().size()));
}
