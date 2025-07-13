#include "Astronomer.h"

Astronomer::Astronomer() {
    this->name = "";
    this->constelation = "";
}

Astronomer::Astronomer(std::string name, std::string constelation) {
    this->name = name;
    this->constelation = constelation;
}

std::string Astronomer::getName() const {
    return this->name;
}

std::string Astronomer::getConstelation() const {
    return this->constelation;
}

void Astronomer::setName(const std::string &name) {
    this->name = name;
}

void Astronomer::setConstelation(const std::string &constelation) {
    this->constelation = constelation;
}
