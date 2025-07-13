#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Doctor.h"
#include "Patient.h"


class Repo {
private:
    std::vector<Doctor> data_doctors;
    std::vector<Patient> data_patients;

public:
    Repo();

    ~Repo() = default;

    void readDoctorsFromFile();

    void readPatientsFromFile();

    const std::vector<Doctor>& getDoctors() const {
        return data_doctors;
    }

    const std::vector<Patient>& getPatients() const {
        return data_patients;
    }

    void addPatient(const Patient &patient);
};


#endif //REPO_H
