#pragma once
#include <vector>
#include "Car.h"
using namespace std;

class Traffic {
	vector <Car> cars;
	int number_of_cars;
	Traffic(int num);
};
