//
// Created by mela on 28.05.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"


class Service {
private:
    Repo &repo;

public:
    Service(Repo &repo) : repo(repo) {
    }

    ~Service() = default;

    std::vector<Item> getAllService();
};


#endif //SERVICE_H
