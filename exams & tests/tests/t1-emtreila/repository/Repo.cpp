#include "Repo.h"

Repo::Repo() = default;

Repo::~Repo() = default;

bool Repo::addSchool(const School &school) {
    /**
     * Adds a new school
     * @param school = the new school to be added
     * return = True if the school was added successfully, False otherwise
     */
    try {
        School found = this->schools.find(school);
    } catch (std::exception &) {
        this->schools.add(school);
        return true;
    }
    return false;
}

const DynamicVector<School> &Repo::getAll() {
    return this->schools;
}


School Repo::getSchool(int index) {
    return this->schools.getElement(index);
}

int Repo::sizeOfRepo() {
    return this->schools.sizeOfVector();
}
