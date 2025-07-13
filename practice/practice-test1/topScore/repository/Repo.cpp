#include "Repo.h"

Repo::Repo(): scorers() {
}

Repo::~Repo() = default;

bool Repo::addScorer(const Scorer &scorer) {
    /**
     * Adds a new player to the repository
     * @param scorer - the player to be added
     * @return true, if the player was added, false otherwise
     */
    try {
        Scorer found = this->scorers.find(scorer);
    } catch (std::exception&) {
        this->scorers.add(scorer);
        return true;
    }
    return false;

}

const DynamicVector<Scorer> &Repo::getAll() {
    return this->scorers;
}

int Repo::getNumberOfPlayers() {
    return this->scorers.sizeOfVector();
}

Scorer Repo::getPlayer(int index) {
    return this->scorers.getElement(index);
}



