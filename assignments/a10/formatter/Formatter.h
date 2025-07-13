#ifndef IFORMATTER_H
#define IFORMATTER_H
#include <vector>
#include <fstream>
#include "../domain/TrenchCoat.h"


class Formatter {
public:

    virtual ~Formatter() = default;

    virtual std::string format(const std::vector<TrenchCoat> &shoppingBag) = 0;

    virtual void save(const std::string &filename, const std::string &s);
};


#endif //IFORMATTER_H
