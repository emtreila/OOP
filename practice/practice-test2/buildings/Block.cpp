#include "Block.h"

Block::Block() {
    this->address = "";
    this->constructionYear = 2025;
    this->totalApartments = 0;
    this-> occupiedApartments = 0;
}

Block::Block(const std::string &address, int constructionYear, int totalApartments, int occupiedApartments) {
    this->address = address;
    this->constructionYear = constructionYear;
    this->totalApartments = totalApartments;
    this->occupiedApartments = occupiedApartments;
}

bool Block::mustBeRestored() {
    double apartments80 = this->totalApartments * 0.8;
    double apartments = this->occupiedApartments / this->totalApartments;
    if (2025 - this->constructionYear > 40 &&  apartments > apartments80) {
        return true;
    }
    return false;
}

bool Block::canBeDemolished() {
    double apartments05 = this->totalApartments * 0.05;
    double apartments = this->occupiedApartments / this->totalApartments;
    if ( apartments < apartments05) {
        return true;
    }
    return false;
}

std::string Block::toString() {
    return "Block | Address: " + this->address + " | Construction Year: " + std::to_string(this->constructionYear) +
           " | Total Apartments: " + std::to_string(this->totalApartments) +
           " | Occupied Apartments: " + std::to_string(this->occupiedApartments) +
           " | Must be restored: " + (this->mustBeRestored() ? "Yes" : "No") +
           " | Can be demolished: " + (this->canBeDemolished() ? "Yes" : "No");
}



