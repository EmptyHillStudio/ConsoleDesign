#pragma once
#include <set>
#include <vector>
#include <map>

#include "City.h"
#include "Province.h"
#include "CsvReader.h"
#include "Properties.h"

class ProvinceManager
{
private:
	map<string, Province> Provinces;
public:
	ProvinceManager();

	Province getProvinceByName(string name);
	City find(string CityName);
	bool isLoaded(const string Proname);
	void info() {
		for (map<string, Province>::iterator iter = Provinces.begin();iter != Provinces.end();iter++) {
			cout << "Province: " << iter->first <<  endl;
			iter->second.info();
		}
	}
	void infoPro() {
		for (map<string, Province>::iterator iter = Provinces.begin();iter != Provinces.end();iter++) {
			cout << "Province: " << iter->first << endl;
		}
	}
	double distance(City c1,City c2);
};

