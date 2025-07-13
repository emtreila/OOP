//
// Created by mela on 24.05.2025.
//

#include "Service.h"

#include <stdexcept>

Service::Service(Repo& r) : repo(r) {}



std::vector<Bills> Service::getDataService() {
    return this->repo.getData();
}

double Service::totalByCompanyService(const std::string &companyName) {
    std::vector<Bills> bills = this->repo.getData();
    double total = 0;

    for (auto bill: bills) {
        if (bill.getCompanyName() == companyName && bill.getIsPaid() == false) {
            total += bill.getSum();
        }
    }
    if (total == 0) {
        throw std::invalid_argument("No bills for this company");
    }
    return total;
}
