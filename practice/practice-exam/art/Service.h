//
// Created by mela on 16.06.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "Observable.h"
#include "Repo.h"


class Service : public Observable{
private:
    Repo &repo;
public:
    Service(Repo &repo) : repo(repo) {
    }

    ~Service() = default;

    std::vector<User> getUsers() const {
        return repo.getUsers();
    }
    std::vector<Item> getItems() const {
        return repo.getItems();
    }

    std::vector<std::string> getCategory();

    void addItem(const Item &item);
};



#endif //SERVICE_H
