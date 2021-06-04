#pragma once
#include "City.h"
#include "ProvinceManager.h"
#include "Airline.h"

#include <map>

using namespace std;

class AirlineManager{
private:
	map<int, Airline> *Airlines;
	int AirlineNum;
public:
	AirlineManager();

	void create(City c1,City c2,ProvinceManager pManager);
	
};


