#ifndef SERVICE_H
#define SERVICE_H
#include "Observer.h"
#include "Repo.h"


class Service {
private:
    Repo &repo;
    std::vector<Observer *> observers;

public:
    Service(Repo &repo) : repo(repo) {
    }

    ~Service() = default;

    void addObserver(Observer *obs);

    void removeObserver(Observer *obs);

    void notifyObservers();

    const std::vector<Event>  &getAllEventsService() const;

    const std::vector<Person> &getAllPeopleService();

    void addEventService(const Event &event);

    void attendEventService(int index, const std::string &personName);
};


#endif //SERVICE_H
