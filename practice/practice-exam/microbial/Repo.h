#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Bacterium.h"
#include "Biologist.h"


class Repo {
private:
    std::vector<Biologist> data_biologists;
    std::vector<Bacterium> data_bacteria;

public:
    Repo();

    ~Repo() = default;

    void readFromFileBiologist();

    void readFromFileBacterium();

    const std::vector<Biologist> &getAllBiologists() const;

    const std::vector<Bacterium> &getAllBacteria() const;

    void addBacteria(const Bacterium &bacterium);
};


#endif //REPO_H
