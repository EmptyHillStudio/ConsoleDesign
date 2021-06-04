#include <iostream>
#include <string>
#include "PerlinNoiseCreater.h"
#include "EconomyManager.h"
#include "ProvinceManager.h"
#include "GameProcessManager.h"

using namespace std;

class Main {
private:
	EconomyManager* eManager;
	ProvinceManager* pManager;
	GameProcessManager* gpManager;
public:
	Main() {
		PerlinNoiseCreater pnc(4, 4);//柏林噪声发生器
		eManager = new EconomyManager();
		pManager = new ProvinceManager();
		gpManager = new GameProcessManager(pManager);
	}
	EconomyManager getEconomyManager() { return *(this->eManager); }
	ProvinceManager getProvinceManager() { return *(this->pManager); }
};

int main(){
	Main* ma = new Main();
}

