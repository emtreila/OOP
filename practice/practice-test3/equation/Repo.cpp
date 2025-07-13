//
// Created by mela on 24.05.2025.
//

#include "Repo.h"

#include <fstream>
#include <sstream>

Repo::Repo() {
    readFile();
}

std::vector<Equation> Repo::getAll() {
    return this->data;
}

void Repo::readFile() {
    std::ifstream file;
    file.open("eq_data.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data = std::vector<Equation>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string astr, bstr, cstr;

        if (std::getline(ss, astr, ',') &&
            std::getline(ss, bstr, ',') &&
            std::getline(ss, cstr, ',')) {
            double a = std::stod(astr);
            double b = std::stod(bstr);
            double c = std::stod(cstr);


            Equation eq(a, b, c);
            this->data.push_back(eq);
        }
    }
}

void Repo::add(const Equation &eq) {
    this->data.push_back(eq);
}