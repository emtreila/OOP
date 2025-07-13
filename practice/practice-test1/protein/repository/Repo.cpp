#include "Repo.h"

Repo::Repo() = default;

Repo::~Repo() = default;

bool Repo::addProtein(const Protein &protein) {
    /**
     * Add a new protein
     * @param protein - the protein to be added
     * return true, if the protein was added, false otherwise
     */
    try {
        Protein found = this->proteins.find(protein);
    } catch ( std::exception&) {
        this->proteins.add(protein);
        return true;
    }
    return false;
}

const DynamicVector<Protein> &Repo::getAll() {
    return this->proteins;
}

Protein Repo::getProtein(int index) {
    return this->proteins.getElement(index);
}