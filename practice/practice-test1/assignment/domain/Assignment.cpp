#include "Assignment.h"

Assignment::Assignment() {
    this->id = 0;
    this->name = "";
    this->solution = "";
}

Assignment::Assignment(int id, const std::string &name, const std::string &solution) {
    this->id = id;
    this->name = name;
    this->solution = solution;
}

Assignment::~Assignment() = default;

Assignment::Assignment(const Assignment &assignment) {
    this->id = assignment.id;
    this->name = assignment.name;
    this->solution = assignment.solution;
}

int Assignment::getId() const {
    return this->id;
}

const std::string &Assignment::getName() const {
    return this->name;
}

const std::string &Assignment::getSolution() const {
    return this->solution;
}

void Assignment::setId(int id) {
    this->id = id;
}

void Assignment::setName(const std::string &name) {
    this->name = name;
}

void Assignment::setSolution(const std::string &solution) {
    this->solution = solution;
}
