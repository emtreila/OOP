#ifndef SERVICE_H
#define SERVICE_H

#include "../repository/IRepository.h"
#include "../validator/ValidatorTrenchCoat.h"
#include "../validator/ValidatorException.h"
#include "../repository/RepositoryException.h"

class Service {
private:
    IRepository *repo;

public:
    explicit Service(IRepository *repo): repo{repo} {
    } // Constructor

    ~Service() = default; // Destructor

    // Add a coat
    void addCoatService(const std::string &size,
                        const std::string &colour,
                        double price,
                        unsigned int quantity,
                        const std::string &photo);

    // Remove a coat
    void removeCoatService(const std::string &size, const std::string &colour);

    // Update a coat
    void updateCoatService(const TrenchCoat &coat);

    // Get all coats
    const std::vector<TrenchCoat> &getAllService() const;
};

#endif //SERVICE_H
