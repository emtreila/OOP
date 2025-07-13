#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Astronomer.h"
#include "Star.h"


class Repo {
private:
    std::vector<Astronomer> data_astronomers;
    std::vector<Star> data_stars;

public:
    Repo();

    ~Repo() = default;

    void readAstronomersFromFile();

    void readStarsFromFile();

    const std::vector<Astronomer> &getAllAstronomers() const;

    const std::vector<Star> &getAllStars() const;

    void addStar(const Star &star);
};


#endif //REPO_H
