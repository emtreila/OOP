#ifndef REPO_H
#define REPO_H
#include "../DynamicVector.h"
#include "../domain/Car.h"


class Repo {
private:
    DynamicVector<Car> cars;

public:
    Repo();

    ~Repo();

    bool addCar(const Car &car); // add a new car

    bool removeCar(const std::string &model, int year);

    const DynamicVector<Car> &getAll();

    Car getCar(int index);

    Car findCar(const std::string &model, int year);
};


#endif //REPO_H
