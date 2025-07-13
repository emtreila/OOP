#include "Bacterium.h"

Bacterium::Bacterium() {
    this->name = "";
    this->species = "";
    this->size = 0;
    this->diseases = "";
}

Bacterium::Bacterium(const std::string &name, const std::string &species, int size, const std::string &diseases) {
    this->name = name;
    this->species = species;
    this->size = size;
    this->diseases = diseases;
}

const std::string &Bacterium::getName() const {
    return this->name;
}

const std::string &Bacterium::getSpecies() const {
    return this->species;
}

int Bacterium::getSize() const {
    return this->size;
}

const std::string &Bacterium::getDiseases() const {
    return this->diseases;
}

void Bacterium::setName(const std::string &name) {
    this->name = name;
}

void Bacterium::setSpecies(const std::string &species) {
    this->species = species;
}

void Bacterium::setSize(int size) {
    this->size = size;
}

void Bacterium::setDiseases(const std::string &diseases) {
    this->diseases = diseases;
}

std::string Bacterium::toString() const {
    return this->name + " | " + this->species + " | " + std::to_string(this->size) + " | " + this->diseases;
}
