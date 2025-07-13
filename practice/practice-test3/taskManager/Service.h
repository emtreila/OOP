//
// Created by mela on 29.05.2025.
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

    std::vector<Task> getAllService();

    std::vector<Task> getFiltered();
};


#endif //SERVICE_H
