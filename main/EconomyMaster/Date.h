#pragma once
#include <windows.h>
#include <string>

using namespace std;

class Date
{
private:
	int year, month, day;
	int year_month_common[12] = { 31, 28,31,30,31,30,31,31,30,31,30,31 };
	int year_month_special[12] = { 31, 29,31,30,31,30,31,31,30,31,30,31 };
	bool isSpecail(int year) {
		if (year % 4 == 0) {
			return true;
		}
		else return false;
	}
public:
	Date();
	Date(int year, int month, int day);
	Date(string date);
	Date operator -(const int date);
	void dayPlus(int day);
	string toString();
	void setYear(int year) { this->year = year; }
	void setMonth(int month) { this->month = month; }
	void setDay(int day) { this->day = day; }
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	bool isLegial(int year, int month, int day);
};

