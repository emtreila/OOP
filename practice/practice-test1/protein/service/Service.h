#ifndef SERVICE_H
#define SERVICE_H

#include "../repository/Repo.h"

class Service {
private:
    Repo &repo;

public:
    explicit Service(Repo &repo): repo{repo} {}

    ~Service() = default;

    bool addProteinService(const std::string &organism,
            const std::string &name,
            const std::string &sequence);

    const DynamicVector<Protein> &getAllService() const;

    Protein getElemService(int index) const;

    DynamicVector<Protein> getProteinsByName(const std::string &name) const;
};


#endif //SERVICE_H
