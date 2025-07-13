#include "Repo.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

Repo::Repo() {
    readFromFile();
}

void Repo::readFromFile() {
    std::ifstream file;
    file.open("data.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data = std::vector<Task>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string des, dur, p;

        if (std::getline(ss, des, ';') &&
            std::getline(ss, dur, ';') &&
            std::getline(ss, p, ';')) {
            std::string description = des;
            int duration = std::stoi(dur);
            int priority = std::stoi(p);


            Task task(description, duration, priority);
            this->data.push_back(task);
        }
    }
}

std::vector<Task> Repo::getAll() {
    return this->data;
}

