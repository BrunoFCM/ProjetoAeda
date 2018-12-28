#include "Sorts.h"

bool userNameAscend(User* user1,User* user2){
	return user1->getName() < user2->getName();
}

bool userNameDescend(User* user1,User* user2){
	return user1->getName() > user2->getName();
}

bool userAgeAscend(User* user1,User* user2){
	return user1->getAge() < user2->getAge();
}

bool userAgeDescend(User* user1,User* user2){
	return user1->getAge() > user2->getAge();
}

bool gameIdAscend(Game* user1,Game* user2){
	return user1->getId() < user2->getId();
}

bool gameIdDescend(Game* user1,Game* user2){
	return user1->getId() > user2->getId();
}

bool gameTitleAscend(Game* user1,Game* user2){
	return user1->getTitle() < user2->getTitle();
}

bool gameTitleDescend(Game* user1,Game* user2){
	return user1->getTitle() > user2->getTitle();
}

bool gamePriceAscend(Game* user1,Game* user2){
	return user1->getPrice() < user2->getPrice();
}

bool gamePriceDescend(Game* user1,Game* user2){
	return user1->getPrice() > user2->getPrice();
}

bool gameBasePriceAscend(Game* user1,Game* user2){
	return user1->getBasePrice() < user2->getBasePrice();
}

bool gameBasePriceDescend(Game* user1,Game* user2){
	return user1->getBasePrice() > user2->getBasePrice();
}

bool gameReleaseAscend(Game* user1,Game* user2){
	return user1->getRelease() < user2->getRelease();
}

bool gameReleaseDescend(Game* user1,Game* user2){
	return !(user1->getRelease() == user2->getRelease() || user1->getRelease() < user2->getRelease());
}

bool gameAgeRangeAscend(Game* user1,Game* user2){
	return user1->getAge() < user2->getAge();
}

bool gameAgeRangeDescend(Game* user1,Game* user2){
	return !(user1->getAge() == user2->getAge() || user1->getAge() < user2->getAge());
}

bool gameDeveloperAscend(Game* user1,Game* user2){
	return user1->getDeveloper() < user2->getDeveloper();
}

bool gameDeveloperDescend(Game* user1,Game* user2){
	return user1->getDeveloper().getNumGames() > user2->getDeveloper().getNumGames();
}
