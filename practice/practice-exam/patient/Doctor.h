#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>


class Doctor {
private:
    std::string name;
    std::string specialization;

public:
    Doctor();

    explicit Doctor(const std::string &name, const std::string &specialization);

    const std::string &getName() const;

    const std::string &getSpecialization() const;

    void setName(const std::string &name);

    void setSpecialization(const std::string &specialization);
};


#endif //DOCTOR_H
