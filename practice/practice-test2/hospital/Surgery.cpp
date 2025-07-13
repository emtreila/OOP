#include "Surgery.h"

Surgery::Surgery() {
    this->hospitalName = "";
    this->numberOfDoctors = 0;
    this->numberOfPatients = 0;
}

Surgery::Surgery(const std::string &hospitalName, int numberOfDoctors, int numberOfPatients) : HospitalDepartment(hospitalName, numberOfDoctors) {
    this->hospitalName = hospitalName;
    this->numberOfDoctors = numberOfDoctors;
    this->numberOfPatients = numberOfPatients;
}

bool Surgery::isEfficient() {
    return numberOfPatients / numberOfDoctors >= 2;
}

std::string Surgery::toString() {
    return "Surgery | Hospital Name: " + this->hospitalName + " | Number of Doctors: " + std::to_string(this->numberOfDoctors) +
           " | Number of Patients: " + std::to_string(this->numberOfPatients) + " | Efficiency: " +
           (isEfficient() ? "Efficient" : "Not Efficient");
}

