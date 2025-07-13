#include "Service.h"

#include <fstream>
#include <stdexcept>

Service::~Service() {
    for (auto car: this->data) {
        delete car;
    }
}


void Service::addCar(const std::string &bodyStyle, const std::string engineType, int autonomy) {
    Car *car = new Car(bodyStyle);
    this->data.push_back(car);
}

std::vector<Car *> Service::getCarsWithMaxPrice(double maxPrice) {
    std::vector<Car *> result;
    for (auto car: this->data) {
        if (car->computePrice() <= maxPrice) {
            result.push_back(car);
        }
    }
    return result;
}

void Service::writeToFile(const std::string &filename, std::vector<Car *> cars) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    for (auto car: this->data) {
        //file << car->toString()<< "\n";
    }
    file.close();
}

std::vector<Car *> Service::getCars() {
    return this->data;
}