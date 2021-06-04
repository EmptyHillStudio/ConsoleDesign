#pragma once
#include <string>

#include "Properties.h"

using namespace std;

class City
{
private:
	string name;
	double longtitude, latitude, BusIndex, TourIndex, CompreIndex;
public:
	bool isCap;
	City(string name, bool isCap, double logntitude, double latitude, double busindex, double tourindex);
	City();
	string getName() { return name; }
	double getLongtitude() { return longtitude; }
	double getLatitude() { return latitude; }
	double getBusIndex() { return BusIndex; }
	double getTourIndex() { return TourIndex; }
	double getCompreIndex() { return CompreIndex; }
};

