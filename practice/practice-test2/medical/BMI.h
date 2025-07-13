#ifndef BMI_H
#define BMI_H
#include "MedicalAnalysis.h"


class BMI : virtual public MedicalAnalysis{
private:
    double value;
public:
    BMI();

    explicit BMI(const std::string &date,double value);

    ~BMI() override = default;

    bool isResultOk() override;

    std::string toString() override;
};


#endif //BMI_H
