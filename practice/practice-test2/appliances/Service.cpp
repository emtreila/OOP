#include "Service.h"

#include <fstream>
#include <iostream>
#include <ostream>
#include<algorithm>

Service::~Service() {
    delete []&this->data;
}


void Service::addAppliance(Appliance *a) {
    this->data.push_back(a);
}

std::vector<Appliance *> Service::getAllAppliances() const {
    return this->data;
}

std::vector<Appliance *> Service::getAllWithConsumedElectricityLessThan(double maxElectricity) {
    this->dataWithConsumedElectricityLessThan.clear();
    for (auto appliance : this->data) {
        if (appliance->consumedElectricity() > maxElectricity) {
            this->dataWithConsumedElectricityLessThan.push_back(appliance);
        }
    }

    std::sort(this->dataWithConsumedElectricityLessThan.begin(), this->dataWithConsumedElectricityLessThan.end(),[](Appliance *a, Appliance *b) {
        return a->getID() < b->getID();
    });

    return this->dataWithConsumedElectricityLessThan;
}

void Service::writeToFile(const std::string &filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    for (const auto appliance : this->dataWithConsumedElectricityLessThan) {
        file << appliance->toString() << std::endl;
    }
    file.close();
}

