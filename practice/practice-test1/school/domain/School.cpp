#include "School.h"

School::School() {
    this->name = "";
    this->address_long = 0;
    this->address_lat = 0;
    this->day = 0;
    this->month = 0;
    this->year = 0;
    this->visited = false;
}

School::School(const std::string &name,
               float address_long,
               float address_lat,
               int day,
               int month,
               int year,
               bool visited) {
    this->name = name;
    this->address_long = address_long;
    this->address_lat = address_lat;
    this->day = day;
    this->month = month;
    this->year = year;
    this->visited = visited;
}

School::~School() = default;

School::School(const School &s) {
    this->name = s.name;
    this->address_long = s.address_long;
    this->address_lat = s.address_lat;
    this->day = s.day;
    this->month = s.month;
    this->year = s.year;
    this->visited = s.visited;
}

const std::string &School::getName() {
    return this->name;
}

float School::getLong() const {
    return this->address_long;
}

float School::getAlt() const {
    return this->address_lat;
}

int School::getDay() const {
    return this->day;
}

int School::getMonth() const {
    return this->month;
}

int School::getYear() const {
    return this->year;
}

bool School::getVisited() const {
    return this->visited;
}

void School::setName(const std::string &newName) {
    this->name = newName;
}

void School::setLong(const float newLong) {
    this->address_long = newLong;
}

void School::setAlt(const float newAlt) {
    this->address_lat = newAlt;
}

void School::setDay(const int newDay) {
    this->day = newDay;
}

void School::setMonth(const int newMonth) {
    this->month = newMonth;
}

void School::setYear(const int newYear) {
    this->year = newYear;
}

void School::setVisited(const bool newVisited) {
    this->visited = newVisited;
}

bool School::operator==(const School &school) const {
    return (this->name == school.name && this->address_long == school.address_long &&
           this->address_lat == school.address_lat);
}