#include "Controller.h"
# include<algorithm>
#include <fstream>
#include <stdexcept>

Controller::~Controller() {
    delete []&this->data;
}

void Controller::addDepartment(HospitalDepartment *department) {
    this->data.push_back(department);
}

std::vector<HospitalDepartment *> Controller::getAllDepartments() {
    std::vector<HospitalDepartment *> sortedDepartments = this->data;
    std::sort(sortedDepartments.begin(), sortedDepartments.end(),
              [](HospitalDepartment *a, HospitalDepartment *b) {
                  return a->getHospitalName() < b->getHospitalName();
              });
    return sortedDepartments;
}

std::vector<HospitalDepartment *> Controller::getAllEfficientDepartments() {
    std::vector<HospitalDepartment *> efficientDepartments;
    for (auto department: this->data) {
        if (department->isEfficient()) {
            efficientDepartments.push_back(department);
        }
    }
    return efficientDepartments;
}

void Controller::writeToFile(const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    for (auto department: this->data) {
        file << department->toString()<< "\n";
    }
    file.close();
}
