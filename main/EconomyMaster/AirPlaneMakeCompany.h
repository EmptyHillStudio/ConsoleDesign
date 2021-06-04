#pragma once

#include <string>
#include <map>

#include "AirPlane.h"
#include "Company.h"

using namespace std;

class AirPlaneMakeCompany : Company{
private:
	map<string, AirPlane> Made_Plane;
public:

};

