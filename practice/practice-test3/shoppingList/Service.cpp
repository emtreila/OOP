//
// Created by mela on 28.05.2025.
//

#include "Service.h"

std::vector<Item> Service::getAllService() {
    return this->repo.getAll();
}
