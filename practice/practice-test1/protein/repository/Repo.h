#ifndef REPO_H
#define REPO_H
#include "../DynamicVector.h"
#include "../domain/Protein.h"


class Repo {
private:
    DynamicVector<Protein> proteins;

public:
    Repo();

    ~Repo();

    bool addProtein(const Protein &protein);

    const DynamicVector<Protein> &getAll();

    Protein getProtein(int index);
};


#endif //REPO_H
