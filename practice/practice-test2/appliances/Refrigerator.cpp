#include "Refrigerator.h"

Refrigerator::Refrigerator() {
    this->id = "0";
    this->electricityUsageClass = "";
    this->hasFreezer = false;
}

Refrigerator::Refrigerator(const std::string &id, const std::string &electricityUsageClass, bool hasFreezer) {
    this->id = id;
    this->electricityUsageClass = electricityUsageClass;
    this->hasFreezer = hasFreezer;
}

double Refrigerator::consumedElectricity() {
    int x = 1;
    if (this->electricityUsageClass == "A") {
        x = 3;
    }
    else if (this->electricityUsageClass == "A++") {
        x = 2;
    }
    if (this->hasFreezer) {
        return x * 30 + 20;
    }
    else {
        return x * 30;
    }
}

std::string Refrigerator::toString() {
    return "Refrigerator | Id: " + this->id + ", Electricity Usage Class: " + this->electricityUsageClass + ", Has Freezer: " + (this->hasFreezer ? "Yes" : "No");
}
