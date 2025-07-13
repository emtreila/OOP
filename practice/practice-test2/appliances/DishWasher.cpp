#include "DishWasher.h"

DishWasher::DishWasher() {
    this->id = "0";
    this->consumedElectricityForOneHour = 0;
}

DishWasher::DishWasher(const std::string &id, double consumedElectricityForOneHour) {
    this->id = id;
    this->consumedElectricityForOneHour = consumedElectricityForOneHour;
}

double DishWasher::consumedElectricity() {
    return this->consumedElectricityForOneHour * 20;
}

std::string DishWasher::toString() {
    return "DishWasher | Id: " + this->id + ", Consumed electricity for one hour: " + std::to_string(this->consumedElectricityForOneHour);
}
