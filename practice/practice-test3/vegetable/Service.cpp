//
// Created by mela on 28.05.2025.
//

#include "Service.h"

std::vector<Vegetable> Service::getAllService() {
    return this->repo.getAll();
}

Vegetable Service::getVegetableByName(const std::string &name) {
    /*
     * Returns a Vegetable object from the repository that matches the given name.
     * @param name: The name of the vegetable to search for.
     * @return: A Vegetable object if found, otherwise an empty Vegetable object.
     */
    Vegetable veg;
    auto veggies = this->repo.getAll(); // Get all vegetables from the repository
    for (auto v : veggies) { // Iterate through each vegetable
        if (v.getName() == name) { // Check if the name matches
            veg = v; // If a match is found, assign it to veg
            break;
        }
    }
    return veg;
}
