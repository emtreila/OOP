#ifndef SERVICE_H
#define SERVICE_H
#include "Observable.h"
#include "Repo.h"


class Service : public Observable{
private:
    Repo &repo;

public:
    Service(Repo &repo) : repo(repo) {
    }

    ~Service() = default;

    const std::vector<Doctor> &getDoctors() const;

    const std::vector<Patient> &getPatients() const;

    std::vector<Patient> getPatientsBySpecialization(const std::string &doctorSpecialization ) const;

    void addPatient(const Patient &patient);
};


#endif //SERVICE_H
