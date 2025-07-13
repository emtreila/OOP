#include "Repo.h"

#include <vector>
#include <sstream>

std::string trim(const std::string& s) {
    const size_t first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    const size_t last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, last - first + 1);
}

Repo::Repo(): assignments() {
    this->filename = "../assignments.txt";
}

Repo::Repo(const std::string &filename): assignments() {
    this->filename = filename;
}

void Repo::readFromFile() {
    std::ifstream fin(this->filename);
    if (!fin) {  // More concise way to check file opening
        throw std::runtime_error("The file could not be opened!");
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(trim(cell));
        }

        int id = std::stoi(row[0]); // Convert first value to integer safely
        std::string name = row[1];
        std::string solution = row[2];

        this->addAssignment(id, name, solution);
    }

    fin.close();
}


bool Repo::addAssignment(int id, std::string name, std::string solution) {
    Assignment assignment{id, name, solution};
    this->assignments.add(assignment);
    return true;
}

const DynamicVector<Assignment> &Repo::getAll() const {
    return this->assignments;
}

int Repo::getNrOfAssignments() const {
    return this->assignments.sizeOfVector();
}

Assignment Repo::getAssignment(int index) {
    return this->assignments.getElement(index);
}




