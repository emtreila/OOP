#ifndef SERVICE_H
#define SERVICE_H

#include "../repository/Repo.h"

class Service {
private:
    Repo &repo;

public:
    explicit Service(Repo &repo): repo{repo} {
    } // Constructor

    ~Service() = default; // Destructor

    // Add a coat
    bool addCoatService(const std::string &size,
                        const std::string &colour,
                        double price,
                        unsigned int quantity,
                        const std::string &photo);

    // Remove a coat
    bool removeCoatService(const std::string &size, const std::string &colour);

    // Update a coat
    bool updateCoatService(const TrenchCoat &coat);

    // Get all coats
    const DynamicVector<TrenchCoat> &getAllService() const;

    // Get the size of the coats
    unsigned int getCoatsSizeService() const;

    // Get a coat by index
    TrenchCoat getCoatService(int index) const;
};

#endif //SERVICE_H
