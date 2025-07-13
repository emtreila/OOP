#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Task.h"


class Repo {
private:
    std::vector<Task> data;

    void readFromFile();

public:
    Repo();

    ~Repo() = default;

    std::vector<Task> getAll();
};


#endif //REPO_H
