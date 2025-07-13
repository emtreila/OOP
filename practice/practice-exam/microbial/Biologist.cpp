#include "Biologist.h"

Biologist::Biologist() {
    this->name = "";
    this->species = "";
}

Biologist::Biologist(const std::string &name, const std::string &species) {
    this->name = name;
    this->species = species;
}

const std::string &Biologist::getName() const {
    return this->name;
}

const std::string &Biologist::getSpecies() const {
    return this->species;
}

void Biologist::setName(const std::string &name) {
    this->name = name;
}

void Biologist::setSpecies(const std::string &species) {
    this->species = species;
}

std::string Biologist::toString() const {
    return this->name + " | " + this->species;
}
