//
// Created by mela on 29.05.2025.
//

#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Weather.h"


class Repo {
private:
    std::vector<Weather> data;

    void readFile();

public:
    Repo();

    ~Repo() = default;

    std::vector<Weather> getAll();
};



#endif //REPO_H
