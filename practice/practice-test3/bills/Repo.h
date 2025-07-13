#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Bills.h"


class Repo {
private:
    std::vector<Bills> data;
    void readFromFile();

public:
    Repo();
    ~Repo() = default;
    std::vector<Bills> getData();
};


#endif //REPO_H
