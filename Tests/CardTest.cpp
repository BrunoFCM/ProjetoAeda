#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Card.h"

void thisIsATest() {
	Card c1("4556322303773830",60); //valid number
		ASSERT_EQUAL(1,c1.getValidity());
		ASSERT_EQUAL(60,c1.getBalance());
		c1.setBalance(70);
		ASSERT_EQUAL(70,c1.getBalance());
		c1.setNumber("1234567891144557");
		ASSERT_EQUAL(0,c1.getBalance());
		ASSERT_EQUAL(0,c1.getValidity());

		Card c2("1234567891144557",60); //invalid number
		ASSERT_EQUAL(0,c2.getValidity());
		ASSERT_EQUAL(0,c2.getBalance());
		c2.setBalance(70);
		ASSERT_EQUAL(0,c2.getBalance());
		c2.setNumber("4556322303773830");
		ASSERT_EQUAL(true,c2.getValidity());
		c2.setBalance(70);
		ASSERT_EQUAL(70,c2.getBalance());
}

void runSuite() {
	cute::suite s;


	s.push_back(CUTE(thisIsATest));
	cute::ide_listener<> lis;
		cute::makeRunner(lis)(s, "Teste");
}

int main(int argc, char const *argv[]) {
	runSuite();
	    return 0;
}
