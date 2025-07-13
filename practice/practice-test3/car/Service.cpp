//
// Created by mela on 25.05.2025.
//

#include "Service.h"

std::vector<Car> Service::getAllService() {
    return this->repo.getAll();
}

std::vector<Car> Service::getCarsByManufacturer(const std::string &manufacturer) {
    /* Retrieves all cars from the repository that match the given manufacturer name.
     * @param manufacturer: The name of the manufacturer to filter cars by.
     * @return A vector of Car objects that match the specified manufacturer.
     */
    std::vector<Car> cars = this->repo.getAll(); // get all cars from the repository
    std::vector<Car> filteredCars; // vector to store cars that match the manufacturer
    for (const auto &car : cars) {
        if (car.getName() == manufacturer) { // check if the car's name matches the manufacturer
            filteredCars.push_back(car); // add the car to the filtered list
        }
    }
    return filteredCars; // return the filtered list of cars
}
