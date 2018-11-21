#include "Date.h"
#include "Exceptions.h"

Date::Date(const std::string &date) {		//input no formato DD-MM-AAAA

	if (date.size() != 10)
		throw InvalidDate(date);


	day = std::stoi(date.substr(0,2));
	month = std::stoi(date.substr(3,2));
	year = std::stoi(date.substr(5,4));


	if (year < 1900) {
		std::string info ="ano " + date.substr(5,4);
		throw InvalidDate(info);
	}

	if (month < 1 || month > 12) {
		std::string info = "mes " + date.substr(3,2);
		throw InvalidDate(info);
	}

	if (month == 2) {
		if (day < 1 || day > 28) {
			std::string info = "dia " + date.substr(0,2);
			throw InvalidDate(info);
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7|| month == 8 || month == 10|| month == 12) {
		if (day < 1 || day > 31) {
			std::string info = "dia " + date.substr(0,2);
			throw InvalidDate(info);
		}
	}
	else {
		if (day < 1 || day > 30) {
			std::string info = "dia " + date.substr(0,2);
			throw InvalidDate(info);
		}
	}

}

Date::Date(const unsigned int &d, const unsigned int &m, const unsigned int &y) {//input de numeros inteiros
		day = d;
		month = d;
		year = y;

		if (year < 1900) {
			std::string info ="ano " + std::to_string(y);
			throw InvalidDate(info);
		}

		if (month < 1 || month > 12) {
			std::string info = "mes " + std::to_string(m);
			throw InvalidDate(info);
		}

		if (month == 2) {
			if (day < 1 || day > 28) {
				std::string info = "dia " + std::to_string(d);
				throw InvalidDate(info);
			}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7|| month == 8 || month == 10|| month == 12) {
			if (day < 1 || day > 31) {
				std::string info = "dia " + std::to_string(d);
				throw InvalidDate(info);
			}
		}
		else {
			if (day < 1 || day > 30) {
				std::string info = "dia " + std::to_string(d);
				throw InvalidDate(info);
			}
		}

}

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

bool Date::operator< (const Date &date2) const{
	if (year == date2.year)
		if (month == date2.month)
			return (day < date2.day);
		else
			return (month < date2.month);
	else
		return (year < date2.year);
}

bool Date::operator== (const Date &date2) const{
	return ((year == date2.year) && (month == date2.month) && (day == date2.day));
}
