#include "Scorer.h"

Scorer::Scorer() {
    this->name = "";
    this->nationality = "";
    this->team = "";
    this->goals = 0;
}

Scorer::Scorer(const std::string &name, const std::string &nationality, const std::string &team, int goals) {
    this->name = name;
    this->nationality = nationality;
    this->team = team;
    this->goals = goals;
}

Scorer::~Scorer() = default;

Scorer::Scorer(const Scorer &scorer) {
    this->name = scorer.name;
    this->nationality = scorer.nationality;
    this->team = scorer.team;
    this->goals = scorer.goals;
}

const std::string& Scorer::getName() const {
    return this->name;
}

const std::string& Scorer::getNationality() const {
    return this->nationality;
}

const std::string& Scorer::getTeam() const {
    return this->team;
}

int Scorer::getGoals() const {
    return this->goals;
}

void Scorer::setName(const std::string newName) {
    this->name = newName;
}

void Scorer::setNationality(const std::string newNationality) {
    this->nationality = newNationality;
}

void Scorer::setTeam(const std::string newTeam) {
    this->team = newTeam;
}

void Scorer::setGoals(int newGoals) {
    this->goals = newGoals;
}

bool Scorer::operator==(const Scorer &scorer) const {
    return (this->name == scorer.name);
}
