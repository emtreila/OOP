#include "NeonatalUnit.h"

NeonatalUnit::NeonatalUnit() {
    this->hospitalName = "";
    this->numberOfDoctors = 0;
    this->numberOfMothers = 0;
    this->numberOfNewborns = 0;
    this->averageGrade = 0.0;
}

NeonatalUnit::NeonatalUnit(const std::string &hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborns, double averageGrade) : HospitalDepartment(hospitalName, numberOfDoctors) {
    this->hospitalName = hospitalName;
    this->numberOfDoctors = numberOfDoctors;
    this->numberOfMothers = numberOfMothers;
    this->numberOfNewborns = numberOfNewborns;
    this->averageGrade = averageGrade;
}

bool NeonatalUnit::isEfficient() {
    return (this->averageGrade > 8.5 && this->numberOfNewborns >= this->numberOfMothers);
}

std::string NeonatalUnit::toString() {
    return "Neonatal Unit | Hospital Name: " + this->hospitalName + " | Number of Doctors: " + std::to_string(this->numberOfDoctors) +
           " | Number of Mothers: " + std::to_string(this->numberOfMothers) + " | Number of Newborns: " + std::to_string(this->numberOfNewborns) +
           " | Average Grade: " + std::to_string(this->averageGrade) + "\n";
}


