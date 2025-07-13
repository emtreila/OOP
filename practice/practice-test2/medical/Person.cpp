#include "Person.h"

#include <fstream>
#include <iostream>
#include <ostream>

Person::Person() {
    this->name = "";
}

Person::~Person() {
    delete []&this->data;
}

Person::Person(const std::string &name) {
    this->name = name;
}

void Person::addAnalysis(MedicalAnalysis *a) {
    this->data.push_back(a);
}

std::vector<MedicalAnalysis *> Person::getAllAnalyses() {
    return this->data;
}

std::vector<MedicalAnalysis *> Person::getAnalysisByMonth(int month) {
    std::vector<MedicalAnalysis *> result;
    for (auto & analyse : this->data) {
        int m = std::stoi(analyse->getDate().substr(5, 2));
        if (m == month) {
            result.push_back(analyse);
        }
    }
    return result;
}

bool Person::isIll(int month) {
    std::vector<MedicalAnalysis*> analyses = this->getAnalysisByMonth(month);
    bool ill = false;
    for (auto & analyse : analyses) {
        if (!analyse->isResultOk()) {
            ill = true;
            break;
        }
    }
    return ill;
}

std::vector<MedicalAnalysis*> Person::getAnalysesBetweenDates(const std::string &date1, const std::string &date2) {
    std::vector<MedicalAnalysis*> result;
    for (auto & analyse : this->data) {
        if (analyse->getDate() >= date1 && analyse->getDate() <= date2) {
            result.push_back(analyse);
        }
    }
    return result;
}

void Person::writeToFile(const std::string &filename, const std::string &date1, const std::string &date2) {
    std::vector<MedicalAnalysis *> analyses = this->getAnalysesBetweenDates(date1, date2);


    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    for (auto & analyse : analyses) {
        file << analyse->toString() << std::endl;
    }

    std::vector<int> months;
    for (auto & analyse : analyses) {
        bool exists = false;
        int m = std::stoi(analyse->getDate().substr(5, 2));
        for (auto & month : months) {
            if (month == m) {
                exists = true;
            }
        }
        if (!exists) {
            months.push_back(m);
        }
    }

    for (auto & month : months) {
        bool ill = this->isIll(month);
        if (ill) {
            file << "Person is ill in month " << month << std::endl;
        } else {
            file << "Person is healthy in month " << month << std::endl;
        }
    }
    file.close();

}







