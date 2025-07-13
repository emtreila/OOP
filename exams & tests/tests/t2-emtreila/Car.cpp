#include "Car.h"

#include "Engine.h"

Car::Car() {
    this->bodyStyle = "";
}

Car::Car(const std::string &bodyStyle) {
    this->bodyStyle = bodyStyle;
}

double Car::computePrice() {
    double price;

    if (this->bodyStyle == "Sedan") {
        price = 8000 + this->engine->getPrice();
    } else if (this->bodyStyle == "Convertible") {
        price = 9000 + this->engine->getPrice();
    }
    return price;
}
