#include "Interval.h"

Interval::Interval(const unsigned int &low, const unsigned int &up):
		lower(low), upper(up) {}

unsigned int Interval::getLower() const {
	return lower;
}

unsigned int Interval::getUpper() const {
	return upper;
}

bool Interval::contains(const unsigned int &value) const {
	return (value >= lower && value <= upper);
}

bool Interval::operator<(const Interval &inter2) const{
	if(lower == inter2.lower)
		return upper < inter2.upper;
	return lower < inter2.lower;
}

bool Interval::operator==(const Interval &inter2) const{
	return (lower == inter2.lower && upper == inter2.upper);
}


