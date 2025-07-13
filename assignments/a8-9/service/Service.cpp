#include "Service.h"

#include "ServiceException.h"


void Service::addCoatService(const std::string &size,
                             const std::string &colour,
                             double price,
                             unsigned int quantity,
                             const std::string &photo) {
    /**
     * Adds the coat to the repository
     * @param size - the size of the coat
     * @param colour - the colour of the coat
     * @param quantity - the quantity of the coat
     * @param photo - the photo of the coat
     * @return true if the coat was added, false otherwise
     */
    TrenchCoat newCoat = TrenchCoat(size, colour, price, quantity, photo);
    try {
        ValidatorTrenchCoat::validateTrenchCoat(newCoat);
    } catch (const ValidatorException &e) {
        std::string errorMessage = "The trench coat is not valid: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }

    try {
        this->repo->addCoat(newCoat);
    } catch (const RepositoryException &e) {
        std::string errorMessage = "The trench coat could not be added: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }
}

void Service::removeCoatService(const std::string &size, const std::string &colour) {
    /**
     * Removes the coat from the repository
     * @param size - the size of the coat
     * @param colour - the colour of the coat
     * @return true if the coat was removed, false otherwise
     */
    try {
        ValidatorTrenchCoat::validateSize(size);
        ValidatorTrenchCoat::validateColour(colour);
    } catch (const ValidatorException &e) {
        std::string errorMessage = "The size / colour is not valid: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }

    try {
        this->repo->removeCoat(size, colour);
    } catch (const RepositoryException &e) {
        std::string errorMessage = "The trench coat could not be removed: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }
}

void Service::updateCoatService(const TrenchCoat &coat) {
    /**
     * Updates the coat from the repository
     * @param coat - the coat to be updated
     * @return true if the coat was updated, false otherwise
     */
    try {
        ValidatorTrenchCoat::validateTrenchCoat(coat);
    } catch (const ValidatorException &e) {
        std::string errorMessage = "The trench coat is not valid: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }

    try {
        this->repo->updateCoat(coat);
    } catch (const RepositoryException &e) {
        std::string errorMessage = "The trench coat could not be updated: ";
        errorMessage += e.what();
        throw ServiceException(errorMessage.c_str());
    }
}

const std::vector<TrenchCoat> &Service::getAllService() const {
    /**
     * Gets all the coats from the repository
     * @return a vector of coats
     */
    return this->repo->getAll();
}
