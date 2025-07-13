#ifndef SERVICE_H
#define SERVICE_H
#include <string>
#include <vector>

#include "Car.h"


class Service {
private:
    std::vector<Car *> data;

public:
    Service() = default;

    ~Service();

    void addCar(const std::string &bodyStyle, const std::string engineType, int autonomy);

    std::vector<Car *> getCarsWithMaxPrice(double maxPrice);

    void writeToFile(const std::string &filename, std::vector<Car *> cars);

    std::vector<Car *> getCars();
};


#endif //SERVICE_H
