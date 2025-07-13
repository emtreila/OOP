//
// Created by mela on 29.05.2025.
//

#ifndef SERVIC_H
#define SERVIC_H
#include <vector>

#include "Repo.h"


class Service {
private:
    Repo &repo;

public:
    Service(Repo &repo) : repo(repo) {
    }

    ~Service() = default;

    std::vector<Weather> getAllService();

    std::vector<Weather> getFilterd();
};



#endif //SERVIC_H
