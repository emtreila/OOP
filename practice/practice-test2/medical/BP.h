#ifndef BP_H
#define BP_H
#include "MedicalAnalysis.h"


class BP : virtual public MedicalAnalysis {
private:
    int systolicValue;

    int diastolicValue;

public:
    BP();

    explicit BP(const std::string &date, int systolicValue, int diastolicValue);

    ~BP() override = default;

    bool isResultOk() override;

    std::string toString() override;
};


#endif //BP_H
