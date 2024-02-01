// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <cstring>
#include <exception>

#include "date.h"

using namespace std;

Date::Date() 
{
	day = 0;
	month = 0;
	year = 0;
}

bool Date::isValide() const
{
	try {
		validateDate(year, month, day);
	}
	catch (std::exception&) {
		return false;
	}

	return true;
}

void Date::validateDate(int y, int m, int d) {

	if (y < 1900) {
		throw out_of_range("Year out of range");
	}
	if (m < 1 || m > 12) {
		throw out_of_range("Month out of range");
	}
	if (d < 1 || d > 31) {
		throw out_of_range("Day out of range");
	}
	if ((d != 29) && (m == 2) && !((y % 4 == 0) || (y % 100 == 0) || (y % 400 == 0))) {
		throw runtime_error("Invalid day format in February");
	}
	if (((m == 4) || (m == 6) || (m == 9) || (m == 11)) && ((d > 30))) {
		throw out_of_range("Day out of range");
	}
}

void Date::load(istream& in) {
	int d, m, y;
	char dots[2];
	in >> y;
	dots[0] = in.get();
	in >> m;
	dots[1] = in.get();
	in >> d;

	if (in.fail()) {
		throw runtime_error("Invalid year format");
	}
	if (dots[0] != '.' || dots[1] != '.')
		throw runtime_error("Invalid dots format!");

	validateDate(y, m, d);

	day = d;
	month = m;
	year = y;
}

void Date::print(std::ostream& out) const {
	cout << year << "." << month << "." << day << "\n";
}