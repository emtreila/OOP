//
// Created by mela on 25.05.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"


class Service {
private:
    Repo &repo;

public:
    Service(Repo &repo): repo(repo) {};

    ~Service() = default;

    std::vector<Car> getAllService();

    std::vector<Car> getCarsByManufacturer(const std::string &manufacturer);
};
#endif //SERVICE_H
