#ifndef CAR_H
#define CAR_H
#include <string>

#include "Engine.h"


class Car{
private:
    Engine *engine;
    std::string bodyStyle;
public:
    Car();

    Car(const std::string &bodyStyle);

    ~Car() = default;

    double computePrice();
};


#endif //CAR_H
