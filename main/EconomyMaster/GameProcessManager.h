#pragma once
#include "City.h"
#include "AirlineManager.h"
#include "ProvinceManager.h"
#include "TimeControlor.cpp"

#include <map>
#include <string>

using namespace std;

class GameProcessManager
{
private:
	int Pro = 1;//回合数
	double money = 0, debt = 0;//钱和负债
	AirlineManager *aManager;
	ProvinceManager *pManager;
	string Company_Name;
	Province Head;
	City HeadQu;
	TimeControlor* TControlor;
public:
	GameProcessManager(ProvinceManager *pManager);
	void Process() { Pro++; }
	void addMoney(double data) { this->money += data; }
	void setMoney(double data) { this->money = data; }

	void perMessage(TimeControlor *tc);

	double profit();
	
};



