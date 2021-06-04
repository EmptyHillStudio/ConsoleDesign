#pragma once
#include "City.h"

class Airline
{
private:
	City Point[2];//起点和终点
	double distance;
	
public:
	Airline(City c1, City c2);
};

