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
    explicit Service(Repo &repo);

    std::vector<Bills> getDataService();

    double totalByCompanyService(const std::string &companyName);
};


#endif //SERVICE_H
