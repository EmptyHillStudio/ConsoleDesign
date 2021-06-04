#include "Date.h"
#include <iostream>
Date::Date() {
	SYSTEMTIME ST;
	GetLocalTime(&ST);
	this->year = ST.wYear;
	this->month = ST.wMonth;
	this->day = ST.wDay;
}
Date::Date(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::Date(string date) {

}
void Date::dayPlus(int day) {
	this->day++;
	if (isSpecail(year)) {
		if (this->day > year_month_special[month - 1]) {
			
			this->day = 1;
			this->month++;
			if (this->month > 12) {
				this->month = 1;
				this->year++;
			}
		}
	}
	else {
		if (this->day > year_month_common[month - 1]) {
			this->day = 1;
			this->month++;
			if (this->month > 12) {
				this->month = 1;
				this->year++;
			}
		}
	}
}

bool Date::isLegial(int year, int month, int day) {
	if (month > 12 || month < 0) {
		return false;
	}
	if (year < 1900) {
		return false;
	}
	if (day<0) {
		return false;
	}
	if (isSpecail(year)) {
		if (day > year_month_special[month - 1]) {
			return false;
		}
	}
	else {
		if (day > year_month_common[month - 1]) {
			return false;
		}
	}
}
