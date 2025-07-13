#include "Repo.h"

Repo::Repo() = default;

Repo::~Repo() = default;

bool Repo::addSchool(const School &school) {
    try {
        School found = this->schools.find(school);
    } catch (std::exception &) {
        this->schools.add(school);
        return true;
    }
    return false;
}

School Repo::findSchool(const std::string &name, float address_long, float address_lat) {
    School mock = School();
    mock.setName(name);
    mock.setLong(address_long);
    mock.setAlt(address_lat);
    School found = this->schools.find(mock);
    return found;
}


bool Repo::removeSchool(const std::string &name, float address_long, float address_lat) {
    /**
     * Remove a school
     * @param name: the name of the school
     * @param address_long: the longitude of the school
     * @param address_lat: the latitude of the school
     * @return true if the school was removed, false otherwise
     */
    try {
        School found = findSchool(name, address_long, address_lat);
        this->schools.remove(found);
        return true;
    } catch (std::exception &) {
        return false;
    }
}

bool Repo::updateSchool(const School &school) {
    return this->schools.update(school);
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
