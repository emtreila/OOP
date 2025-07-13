#ifndef REPO_H
#define REPO_H
#include "../domain/TrenchCoat.h"
#include "../structures/DynamicVector.h"

class Repo {
private:
    DynamicVector<TrenchCoat> coats;

public:
    // default constructor
    Repo();

    // destructor
    ~Repo();

    // adds a coat to the repository
    bool addCoat(const TrenchCoat &coat);

    // removes a coat from the repository
    bool removeCoat(const std::string &size, const std::string &colour);

    // updates a coat from the repository
    bool updateCoat(const TrenchCoat &coat);

    // finds a coat in the repository
    TrenchCoat findCoat(const std::string &size, const std::string &colour) const;

    // returns all the coats from the repository
    const DynamicVector<TrenchCoat> &getAll() const;

    // returns the number of coats in the dynamic array
    unsigned int getCoatsSize() const;

    // returns a coat from the dynamic array
    TrenchCoat getCoat(int index) const;
};


#endif //REPO_H
