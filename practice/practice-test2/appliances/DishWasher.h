#ifndef DISHWASHER_H
#define DISHWASHER_H
#include "Appliance.h"


class DishWasher : virtual public Appliance {
private:
    double consumedElectricityForOneHour;
public:
    DishWasher();

    explicit DishWasher(const std::string &id, double consumedElectricityForOneHour);

    ~DishWasher() override = default;

    double consumedElectricity() override;

    std::string toString() override;
};


#endif //DISHWASHER_H
