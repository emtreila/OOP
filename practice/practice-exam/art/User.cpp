#include "User.h"

User::User() {
    this->id = 0;
    this->name = "";
    this->type = "";
}

User::User(const std::string &name, int id, const std::string &type) {
    this->id = id;
    this->name = name;
    this->type = type;
}

int User::getId() const {
    return id;
}

const std::string &User::getName() const {
    return name;
}

const std::string &User::getType() const {
    return type;
}

void User::setId(int id) {
    this->id = id;
}

void User::setName(const std::string &name) {
    this->name = name;
}

void User::setType(const std::string &type) {
    this->type = type;
}
