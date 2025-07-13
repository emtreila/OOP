#include "Controller.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>

Controller::~Controller() {
    delete []&this->data;
}

void Controller::addBuilding(Building *building) {
    /*
     * Adds a building to the list of buildings.
     * @param building: The building to add.
     */
    this->data.push_back(building); // Add the building to the list
}

std::vector<Building *> Controller::getAllBuildings() {
    /*
     * Returns all buildings in the list, sorted by construction year.
     * @return: A vector of pointers to all buildings.
     */
    std::sort(this->data.begin(), this->data.end(), [](Building *a, Building *b) { // Lambda function to sort buildings by construction year
        return a->getConstructionYear() < b->getConstructionYear(); // Sort by construction year
    });
    return this->data; // Return the sorted list of buildings
}

std::vector<Building *> Controller::getAllBuildingsToBeRestored() const {
    std::vector<Building *> buildingsToBeRestored;
    for (auto building : this->data) {
        if (building->mustBeRestored()) {
            buildingsToBeRestored.push_back(building);
        }
    }
    return buildingsToBeRestored;
}

std::vector<Building *> Controller::getAllBuildingsToBeDemolished() const {
    std::vector<Building *> buildingsToBeDemolished;
    for (auto building : this->data) {
        if (building->canBeDemolished()) {
            buildingsToBeDemolished.push_back(building);
        }
    }
    return buildingsToBeDemolished;
}

void Controller::writeToFile(const std::string &filename, std::vector<Building *> buildings) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    for (auto building : buildings) {
        file << building->toString() << "\n";
    }
    file.close();
}


