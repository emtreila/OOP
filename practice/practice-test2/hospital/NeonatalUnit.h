#ifndef NEONATALUNIT_H
#define NEONATALUNIT_H
#include <string>

#include "HospitalDepartment.h"


class NeonatalUnit : virtual  public  HospitalDepartment{
private:
    int numberOfMothers;
    int numberOfNewborns;
    double averageGrade;
public:
    NeonatalUnit();

    NeonatalUnit(const std::string &hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborns, double averageGrade);

    ~NeonatalUnit() override = default;

    bool isEfficient() override;

    std::string toString() override;
};


#endif //NEONATALUNIT_H
