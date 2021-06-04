#include "AirPlaneManager.h"

AirPlaneManager::AirPlaneManager() {
	CsvReader cReader("Planes.csv");
	for (set<vector<string>>::iterator iter = cReader.getReader().begin();iter != cReader.getReader().end();iter++) {

	}
}