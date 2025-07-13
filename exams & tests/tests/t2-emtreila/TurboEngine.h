#ifndef TURBOENGINE_H
#define TURBOENGINE_H
#include "Engine.h"


class TurboEngine : virtual public Engine{
private:
    double basePrice;
public:
    TurboEngine();

    TurboEngine(double basePrice);

    ~TurboEngine() override = default;

    double getPrice();

    std::string toString() override;
};


#endif //TURBOENGINE_H
