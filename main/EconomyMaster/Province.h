#pragma once
#include <string>
#include <vector>
#include <list>
#include "City.h"
#include <iostream>

using namespace std;

class Province
{
private:
	string name;
	list<City> *Cities;
public:
	Province(string name);
	Province();
	string getName() { return name; }
	void loadCities(vector<string> CitiesLine);
	void info();
	void infoDetails();
	void infoUnless(string name);
	void infoUnless(City c);
	list<City> *getCities() { return Cities; }
	City getCityByName(string name);
	bool isInProvince(string name);
};

