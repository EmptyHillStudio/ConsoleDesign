#include "City.h"
City::City(string name, bool isCap, double longtitude, double latitude, double busindex, double tourindex) {
	Properties* pro = new Properties("Cities.properties");
	pro->load();
	double Business_index_weight = atof(pro->read("Business_Index_weight")[0].c_str());
	double Tour_Index_weight = atof(pro->read("Tour_Index_weight")[0].c_str());
	this->name = name;
	this->isCap = isCap;
	this->longtitude = longtitude;
	this->latitude = latitude;
	this->BusIndex = busindex;
	this->TourIndex = tourindex;
	this->CompreIndex = (busindex * Business_index_weight + tourindex * Tour_Index_weight) / 2;
	pro->close();
}
City::City() {
	
}