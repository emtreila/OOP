//
// Created by mela on 28.05.2025.
//

#include "Vegetable.h"

Vegetable::Vegetable() {
    this->family = "";
    this->name = "";
    this->parts = "";
}

Vegetable::Vegetable(const std::string &family, const std::string &name, const std::string &parts) {
    this->family = family;
    this->name = name;
    this->parts = parts;
}

std::string Vegetable::getFamily() {
    return this->family;
}

std::string Vegetable::getName() {
    return this->name;
}

std::string Vegetable::getParts() {
    return this->parts;
}
