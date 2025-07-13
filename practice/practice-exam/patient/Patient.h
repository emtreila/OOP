#ifndef PATIENT_H
#define PATIENT_H
#include <string>


class Patient {
private:
    std::string name, diagnosis, specialization, current_doctor, date;

public:
    Patient();

    explicit Patient(const std::string &name, const std::string &diagnosis, const std::string &specialization,
                     const std::string &current_doctor, const std::string &date);

    const std::string &getName() const;

    const std::string &getDiagnosis() const;

    const std::string &getSpecialization() const;

    const std::string &getCurrentDoctor() const;

    const std::string &getDate() const;

    void setName(const std::string &name);

    void setDiagnosis(const std::string &diagnosis);

    void setSpecialization(const std::string &specialization);

    void setCurrentDoctor(const std::string &current_doctor);

    void setDate(const std::string &date);

    std::string toString() const;
};


#endif //PATIENT_H
