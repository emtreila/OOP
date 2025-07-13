#include "Service.h"

bool Service::addCoatService(const std::string &size,
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
    return this->repo.addCoat(newCoat);
}

bool Service::removeCoatService(const std::string &size, const std::string &colour) {
    /**
     * Removes the coat from the repository
     * @param size - the size of the coat
     * @param colour - the colour of the coat
     * @return true if the coat was removed, false otherwise
     */
    return this->repo.removeCoat(size, colour);
}

bool Service::updateCoatService(const TrenchCoat &coat) {
    /**
     * Updates the coat from the repository
     * @param coat - the coat to be updated
     * @return true if the coat was updated, false otherwise
     */
    return this->repo.updateCoat(coat);
}

const DynamicVector<TrenchCoat> &Service::getAllService() const {
    /**
     * Gets all the coats from the repository
     * @return a vector of coats
     */
    return this->repo.getAll();
}

unsigned int Service::getCoatsSizeService() const {
    /**
     * Gets the number of coats
     * @return the size of the coats
     */
    return this->repo.getCoatsSize();
}

TrenchCoat Service::getCoatService(int index) const {
    /**
     * Gets a coat by index
     * @param index - the index of the coat
     * @return the coat
     */
    return this->repo.getCoat(index);
}
