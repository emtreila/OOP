#include "Person.h"

Person::Person() {
    this->name = "";
    this->longitude = 0.0;
    this->latitude = 0.0;
    this->status = false;
}

Person::Person(const std::string &name, double longitude, double latitude, bool status) {
    this->name = name;
    this->longitude = longitude;
    this->latitude = latitude;
    this->status = status;
}

const std::string &Person::getName() const {
    return name;
}

void Person::setName(const std::string &name) {
    this->name = name;
}

double Person::getLongitude() const {
    return longitude;
}

void Person::setLongitude(double longitude) {
    this->longitude = longitude;
}

double Person::getLatitude() const {
    return latitude;
}

void Person::setLatitude(double latitude) {
    this->latitude = latitude;
}

bool Person::getStatus() const {
    return status;
}

void Person::setStatus(bool status) {
    this->status = status;
}

std::string Person::getLocation(double lat,double lon) const {
    return std::to_string(lat) + ", " + std::to_string(lon);
}
