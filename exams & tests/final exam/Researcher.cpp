#include "Researcher.h"

Researcher::Researcher() {
    this->name = "";
    this->position = "";
}

Researcher::Researcher(const std::string &name, const std::string &position){
    this->name = name;
    this->position = position;
}

const std::string &Researcher::getName() const {
    return this->name;
}

const std::string &Researcher::getPosition() const {
    return this->position;
}

void Researcher::setName(const std::string &name) {
    this->name = name;
}

void Researcher::setPosition(const std::string &position) {
    this->position = position;
}

std::string Researcher::toString() const {
    return this->name + " | " + this->position;
}

