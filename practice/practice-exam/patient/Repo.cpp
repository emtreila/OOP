#include "Repo.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

Repo::Repo() {
    readDoctorsFromFile();
    readPatientsFromFile();
}

void Repo::readDoctorsFromFile() {
    std::ifstream file;
    file.open("data_doctor.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data_doctors = std::vector<Doctor>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, specialization;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, specialization, ';')) {
            Doctor(name, specialization);
            data_doctors.push_back(Doctor(name, specialization));
        }
    }
}

void Repo::readPatientsFromFile() {
    std::ifstream file;
    file.open("data_patient.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data_patients = std::vector<Patient>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, diagnosis, specialization, current_doctor, date;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, diagnosis, ';') &&
            std::getline(ss, specialization, ';') &&
            std::getline(ss, current_doctor, ';') &&
            std::getline(ss, date, ';')) {
            Patient(name, diagnosis, specialization, current_doctor, date);
            this->data_patients.push_back(Patient(name, diagnosis, specialization, current_doctor, date));
        }
    }
}

void Repo::addPatient(const Patient &patient) {
    this->data_patients.push_back(patient);
    std::ofstream file("data_patient.txt", std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    file << patient.getName() << ";"
            << patient.getDiagnosis() << ";"
            << patient.getSpecialization() << ";"
            << patient.getCurrentDoctor() << ";"
            << patient.getDate() << "\n";
}
