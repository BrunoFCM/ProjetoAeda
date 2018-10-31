#include "Interval.h"

Interval::Interval(unsigned int low, unsigned int up):
		lower(low), upper(up) {}

unsigned int Interval::getLower() const {
	return lower;
}

unsigned int Interval::getUpper() const {
	return upper;
}

bool Interval::canPlay(unsigned int age) const {
	return (age >= lower && age <= upper);
}
