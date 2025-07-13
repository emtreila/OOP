#include "Event.h"

#include <algorithm>

Event::Event() {
    this->organizer = "";
    this->name = "";
    this->description = "";
    this->longitude = 0.0;
    this->latitude = 0.0;
    this->date = "";
    this->attendees = std::vector<std::string>();
}

Event::Event(const std::string &organizer, const std::string &name, const std::string &description, double longitude,
             double latitude, const std::string &date, std::vector<std::string> attendees) {
    this->organizer = organizer;
    this->name = name;
    this->description = description;
    this->longitude = longitude;
    this->latitude = latitude;
    this->date = date;
    this->attendees = std::move(attendees);
}

const std::string &Event::getOrganizer() const {
    return organizer;
}

void Event::setOrganizer(const std::string &organizer) {
    this->organizer = organizer;
}

const std::string &Event::getName() const {
    return name;
}

void Event::setName(const std::string &name) {
    this->name = name;
}

const std::string &Event::getDescription() const {
    return description;
}

void Event::setDescription(const std::string &description) {
    this->description = description;
}

double Event::getLongitude() const {
    return longitude;
}

void Event::setLongitude(double longitude) {
    this->longitude = longitude;
}

double Event::getLatitude() const {
    return latitude;
}

void Event::setLatitude(double latitude) {
    this->latitude = latitude;
}

const std::string &Event::getDate() const {
    return date;
}

void Event::setDate(const std::string &date) {
    this->date = date;
}

std::string Event::toString() const {
    return this->organizer + " | " + this->name + " | " +
           std::to_string(this->longitude) + " | " + std::to_string(this->latitude) + " | " + this->date;
}

std::vector<std::string> Event::getAttendees() {
    return this->attendees;
}

void Event::addAttendee(const std::string &personName) {
    this->attendees.push_back(personName);
}

bool Event::isAttending(const std::string &personName) const {
    return std::find(attendees.begin(), attendees.end(), personName) != attendees.end();
}