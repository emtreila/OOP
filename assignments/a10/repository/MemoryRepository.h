#ifndef MEMORYREPOSITORY_H
#define MEMORYREPOSITORY_H
#include "IRepository.h"


class MemoryRepository : virtual public IRepository {
protected:
    std::vector<TrenchCoat> coats;

public:
    MemoryRepository() = default;

    virtual ~MemoryRepository() = default;

    // adds a coat to the repository
    virtual void addCoat(const TrenchCoat &coat);

    // removes a coat from the repository
    virtual void removeCoat(const std::string &size, const std::string &colour);

    // updates a coat from the repository
    virtual void updateCoat(const TrenchCoat &coat);


    // returns all the coats from the repository
    virtual const std::vector<TrenchCoat> &getAll() const;
};


#endif //MEMORYREPOSITORY_H
