//
// Created by mela on 25.05.2025.
//

#include "Car.h"

Car::Car() {
    this->model = "";
    this->name = "";
    this->year = 0;
    this->color = "";
}

Car::Car( const std::string &name, const std::string &model, int year, const std::string &color) {
    this->model = model;
    this->name = name;
    this->year = year;
    this->color = color;
}

const std::string &Car::getModel() const {
    return model;
}
void Car::setModel(const std::string &model) {
    this->model = model;
}
const std::string &Car::getName() const {
    return name;
}
void Car::setName(const std::string &name) {
    this->name = name;
}
int Car::getYear() const {
    return year;
}
void Car::setYear(int year) {
    this->year = year;
}
const std::string &Car::getColor() const {
    return color;
}
void Car::setColor(const std::string &color) {
    this->color = color;
}
std::string Car::toString() const {
    return this->name + " " + this->model;
}
