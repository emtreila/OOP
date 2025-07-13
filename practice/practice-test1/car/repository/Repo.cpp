#include "Repo.h"

Repo::Repo() = default;

Repo::~Repo() = default;

bool Repo::addCar(const Car &car) {
    /**
     * Add a new car
     * @param car - the car to be added
     * return true, if the car was added, false otherwise
     */
    try {
        Car found = this->cars.find(car);
    } catch ( std::exception&) {
        this->cars.add(car);
        return true;
    }
    return false;
}

Car Repo::findCar(const std::string &model, int year) {
    Car mock = Car();
    mock.setModel(model);
    mock.setYear(year);
    Car found = this->cars.find(mock);
    return found;
}


bool Repo::removeCar(const std::string &model, int year) {
    try {
        Car found = findCar(model, year);
        this->cars.remove(found);
        return true;
    } catch (std::exception&) {
        return false;
    }
}


const DynamicVector<Car> &Repo::getAll() {
    return this->cars;
}

Car Repo::getCar(int index) {
    return this->cars.getElement(index);
}



