#include "Service.h"

const std::vector<Astronomer> &Service::getAllAstronomers() const {
    return this->repo.getAllAstronomers();
}

const std::vector<Star> &Service::getAllStars() const {
    return this->repo.getAllStars();
}

std::vector<Star> Service::getAllStudiedStars(const std::string &constellationName) const {
    std::vector<Star> studiedStars;
    for (const auto &star: this->repo.getAllStars()) {
        if (star.getConstellation() == constellationName) {
            studiedStars.push_back(star);
        }
    }
    return studiedStars;
}

void Service::addStar(const Star &star) {
    this->repo.addStar(star);
}

#include <fstream>
#include <algorithm>
