#ifndef HOSPITALDEPARTMENT_H
#define HOSPITALDEPARTMENT_H
#include <string>


class HospitalDepartment {
protected:
    std::string hospitalName;
    int numberOfDoctors;
public:
    HospitalDepartment();

    explicit HospitalDepartment(const std::string &hospitalName, int numberOfDoctors);

    virtual ~HospitalDepartment() = default;

    std::string getHospitalName();

    virtual bool isEfficient() = 0;

    virtual std::string toString();
};


#endif //HOSPITALDEPARTMENT_H
