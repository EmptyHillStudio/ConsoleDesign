#pragma once
#include <string>
#include <list>

using namespace std;

class Research{
protected:
	string Name, Description;//���ֺ�����
	double Cost;//����
	int Needed_Day;//�о�ʱ��
	bool Researched;//�Ƿ��о����
	
public:

	list<string> Needed;//��Ҫ��ǰ�ÿƼ�������

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

