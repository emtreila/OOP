#include "TextFileRepository.h"

#include <fstream>
#include <sstream>

TextFileRepository::TextFileRepository(const std::string &filename) : FileRepository(filename) {
    this->filename = filename;
    TextFileRepository::readFromFile();
}

void TextFileRepository::readFromFile() {
    std::ifstream file;

    file.open(this->filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + this->filename);
    }

    this->coats = std::vector<TrenchCoat>();
    std::string line{};
    TrenchCoat coat;

    while (file >> coat) {
        this->coats.push_back(coat);
    }

    file.close();
}

void TextFileRepository::writeToFile() {
    std::ofstream file(this->filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + this->filename);
    }

    for (const auto &coat: this->coats) {
        file << coat;
    }

    file.close();
}
