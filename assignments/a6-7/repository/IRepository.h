#ifndef IREPOSITORY_H
#define IREPOSITORY_H
#include <string>
#include <vector>

#include "../domain/TrenchCoat.h"

class IRepository {
public:
    // adds a coat to the repository
    virtual void addCoat(const TrenchCoat &coat) = 0;

    // removes a coat from the repository
    virtual void removeCoat(const std::string &size, const std::string &colour) = 0;

    // updates a coat from the repository
    virtual void updateCoat(const TrenchCoat &coat) = 0;

    // returns all the coats from the repository
    virtual const std::vector<TrenchCoat> &getAll() const = 0;

};

#endif //IREPOSITORY_H
