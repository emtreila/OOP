//
// Created by mela on 25.05.2025.
//

#include "Repo.h"

#include <algorithm>
#include <fstream>
#include <sstream>

Repo::Repo() {
    readFile();
}

std::vector<Car> Repo::getAll() {
    return this->data;
}

void Repo::readFile() {
    std::ifstream file;
    file.open("car_data.txt");

    if (!file.is_open()) {
        std::runtime_error("Could not open file car_data.txt");
    }
    this->data = std::vector<Car>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string namestr, modelstr,colostr, yearstr;

        if (std::getline(ss, namestr, ';') &&
            std::getline(ss, modelstr, ';') &&
             std::getline(ss, yearstr, ';') &&
              std::getline(ss, colostr, ';')){
            std::string name = namestr;
            std::string model = modelstr;
            std::string color = colostr;
            int year = std::stoi(yearstr);


            Car car(name, model, year, color );
            this->data.push_back(car);
            }
    }

    std::sort(this->data.begin(), this->data.end(),
              [](const Car &a, const Car &b) {
                  return a.getName() < b.getName();
              });

    file.close();
}



