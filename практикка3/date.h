#pragma once

#include <iostream>

class Date {
public:
	int day;
	int month;
	int year;

	Date();
	void load(std::istream& in);
	void print(std::ostream& out) const;
	bool isValide() const;
	static void validateDate(int y, int m, int d);
};