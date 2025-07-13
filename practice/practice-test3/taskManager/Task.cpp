#include "Task.h"

Task::Task() {
    this->description = "";
    this->duration = 0;
    this->priority = 0;
}

Task::Task(std::string description, int duration, int priority) {
    this->description = description;
    this->duration = duration;
    this->priority = priority;
}

std::string Task::getDescription() {
    return this->description;
}

int Task::getPriority() {
    return this->priority;
}

int Task::getDuration() {
    return this->duration;
}

std::string Task::toString() {
    return this->description + " | " + std::to_string(this->duration) + " | " + std::to_string(this->priority);
}
