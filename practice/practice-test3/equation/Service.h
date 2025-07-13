//
// Created by mela on 24.05.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"


class Service {
private:
    Repo &repo;

public:
    Service(Repo &repo): repo(repo) {
    };

    ~Service() = default;

    std::vector<Equation> getAllService();

    bool realSol(Equation &eq);

    void addEquation(const Equation &eq);

    std::string solutions(Equation &eq);
};


#endif //SERVICE_H
