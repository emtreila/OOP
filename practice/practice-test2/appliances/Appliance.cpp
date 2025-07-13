#include "Appliance.h"

Appliance::Appliance() {
    this->id = "0";
}

Appliance::Appliance(const std::string &id) {
    this->id = id;
}

std::string Appliance::getID() const {
    return this->id;
}
