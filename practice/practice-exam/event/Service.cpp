#include "Service.h"
#include<algorithm>
#include <stdexcept>

const std::vector<Event> &Service::getAllEventsService() const {
    return this->repo.getAllEvents();
}

const std::vector<Person> &Service::getAllPeopleService() {
    return this->repo.getAllPeople();
}

void Service::addObserver(Observer *obs) {
    this->observers.push_back(obs);
}

void Service::removeObserver(Observer *obs) {
    this->observers.erase(std::remove(this->observers.begin(), this->observers.end(), obs), this->observers.end());
}

void Service::notifyObservers() {
    for (auto obs: observers)
        obs->update();
}


void Service::addEventService(const Event &newEvent) {
    for (const auto &ev: repo.getAllEvents()) {
        if (ev.getName() == newEvent.getName() &&
            ev.getLatitude() == newEvent.getLatitude() &&
            ev.getLongitude() == newEvent.getLongitude()) {
            throw std::runtime_error("Event with same name and location already exists.");
        }
    }
    this->repo.addEvent(newEvent);
    notifyObservers();
}


void Service::attendEventService(int index, const std::string &personName) {
    std::vector<Event> events = this->repo.getAllEvents();
    if (!events[index].isAttending(personName))
        events[index].addAttendee(personName);
    notifyObservers();
}

