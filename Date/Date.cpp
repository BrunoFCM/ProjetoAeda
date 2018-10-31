#include "Date.h"

Date::Date(const std::string &date) {		//input no formato DD-MM-AAAA
	day = std::stoi(date.substr(0,2));
	month = std::stoi(date.substr(3,2));
	year = std::stoi(date.substr(5,4));
}

Date::Date(unsigned int d, unsigned int m, unsigned int y):		//input de números inteiros
		day(d), month(m), year(y) {}

unsigned int Date::getDay() const {
	return day;
}

unsigned int Date::getMonth() const {
	return month;
}

unsigned int Date::getYear() const {
	return year;
}

std::string Date::getDate() const {			//output no formato DD-MM-AAAA
	return std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year);
}
