#include "EconomyManager.h"
#include "Properties.h"
EconomyManager::EconomyManager() {
	Properties Prop;
	this->debt = 0;
	this->money = 0;
	bool ret = Prop.open("Default.properties");
	if (ret != IS_OK)
	{
		cout << "Couldn't find the file" << "Default.properties" << "\n" << "Please check the file isn't broken!" << endl;
		getchar();
		return;
	}
	else {
		cout << "Open the file \"Default.properties\" successfully!" << endl;
	}
	Prop.load();
	vector<string> vec = Prop.read("DefaultPrimaryMoney");
	
	if (vec.size() != 0) {
		this->money = atof(vec[0].c_str());
	}
	Prop.close();
}
