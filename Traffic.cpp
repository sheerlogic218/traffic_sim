#include "Traffic.h"

using namespace std;

vector <Car> cars;
int number_of_cars;

Traffic::Traffic(int num) {
    this->number_of_cars = num;
    for (int i = 0; i < number_of_cars; i++) {
        Car c(i, 0.0, 0.0);
        cars.push_back(c);
    }
}
