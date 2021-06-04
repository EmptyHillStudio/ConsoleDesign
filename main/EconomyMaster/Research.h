#pragma once
#include <string>
#include <list>

using namespace std;

class Research{
protected:
	string Name, Description;//名字和描述
	double Cost;//花费
	int Needed_Day;//研究时间
	bool Researched;//是否研究完毕
	
public:

	list<string> Needed;//需要的前置科技的名字

	string getName() { return Name; }
	string getDesctipion() { return Description; }
	double getCost() { return Cost; }
	int getDayInNeeded() { return Needed_Day; }
	bool isResearched() { return Researched; }
	void setName(string name) { this->Name = name; }
	void setCosat(double cost) { Cost = cost; }
	void setNeeded_Day(int day) { Needed_Day = day; }
	void setResearchState(bool state) { Researched = state; }
};

