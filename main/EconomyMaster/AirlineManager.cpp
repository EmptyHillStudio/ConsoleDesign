#include "AirlineManager.h"

using namespace std;

AirlineManager::AirlineManager() {
	this->AirlineNum = 0;
	this->Airlines = new map<int, Airline>;
}

//void AirlineManager::create() {
	
//}