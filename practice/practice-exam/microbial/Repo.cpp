#include "Repo.h"

#include <algorithm>
#include <fstream>
#include <sstream>

Repo::Repo() {
    readFromFileBacterium();
    readFromFileBiologist();
}

void Repo::readFromFileBacterium() {
    std::ifstream file;
    file.open("data_bacteria.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data_bacteria = std::vector<Bacterium>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, species, strsize, diseases;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, species, ';') &&
            std::getline(ss, strsize, ';') &&
            std::getline(ss, diseases, ';')) {
            int size = std::stoi(strsize);


            Bacterium bacterium(name, species, size, diseases);
            this->data_bacteria.push_back(bacterium);
        }
    }

    std::sort(this->data_bacteria.begin(), this->data_bacteria.end(),
              [](Bacterium &a, Bacterium &b) {
                  return a.getName() < b.getName();
              });
}


void Repo::readFromFileBiologist() {
    std::ifstream file;
    file.open("data_biologist.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data_biologists = std::vector<Biologist>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, species;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, species, ';')) {
            Biologist biologist(name, species);
            this->data_biologists.push_back(biologist);
        }
    }
}

const std::vector<Biologist> &Repo::getAllBiologists() const {
    return this->data_biologists;
}

const std::vector<Bacterium> &Repo::getAllBacteria() const {
    return this->data_bacteria;
}

void Repo::addBacteria(const Bacterium &bacterium) {
    this->data_bacteria.push_back(bacterium);
    std::ofstream file("data_bacteria.txt", std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    file << bacterium.getName() << ";"
            << bacterium.getSpecies() << ";"
            << bacterium.getSize() << ";"
            << bacterium.getDiseases() << "\n";
}