//
// Created by mela on 28.05.2025.
//

#include "Repo.h"

#include <algorithm>
#include <fstream>
#include <sstream>

Repo::Repo() {
    readFile();
}

void Repo::readFile() {
    std::ifstream file;
    file.open("data.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data = std::vector<Item>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string c, n, q;

        if (std::getline(ss, c, ';') &&
            std::getline(ss, n, ';') &&
            std::getline(ss, q, ';')) {
            std::string category = c;
            std::string name = n;
            int quantity = std::stoi(q);


            Item item(category, name, quantity);
            this->data.push_back(item);
        }
    }
    std::sort(data.begin(), data.end(),
              [](Item &a, Item &b) {
                  if (a.getCategory() == b.getCategory()) {
                      return a.getName() < b.getName();
                  }
                  return a.getCategory() < b.getCategory();
              });
}

std::vector<Item> Repo::getAll() {
    return this->data;
}
