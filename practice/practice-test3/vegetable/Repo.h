//
// Created by mela on 28.05.2025.
//

#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Vegetable.h"


class Repo {
private:
    std::vector<Vegetable> data;

    void readFile();

public:
    Repo();

    ~Repo() = default;

    std::vector<Vegetable> getAll();
};


#endif //REPO_H
