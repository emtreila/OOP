#include "MemoryRepository.h"
#include <algorithm>

#include "RepositoryException.h"

void MemoryRepository::addCoat(const TrenchCoat &coat) {
    /**
     * Adds a coat to the repository
     * @param coat - the coat to be added
     * @return true if the coat was added, false otherwise
     */
    auto found = std::find(this->coats.begin(), this->coats.end(), coat);
    if (found == this->coats.end()) {
        coats.push_back(coat);
        return;
    }
    throw RepositoryException("The coat already exists!");
}


void MemoryRepository::removeCoat(const std::string &size, const std::string &colour) {
    /**
     * Removes a coat from the repository
     * @param size - the size of the coat
     * @param colour - the colour of the coat
     * @return true if the coat was removed, false otherwise
     */

    auto found = std::find_if(this->coats.begin(), this->coats.end(), [&](const TrenchCoat &t) {
        return t.getSize() == size && t.getColour() == colour;
    });
    if (found != this->coats.end()) {
        this->coats.erase(found);
        return;
    }
    throw RepositoryException("The coat does not exist!");
}

void MemoryRepository::updateCoat(const TrenchCoat &coat) {
    /**
     * Updates a coat from the repository
     * @param coat - the coat to be updated
     * @return true if the coat was updated, false otherwise
     */
    for (auto &i: this->coats) {
        if (i == coat) {
            i = coat;
            return;
        }
    }
    throw RepositoryException("The coat does not exist!");
}

const std::vector<TrenchCoat> &MemoryRepository::getAll() const {
    /**
     * Returns all the coats from the repository
     * @return a reference to the dynamic vector containing all the coats
     */
    return this->coats;
}
