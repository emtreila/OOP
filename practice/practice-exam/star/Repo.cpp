#include "Repo.h"

#include <algorithm>
#include <fstream>
#include <sstream>

Repo::Repo() {
    readAstronomersFromFile();
    readStarsFromFile();
}

void Repo::readAstronomersFromFile() {
    std::ifstream file;
    file.open("data_astronomer.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data_astronomers = std::vector<Astronomer>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, constellation;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, constellation, ';')) {
            Astronomer astronomer(name, constellation);
            this->data_astronomers.push_back(astronomer);
        }
    }
}

void Repo::readStarsFromFile() {
    std::ifstream file;
    file.open("data_star.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data_stars = std::vector<Star>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, constellation, RAstr, Decstr, diameterstr;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, constellation, ';') &&
            std::getline(ss, RAstr, ';') &&
            std::getline(ss, Decstr, ';') &&
            std::getline(ss, diameterstr, ';')) {
            int RA = std::stoi(RAstr);
            int Dec = std::stoi(Decstr);
            double diameter = std::stod(diameterstr);
            Star star(name, constellation, RA, Dec, diameter);
            this->data_stars.push_back(star);
        }
    }

    std::sort(data_stars.begin(), data_stars.end(),
              [](Star &a, Star &b) {
                  return a.getConstellation() < b.getConstellation();
              });
}

const std::vector<Astronomer> &Repo::getAllAstronomers() const {
    return this->data_astronomers;
}

const std::vector<Star> &Repo::getAllStars() const {
    return this->data_stars;
}

void Repo::addStar(const Star &star) {
    this->data_stars.push_back(star);

    std::ofstream file("data_star.txt", std::ios::app);
    if (file.is_open()) {
        file << star.getName() << ";"
             << star.getConstellation() << ";"
             << star.getRA() << ";"
             << star.getDec() << ";"
             << star.getDiameter() << ";\n";
        file.close();
    } else {
        throw std::runtime_error("Couldn't open file to write!");
    }

    std::sort(data_stars.begin(), data_stars.end(), [](const Star &a, const Star &b) {
        if (a.getConstellation() == b.getConstellation())
            return a.getDiameter() < b.getDiameter();
        return a.getConstellation() < b.getConstellation();
    });
    std::ofstream out("sorted_stars.txt");
    if (!out.is_open())
        throw std::runtime_error("Couldn't open output file!");

    for (const auto &star : this->data_stars) {
        out << star.getName() << ";"
            << star.getConstellation() << ";"
            << star.getRA() << ";"
            << star.getDec() << ";"
            << star.getDiameter() << "\n";
    }
}