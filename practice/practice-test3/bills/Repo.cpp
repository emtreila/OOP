#include "Repo.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

Repo::Repo() {
    readFromFile();
}

void Repo::readFromFile() {
    std::ifstream file;

    file.open("bills_data.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file!");
    }

    this->data = std::vector<Bills>();
    std::string line{};

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string company, serial, amountStr, isPaidStr;

        if (std::getline(ss, company, ';') &&
            std::getline(ss, serial, ';') &&
            std::getline(ss, amountStr, ';') &&
            std::getline(ss, isPaidStr, ';')) {

            double amount = std::stod(amountStr);
            bool isPaid = (isPaidStr == "true");

            Bills bill{company, serial, amount, isPaid};
            this->data.push_back(bill);
            }
    }

    std::sort(this->data.begin(), this->data.end(),
              [](const Bills &a, const Bills &b) {
                  return a.getCompanyName() < b.getCompanyName();
              });

    file.close();
}

std::vector<Bills> Repo::getData() {
    return this->data;
}