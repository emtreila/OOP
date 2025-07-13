#include "Service.h"

bool Service::addProteinService(const std::string &organism,
                                const std::string &name,
                                const std::string &sequence) {
    /**
     * Add a new protein
     * @param organism: the organism of the protein
     * @param name: the name of the protein
     * @param sequence: the sequence of the protein
     * return: true if the protein was added, false otherwise
     */
    Protein protein = Protein(organism, name, sequence);
    return this->repo.addProtein(protein);
}

const DynamicVector<Protein> &Service::getAllService() const {
    return this->repo.getAll();
}

Protein Service::getElemService(int index) const {
    return this->repo.getProtein(index);
}

DynamicVector<Protein> Service::getProteinsByName(const std::string &name) const {
    /**
     * Get all the proteins with a given name, sorted by organism
     * @param name: the name of the proteins
     * return: a vector with all the proteins with the given name, sorted by organism
     */
    const DynamicVector<Protein> &proteins = this->repo.getAll();
    DynamicVector<Protein> result = DynamicVector<Protein>();
    for (int i = 0; i < proteins.sizeOfVector(); i++) {
        if (proteins.getElement(i).getName() == name) {
            result.add(proteins.getElement(i));
        }
    }

    for (int i = 0; i < result.sizeOfVector(); i++) {
        for (int j = i + 1; j < result.sizeOfVector(); j++) {
            if (result.getElement(i).getOrganism() > result.getElement(j).getOrganism()) {
                Protein aux = result.getElement(i);
                result.setElement(i, result.getElement(j));
                result.setElement(j, aux);
            }
        }
    }

    return result;
}
