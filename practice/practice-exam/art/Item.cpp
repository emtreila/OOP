#include "Item.h"
#include <sstream>

Item::Item() {
    this->name = "";
    this->category = "";
    this->currentPrice = 0;
    this->offers = std::vector<std::tuple<int, std::string, int>>();
}

Item::Item(const std::string& name, const std::string& category, int currentPrice) {
    this->name = name;
    this->category = category;
    this->currentPrice = currentPrice;
    this->offers = std::vector<std::tuple<int, std::string, int>>();
}

const std::string& Item::getName() const {
    return name;
}

const std::string& Item::getCategory() const {
    return category;
}

int Item::getCurrentPrice() const {
    return currentPrice;
}

const std::vector<std::tuple<int, std::string, int>>& Item::getOffers() const {
    return offers;
}

void Item::setName(const std::string& name) {
    this->name = name;
}

void Item::setCategory(const std::string& category) {
    this->category = category;
}

void Item::setCurrentPrice(int price) {
    this->currentPrice = price;
}

void Item::addOffer(int userId, const std::string& date, int sum) {
    offers.emplace_back(userId, date, sum);
}

std::string Item::toString() const {
    return this->name + " | " + this->category + " | " + std::to_string(this->currentPrice);
}
