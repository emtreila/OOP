#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H
#include "Appliance.h"


class Refrigerator : virtual public Appliance{
private:
    std::string electricityUsageClass;
    bool hasFreezer;
public:
    Refrigerator();

    Refrigerator(const std::string &id, const std::string &electricityUsageClass, bool hasFreezer);

    ~Refrigerator() override = default;

    double consumedElectricity() override;

    std::string toString() override;
};


#endif //REFRIGERATOR_H
