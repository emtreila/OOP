#include "Protein.h"

Protein::Protein() {
    this->organism = "";
    this->name = "";
    this->sequence = "";
}

Protein::Protein(const std::string &organism, const std::string &name, const std::string &sequence) {
    this->organism = organism;
    this->name = name;
    this->sequence = sequence;
}

Protein::~Protein() = default;

Protein::Protein(const Protein &protein) {
    this->organism = protein.organism;
    this->name = protein.name;
    this->sequence = protein.sequence;
}

const std::string &Protein::getName() const {
    return this->name;
}

const std::string &Protein::getOrganism() const {
    return this->organism;
}

const std::string &Protein::getSequence() const {
    return this->sequence;
}

void Protein::setName(const std::string &newName) {
    this->name = newName;
}

void Protein::setOrganism(const std::string &newOrganism) {
    this->organism = newOrganism;
}

void Protein::setSequence(const std::string &newSequence) {
    this->sequence = newSequence;
}

bool Protein::operator==(const Protein &protein) const {
    return (this->name.compare(protein.name) == 0 && this->organism.compare(protein.organism) == 0);
}
