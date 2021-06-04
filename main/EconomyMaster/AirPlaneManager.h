#pragma once
#include "CsvReader.h"
#include "AirPlaneMakeCompany.h"
#include "AirPlane.h"


#include <map>
#include <set>
#include <vector>

class AirPlaneManager
{
private:
	map<string, AirPlaneMakeCompany> Companies;
	map<string, AirPlane> LoadedAirplanes;
public:
	AirPlaneManager();
};

