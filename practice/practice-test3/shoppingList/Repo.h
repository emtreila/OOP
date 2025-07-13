//
// Created by mela on 28.05.2025.
//

#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Item.h"


class Repo {
private:
    std::vector<Item> data;

    void readFile();

public:
    Repo();

    ~Repo() = default;

    std::vector<Item> getAll();
};



#endif //REPO_H
