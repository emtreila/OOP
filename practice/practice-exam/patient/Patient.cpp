#include "Patient.h"

Patient::Patient() {
    this->name = "";
    this->diagnosis = "";
    this->specialization = "";
    this->current_doctor = "";
    this->date = "";
}

Patient::Patient(const std::string &name, const std::string &diagnosis, const std::string &specialization,
                 const std::string &current_doctor, const std::string &date) {
    this->name = name;
    this->diagnosis = diagnosis;
    this->specialization = specialization;
    this->current_doctor = current_doctor;
    this->date = date;
}

const std::string &Patient::getName() const {
    return this->name;
}

const std::string &Patient::getDiagnosis() const {
    return this->diagnosis;
}

const std::string &Patient::getSpecialization() const {
    return this->specialization;
}

const std::string &Patient::getCurrentDoctor() const {
    return this->current_doctor;
}

const std::string &Patient::getDate() const {
    return this->date;
}

void Patient::setName(const std::string &name) {
    this->name = name;
}

void Patient::setDiagnosis(const std::string &diagnosis) {
    this->diagnosis = diagnosis;
}

void Patient::setSpecialization(const std::string &specialization) {
    this->specialization = specialization;
}

void Patient::setCurrentDoctor(const std::string &current_doctor) {
    this->current_doctor = current_doctor;
}

void Patient::setDate(const std::string &date) {
    this->date = date;
}

std::string Patient::toString() const {
    return this->name + " | " + this->diagnosis + " | " + this->specialization + " | " +
           this->current_doctor + " | " + this->date;
}
