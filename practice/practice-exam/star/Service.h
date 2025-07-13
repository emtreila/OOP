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

    const std::vector<Astronomer> &getAllAstronomers() const;

    const std::vector<Star> &getAllStars() const;

    std::vector<Star> getAllStudiedStars(const std::string &constellationName) const;

    void addStar(const Star &star);

};


#endif //SERVICE_H
