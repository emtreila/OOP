//
// Created by mela on 24.05.2025.
//

#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Equation.h"


class Repo {
private:
    std::vector<Equation> data;

    void readFile();

public:
    Repo();

    ~Repo() = default;

    std::vector<Equation> getAll();

    void add(const Equation &eq);
};


#endif //REPO_H
