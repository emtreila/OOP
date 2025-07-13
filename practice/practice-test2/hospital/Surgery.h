#ifndef SURGERY_H
#define SURGERY_H
#include "HospitalDepartment.h"


class Surgery : virtual public HospitalDepartment {
private:
    int numberOfPatients;

public:
    Surgery();

    explicit Surgery(const std::string &hospitalName, int numberOfDoctors, int numberOfPatients);

    ~Surgery() override = default;

    bool isEfficient() override;

    std::string toString() override;
};


#endif //SURGERY_H
