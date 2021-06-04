#include "ProvinceManager.h"
#include "City.h"
#include "Properties.h"

#include <math.h>
#include <windows.h>
#include <conio.h>


double EARTH_RADIUS = 6378.137;//地球半径 单位km

ProvinceManager::ProvinceManager() {
	SYSTEMTIME time, nowtime;
	CsvReader* cReader = new CsvReader("Cities.csv");
	set<vector<string>> CitiesFile = cReader->getReader();
	for (set<vector<string>>::iterator iter = CitiesFile.begin();iter != CitiesFile.end();iter++) {
		vector<string> temp = *iter;
		Province* newPro = NULL;
		map<string, Province>::iterator iter_province = Provinces.find(temp[0]);
		if (iter_province == Provinces.end()) {//找不到temp[0]名称的省份
			newPro = new Province(temp[0]);
			this->Provinces.insert(pair<string, Province>(temp[0], *newPro));
		}
		else newPro = &iter_province->second;
		newPro->loadCities(temp);
		
	}
	if (this->Provinces.size() != 0) {
		for (map<string, Province>::iterator iter = Provinces.begin();iter != Provinces.end();iter++) {
			Province temp = iter->second;
			if (temp.getCities()->size() == 0) {
				throw new exception("Invalid Provinces, please check out the file.");
				cout << "Invalid Provinces, please check out the file." << endl;
			}
		}
	}
	else{
		throw new exception("Invalid Provinces, please check out the file.");
		cout << "Invalid Provinces, please check out the file." << endl;
	}
	cout << "Cities are loaded successfully!" << endl;
	cout << "You can list the cities that were loaded, please press the key enter to do it in 3s." << endl;
	GetLocalTime(&time);
	GetLocalTime(&nowtime);
	int* p = new int(0);
	while (*p < 3) {
		int ch;
		if (_kbhit()) {
			ch = _getch();
			if (ch == 13) {
				cout << "You pressed the key_enter." << endl;
				this->info();
				break;
			}
		}
		GetLocalTime(&nowtime);
		if (nowtime.wSecond - time.wSecond > 1 && *p < 2) {
			time = nowtime;
			cout << "You can list the cities that were loaded, please press the key enter to do it in " << 2 - *p << "s." << endl;
			(*p)++;
		}
		else if (nowtime.wSecond - time.wSecond > 1) {
			time = nowtime;
			(*p)++;
		}
	}
	delete p;
}

bool ProvinceManager::isLoaded(const string proname) {//检查省份是否已经存在
	bool temp = false;
	for (map<string, Province>::iterator iter = Provinces.begin();iter != Provinces.end();iter++) {
		if (iter->first == proname) {
			return true;
		}
	}
	return temp;
}
double rad(double d) {//弧度转换，内置函数
	return d * 3.14159265358 / 180.0;
}

double ProvinceManager::distance(City c1, City c2) {//经纬度计算距离
	double radLat1 = rad(c1.getLatitude());
	double radLat2 = rad(c2.getLatitude());
	double a = radLat1 - radLat2;
	double b = rad(c1.getLongtitude()) - rad(c2.getLongtitude());
	double s = 2 * sin(sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2)));
	s = s * EARTH_RADIUS;
	s = (s * 10) / 10;
	return s;
}

Province ProvinceManager::getProvinceByName(string name) {
	if (isLoaded(name)) {
		map<string, Province>::iterator iter = this->Provinces.find(name);
		return iter->second;
	}
}

City ProvinceManager::find(string CityName) {//根据城市名返回城市
	for (map<string, Province>::iterator iter = Provinces.begin();iter != Provinces.end();iter++) {
		Province ta = iter->second;
		for (list<City>::iterator itor = ta.getCities()->begin();itor != ta.getCities()->end();itor++) {
			City c = *itor;
			if (c.getName() == CityName) {
				return c;
			}
		}
	}
}