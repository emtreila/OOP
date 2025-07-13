#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Item.h"
#include "User.h"


class Repo {
private:
    std::vector<User> data_users;
    std::vector<Item> data_items;

public:
    Repo();

    ~Repo() = default;

    void readUsersFromFile();

    void readItemsFromFile();

    const std::vector<User> &getUsers() const;

    const std::vector<Item> &getItems() const;

    void addItem(const Item &item);
};


#endif //REPO_H
