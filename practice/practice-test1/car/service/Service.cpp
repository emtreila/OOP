#include "Service.h"

bool Service::addCarService(const std::string &name, const std::string &model, int year, const std::string &color) {
    /**
     * Add a new car
     * @param name: the name of the car
     * @param model: the model of the car
     * @param year: the year of the car
     * @param color: the color of the car
     * return: true if the car was added, false otherwise
     */
    Car newCar = Car(name, model, year, color);
    return this->repo.addCar(newCar);
}

bool Service::removeCarService(const std::string &model, int year) {
    return this->repo.removeCar(model, year);
}

DynamicVector<Car> Service::getAllService() const {
    const DynamicVector<Car> &cars = this->repo.getAll();
    DynamicVector<Car> sorted = DynamicVector<Car>(cars.sizeOfVector());

    for (int i = 0; i < cars.sizeOfVector(); i++) {
        sorted.add(cars.getElement(i));
    }

    for (int i = 0; i < sorted.sizeOfVector(); i++) {
        for (int j = i + 1; j < sorted.sizeOfVector(); j++) {
            if (sorted.getElement(i).getName() > sorted.getElement(j).getName() && sorted.getElement(i).getModel() >
                sorted.getElement(j).getModel()) {
                Car aux = sorted.getElement(i);
                sorted.setElement(i, sorted.getElement(j));
                sorted.setElement(j, aux);
            }
        }
    }
    return sorted;
}

Car Service::getCarService(int index) const {
    return this->repo.getCar(index);
}

DynamicVector<Car> Service::getVintageCarsService() {
    /**
     * Get all the vintage cars
     * return: a vector with all the vintage cars
     */
    DynamicVector<Car> vintageCars = DynamicVector<Car>();
    const DynamicVector<Car> &cars = this->repo.getAll();
    for (int i = 0; i < cars.sizeOfVector(); i++) {
        if (cars.getElement(i).getYear() < 1980) {
            vintageCars.add(cars.getElement(i));
        }
    }
    // sort the vintage cars by color
    for (int i = 0; i < vintageCars.sizeOfVector(); i++) {
        for (int j = i + 1; j < vintageCars.sizeOfVector(); j++) {
            if (vintageCars.getElement(i).getColor() > vintageCars.getElement(j).getColor()) {
                Car aux = vintageCars.getElement(i);
                vintageCars.setElement(i, vintageCars.getElement(j));
                vintageCars.setElement(j, aux);
            }
        }
    }

    return vintageCars;
}
