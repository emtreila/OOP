#include "House.h"

House::House() {
    this->address = "";
    this->constructionYear = 2025;
    this->type = "";
    this->isHistorical = false;
}

House::House(const std::string &address, int constructionYear, const std::string &type, bool isHistorical) : Building(address, constructionYear) {
    this->address = address;
    this->constructionYear = constructionYear;
    this->type = type;
    this->isHistorical = isHistorical;
}

bool House::mustBeRestored() {
    if (2025 - this->constructionYear > 100) {
        return true;
    }
    return false;
}

bool House::canBeDemolished() {
    if (this->isHistorical) {
        return false;
    }
    return true;
}

std::string House::toString() {
    return "House | Address: " + this->address + "| Construction Year: " + std::to_string(this->constructionYear) + "| Type: " + this->type + "| Is Historical: " + (this->isHistorical ? "Yes" : "No");
}
