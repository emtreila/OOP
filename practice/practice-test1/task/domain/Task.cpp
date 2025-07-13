#include "Task.h"

Task::Task() {
    this->description = "";
    this->duration = 0;
    this->priority = 0;
}

Task::Task(const std::string &description, unsigned int duration, unsigned int priority) {
    this->description = description;
    this->duration = duration;
    this->priority = priority;
}

Task::~Task() = default;

Task::Task(const Task &task) {
    this->description = task.description;
    this->duration = task.duration;
    this->priority = task.priority;
}

std::string Task::getDescription() {
    return this->description;
}

unsigned int Task::getDuration() const {
    return this->duration;
}

unsigned int Task::getPriority() const {
    return this->priority;
}

void Task::setDescription(const std::string &description) {
    this->description = description;
}

void Task::setDuration(const unsigned int duration) {
    this->duration = duration;
}

void Task::setPriority(const unsigned int priority) {
    this->priority = priority;
}

bool Task::operator==(const Task &t) const {
    return (this->description == t.description);
}

