#include "Repo.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

Repo::Repo() {
    readFile();
}

void Repo::readFile() {
    std::ifstream file; 
    file.open("data.txt"); 

    if (!file.is_open()) {
        
        throw std::runtime_error("Couldn't open file!");
    }
    this->data = std::vector<Weather>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string start,end,temp, precip, desc;

        if (std::getline(ss, start, ';') &&
            std::getline(ss, end, ';') &&
            std::getline(ss, temp, ';') &&
            std::getline(ss, precip, ';') &&
            std::getline(ss, desc, ';')) {
            int startInt = std::stoi(start);
            int endInt = std::stoi(end);
            int temperature = std::stoi(temp);
            int precipitation = std::stoi(precip);
            std::string description = desc;


            Weather weather(startInt, endInt, temperature, precipitation, description);
            this->data.push_back(weather);
        }
    }
}

std::vector<Weather> Repo::getAll() {
    return this->data;
}
