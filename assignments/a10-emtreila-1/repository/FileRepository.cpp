#include "FileRepository.h"

FileRepository::FileRepository(const std::string &filename) {
    this->filename = filename;
}


void FileRepository::addCoat(const TrenchCoat &coat) {
    MemoryRepository::addCoat(coat);
    writeToFile();
}

void FileRepository::removeCoat(const std::string &size, const std::string &colour) {
    MemoryRepository::removeCoat(size, colour);
    writeToFile();
}

void FileRepository::updateCoat(const TrenchCoat &coat) {
    MemoryRepository::updateCoat(coat);
    writeToFile();
}
