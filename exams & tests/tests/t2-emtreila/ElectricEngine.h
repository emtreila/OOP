#ifndef ELECTRICENGINE_H
#define ELECTRICENGINE_H
#include "Engine.h"


class ElectricEngine : public virtual Engine{
private:
    double basePrice;
    int autonomy;

public:
    ElectricEngine();

    explicit ElectricEngine(double basePrice, int autonomy);

    ~ElectricEngine() override = default;

    double getPrice();

    std::string toString() override;
};


#endif //ELECTRICENGINE_H
