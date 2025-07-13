#include "Doctor.h"

Doctor::Doctor() {
    this->name = "";
    this->specialization = "";
}

Doctor::Doctor(const std::string &name, const std::string &specialization) {
    this->name = name;
    this->specialization = specialization;
}

const std::string &Doctor::getName() const {
    return this->name;
}

const std::string &Doctor::getSpecialization() const {
    return this->specialization;
}

void Doctor::setName(const std::string &name) {
    this->name = name;
}

void Doctor::setSpecialization(const std::string &specialization) {
    this->specialization = specialization;
}

