#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Document.h"


class Repo {
private:
    std::vector<Document> data;

    void readFromFile();

public:
    Repo();

    ~Repo() = default;

    std::vector<Document> getAll();
};


#endif //REPO_H
