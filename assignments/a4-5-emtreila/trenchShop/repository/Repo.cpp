#include "Repo.h"

Repo::Repo(): coats() {
}

Repo::~Repo() = default; // Destructor

bool Repo::addCoat(const TrenchCoat &coat) {
    /**
     * Adds a coat to the repository
     * @param coat - the coat to be added
     * @return true if the coat was added, false otherwise
     */
    try {
        TrenchCoat found = this->coats.find(coat); // check if the coat already exists
    } catch (std::exception &) {
        // if the coat does not exist, add it
        this->coats.add(coat);
        return true;
    }
    return false;
}

TrenchCoat Repo::findCoat(const std::string &size, const std::string &colour) const {
    /**
     * Finds a coat in the repository
     * @param size - the size of the coat
     * @param colour - the colour of the coat
     * @return the coat if it was found, an empty coat otherwise
     */
    TrenchCoat mock = TrenchCoat();
    mock.setSize(size);
    mock.setColour(colour);
    TrenchCoat found = this->coats.find(mock);
    return found;
}


bool Repo::removeCoat(const std::string &size, const std::string &colour) {
    /**
     * Removes a coat from the repository
     * @param size - the size of the coat
     * @param colour - the colour of the coat
     * @return true if the coat was removed, false otherwise
     */
    try {
        TrenchCoat found = findCoat(size, colour);
        this->coats.remove(found);
        return true;
    } catch (std::exception &) {
        return false;
    }
}

bool Repo::updateCoat(const TrenchCoat &coat) {
    /**
     * Updates a coat from the repository
     * @param coat - the coat to be updated
     * @return true if the coat was updated, false otherwise
     */
    return this->coats.update(coat);
}

const DynamicVector<TrenchCoat> &Repo::getAll() const {
    /**
     * Returns all the coats from the repository
     * @return a reference to the dynamic vector containing all the coats
     */
    return this->coats;
}

unsigned int Repo::getCoatsSize() const {
    /**
     * Returns the number of coats in the dynamic array
     * @return the number of coats
     */
    return this->coats.sizeOfVector();
}

TrenchCoat Repo::getCoat(int index) const {
    /**
     * Returns a coat from the dynamic array
     * @param index - the index of the coat
     * @return the coat at the given index
     */
    return this->coats.getElement(index);
}
