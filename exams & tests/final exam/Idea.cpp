#include "Idea.h"

Idea::Idea() {
    this->title = "";
    this->description = "";
    this->status = "";
    this->creator = "";
    this->duration = 0;
}

Idea::Idea(const std::string &title, const std::string &description, const std::string &status,
           const std::string &creator, int duration) {
    this->title = title;
    this->description = description;
    this->status = status;
    this->creator = creator;
    this->duration = duration;
}

const std::string &Idea::getTitle() const {
    return this->title;
}

void Idea::setTitle(const std::string &title) {
    this->title = title;
}

const std::string &Idea::getDescription() const {
    return this->description;
}

void Idea::setDescription(const std::string &description) {
    this->description = description;
}

const std::string &Idea::getStatus() const {
    return this->status;
}

void Idea::setStatus(const std::string &status) {
    this->status = status;
}

const std::string &Idea::getCreator() const {
    return this->creator;
}

void Idea::setCreator(const std::string &creator) {
    this->creator = creator;
}

int Idea::getDuration() const {
    return this->duration;
}

void Idea::setDuration(int duration) {
    this->duration = duration;
}

std::string Idea::toString() const {
    return this->title + " | " + this->status + " | " + this->creator + " | " + std::to_string(this->duration);
}

std::string Idea::toDevelopString() const {
    return this->title + " | " + this->status + " | " + this->description + " | " + this->creator + " | " +
           std::to_string(this->duration);
}


Idea &Idea::operator=(const Idea &otherIdea) {
    if (this != &otherIdea) {
        this->title = otherIdea.title;
        this->description = otherIdea.description;
        this->status = otherIdea.status;
        this->creator = otherIdea.creator;
        this->duration = otherIdea.duration;
    }
    return *this;
}
