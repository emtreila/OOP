#ifndef SERVICE_H
#define SERVICE_H

#include "../repository/Repo.h"

class Service {
private:
    Repo &repo;

public:
    explicit Service(Repo &repo) : repo{repo} {
    }

    ~Service() = default;

    bool addCarService(const std::string &name,
                       const std::string &model,
                       int year,
                       const std::string &color); // add a car to the repository

    bool removeCarService(const std::string &model,
                          int year);

    DynamicVector<Car> getAllService() const;

    Car getCarService(int index) const;

    DynamicVector<Car> getVintageCarsService(); // get all cars older than 1980, sorted by color
};


#endif //SERVICE_H
