#include <conio.h>
#include <windows.h>
#include <iostream>

#include "Date.h"

using namespace std;

class TimeControlor {
private:
	Date date;
	
public:
	TimeControlor() {
		date = Date(1910,1,1);
	}
	void dayPlus() {
		date.dayPlus(1);
	}
	~TimeControlor() {
	}
	Date getDate() { return date; }
};
