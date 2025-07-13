#ifndef SERVICE_H
#define SERVICE_H

#include "Repo.h"
#include <algorithm>
#include <sstream>

class Service {
private:
    Repo &repo;

public:
    Service(Repo &repo) : repo(repo) {
    }

    ~Service() = default;

    const std::vector<Biologist> &getAllBiologistsService() const;

    const std::vector<Bacterium> &getAllBacteriaService() const;

    std::vector<Bacterium> getBacteriaByBiologistSpecies(const std::string &biologistName) const;

    std::vector<std::string> splitSpecies(const std::string &species) const;

    void addBacteria(const Bacterium &bacterium);
};


#endif //SERVICE_H
