#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Event.h"
#include "Person.h"


class Repo {
private:
    std::vector<Event> events_data;
    std::vector<Person> people_data;

public:
    Repo();

    ~Repo() = default;

    void readEventFromFile();

    void readPersonFromFile();

    const std::vector<Event> &getAllEvents() const;

    const std::vector<Person> &getAllPeople() const;

    void addEvent(const Event &event);

    void writeEventToFile(const Event &event);

};


#endif //REPO_H
