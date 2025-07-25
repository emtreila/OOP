//
// Created by mela on 28.05.2025.
//

#include "Item.h"

Item::Item() {
    this->category = "";
    this->name = "";
    this->quantity = 0;
}

Item::Item(std::string category, std::string name, int quantity) {
    this->category = category;
    this->name = name;
    this->quantity = quantity;
}


std::string Item::getCategory() {
    return this->category;
}

std::string Item::getName() {
    return this->name;
}

int Item::getQuantity() {
    return this->quantity;
}

std::string Item::toString() {
    return this->category + " | " + this->name + " | " + std::to_string(this->quantity);
}
