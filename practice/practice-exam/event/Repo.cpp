#include "Repo.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

Repo::Repo() {
    this->readEventFromFile();
    this->readPersonFromFile();
}

void Repo::readEventFromFile() {
    std::ifstream file;
    file.open("data_event.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->events_data = std::vector<Event>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string organizer, name, description, strlongitude, strlatitude, date;

        if (std::getline(ss, organizer, ';') &&
            std::getline(ss, name, ';') &&
            std::getline(ss, description, ';') &&
            std::getline(ss, strlongitude, ';') &&
            std::getline(ss, strlatitude, ';') &&
            std::getline(ss, date, ';')) {
            double longitude = std::stod(strlongitude);
            double latitude = std::stod(strlatitude);


            Event event(organizer, name, description, longitude, latitude, date, std::vector<std::string>());
            this->events_data.push_back(event);
        }
    }

    std::sort(events_data.begin(), events_data.end(),
              [](Event &a, Event &b) {
                  return a.getDate() < b.getDate();
              });
}

void Repo::readPersonFromFile() {
    std::ifstream file;
    file.open("data_person.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->people_data = std::vector<Person>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, strlongitude, strlatitude, strstatus;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, strlongitude, ';') &&
            std::getline(ss, strlatitude, ';') &&
            std::getline(ss, strstatus, ';')) {
            double longitude = std::stod(strlongitude);
            double latitude = std::stod(strlatitude);
            bool status = (strstatus == "1");

            Person person(name, longitude, latitude, status);
            this->people_data.push_back(person);
        }
    }
}

const std::vector<Event> &Repo::getAllEvents() const {
    return this->events_data;
}

const std::vector<Person> &Repo::getAllPeople() const {
    return this->people_data;
}

void Repo::addEvent(const Event &event) {
    writeEventToFile(event);
}

void Repo::writeEventToFile(const Event &event) {
    this->events_data.push_back(event);

    std::ofstream file("data_event.txt", std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    file << "\n" << event.getOrganizer() << ";"
            << event.getName() << ";"
            << event.getDescription() << ";"
            << event.getLongitude() << ";"
            << event.getLatitude() << ";"
            << event.getDate();

    file.close();
}
