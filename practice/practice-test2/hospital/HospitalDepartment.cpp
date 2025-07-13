#include "HospitalDepartment.h"

HospitalDepartment::HospitalDepartment() {
    this->hospitalName = "";
    this->numberOfDoctors = 0;
}

HospitalDepartment::HospitalDepartment(const std::string &hospitalName, int numberOfDoctors) {
    this->hospitalName = hospitalName;
    this->numberOfDoctors = numberOfDoctors;
}

std::string HospitalDepartment::toString() {
    return "Hospital Name: " + this->hospitalName + "\n" +
           " | Number of Doctors: " + std::to_string(this->numberOfDoctors) + "\n";
}

std::string HospitalDepartment::getHospitalName() {
    return this->hospitalName;
}


