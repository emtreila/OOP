//
// Created by mela on 25.05.2025.
//

#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Car.h"


class Repo {
private:
    std::vector<Car> data;
    void readFile();
public:
    Repo();
    ~Repo() = default;
    std::vector<Car> getAll();
};



#endif //REPO_H
