#include "Car.h"

Car::Car() {
    this->name = "";
    this->model = "";
    this->year = 0;
    this->color = "";
}

Car::Car(const std::string &name, const std::string &model, int year, const std::string &color) {
    this->name = name;
    this->model = model;
    this->year = year;
    this->color = color;
}

Car::~Car() = default;

Car::Car(const Car &car) {
    this->name = car.name;
    this->model = car.model;
    this->year = car.year;
    this->color = car.color;
}

const std::string &Car::getName() const {
    return this->name;
}

const std::string &Car::getModel() const {
    return this->model;
}

int Car::getYear() const {
    return this->year;
}

const std::string &Car::getColor() const {
    return this->color;
}

void Car::setName(const std::string &newName) {
    this->name = newName;
}

void Car::setModel(const std::string &newModel) {
    this->model = newModel;
}

void Car::setYear(int newYear) {
    this->year = newYear;
}

void Car::setColor(const std::string &newColor) {
    this->color = newColor;
}

bool Car::operator==(const Car &car) const {
    return (this->model.compare(car.model) == 0 && this->year == car.year);
}
