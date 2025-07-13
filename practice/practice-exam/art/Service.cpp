//
// Created by mela on 16.06.2025.
//

#include "Service.h"

std::vector<std::string> Service::getCategory() {
    std::vector<std::string> categories;
    for (const auto &item: repo.getItems()) {
        if (std::find(categories.begin(), categories.end(), item.getCategory()) == categories.end()) {
            categories.push_back(item.getCategory());
        }
    }
    return categories;
}

void Service::addItem(const Item &item) {
    repo.addItem(item);
    notify();
}