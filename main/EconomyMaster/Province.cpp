#include "Province.h"
Province::Province(string name) {
	this->name = name;
	this->Cities = new list<City>;
}
void Province::loadCities(vector<string> CitiesLine) {
	City* temp = new City(CitiesLine[1], atof(CitiesLine[2].c_str()), atof(CitiesLine[3].c_str()), atof(CitiesLine[4].c_str()), atof(CitiesLine[5].c_str()), atof(CitiesLine[6].c_str()));
	Cities->insert(Cities->begin(), *temp);
}
void Province::info() {
	for (list<City>::iterator iter = Cities->begin();iter != Cities->end();iter++) {
		City temp = *iter;
		cout << "City：" << temp.getName() << endl;
	}
}

void Province::infoDetails() {
	for (list<City>::iterator iter = Cities->begin();iter != Cities->end();iter++) {
		City temp = *iter;
		cout << "城市名：" << temp.getName() << endl;
		cout << "经度：" << temp.getLongtitude() << endl;
		cout << "纬度：" << temp.getLatitude() << endl;
		cout << "综合指数：" << temp.getCompreIndex() << "(商务指数：" << temp.getBusIndex() << "\t旅游指数：" << temp.getTourIndex() << ")" << endl;
		cout << "\n\n";
	}
}

void Province::infoUnless(string name) {
	for (list<City>::iterator iter = Cities->begin();iter != Cities->end();iter++) {
		City temp = *iter;
		if (temp.getName()!=name) {
			cout << "City：" << temp.getName() << endl;
		}
	}
}

void Province::infoUnless(City c) {
	for (list<City>::iterator iter = Cities->begin();iter != Cities->end();iter++) {
		City temp = *iter;
		if (c.getName() != temp.getName()) {
			cout << "City：" << temp.getName() << endl;
		}
	}
}

City Province::getCityByName(string name) {
	City *empty = NULL;
	for (list<City>::iterator iter = Cities->begin();iter != Cities->end();iter++) {
		City temp = *iter;
		if (name == temp.getName()) {
			return temp;
		}
	}
	return *empty;
}

bool Province::isInProvince(string name) {
	for (list<City>::iterator iter = Cities->begin();iter != Cities->end();iter++) {
		City temp = *iter;
		if (name == temp.getName()) {
			return true;
		}
	}
	return false;
}

Province::Province() {

}