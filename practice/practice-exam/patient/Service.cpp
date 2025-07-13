#include "Service.h"

#include <algorithm>

const std::vector<Doctor> &Service::getDoctors() const {
    return this->repo.getDoctors();
}

const std::vector<Patient> &Service::getPatients() const {
    return this->repo.getPatients();
}

std::vector<Patient> Service::getPatientsBySpecialization(const std::string &doctorSpecialization) const {
    std::vector<Patient> result;
    for (const auto &patient: repo.getPatients()) {
        if (patient.getSpecialization() == doctorSpecialization || patient.getDiagnosis() == "undiagnosed") {
            result.push_back(patient);
        }
    }

    sort(result.begin(), result.end(),
         [](const Patient &a, const Patient &b) {
             return a.getDate() < b.getDate();
         });

    return result;
}

void Service::addPatient(const Patient &patient) {
    this->repo.addPatient(patient);
    this->notify();
}
