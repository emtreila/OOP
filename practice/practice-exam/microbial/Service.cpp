#include "Service.h"


const std::vector<Bacterium> &Service::getAllBacteriaService() const {
    return this->repo.getAllBacteria();
}

const std::vector<Biologist> &Service::getAllBiologistsService() const {
    return this->repo.getAllBiologists();
}

std::vector<std::string> Service::splitSpecies(const std::string &species) const {
    std::vector<std::string> result;
    std::stringstream ss(species);
    std::string item;

    while (std::getline(ss, item, ',')) {
        item.erase(0, item.find_first_not_of(" \t\r\n"));
        item.erase(item.find_last_not_of(" \t\r\n") + 1);
        result.push_back(item);
    }

    return result;
}


std::vector<Bacterium> Service::getBacteriaByBiologistSpecies(const std::string &biologistName) const {
    std::vector<Biologist> biologists = this->repo.getAllBiologists();
    std::vector<Bacterium> bacteria = this->repo.getAllBacteria();
    std::vector<Bacterium> result;
    for (const auto &biologist: biologists) {
        std::vector<std::string> speciesList = splitSpecies(biologist.getSpecies());
        for (const auto &bacterium: bacteria) {
            auto it = std::find(speciesList.begin(), speciesList.end(), bacterium.getSpecies());
            if (it != speciesList.end() && biologist.getName() == biologistName) {
                result.push_back(bacterium);
            }
        }
    }
    std::sort(result.begin(), result.end(),
              [](Bacterium &a, Bacterium &b) {
                  return a.getName() < b.getName();
              });

    return result;
}

void Service::addBacteria(const Bacterium &bacterium) {
    this->repo.addBacteria(bacterium);
}