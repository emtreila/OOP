#include "Building.h"
Building::Building() {
    this->address = "";
    this->constructionYear = 2025;
}

Building::Building(const std::string &address, int constructionYear) {
    this->address = address;
    this->constructionYear = constructionYear;
}

std::string Building::getAddress() const {
    return this->address;
}

int Building::getConstructionYear() const {
    return this->constructionYear;
}




