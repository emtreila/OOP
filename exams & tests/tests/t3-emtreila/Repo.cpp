#include "Repo.h"

#include <algorithm>
#include <fstream>
#include <sstream>

Repo::Repo() {
    readFromFile();
}

void Repo::readFromFile() {
    std::ifstream file;
    file.open("search_data.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data = std::vector<Document>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string n, k, c;

        if (std::getline(ss, n, ';') &&
            std::getline(ss, k, ';') &&
            std::getline(ss, c, ';')) {
            std::string name = n;
            std::string keyword = k;
            std::string content = c;


            Document doc(name, keyword, content);
            this->data.push_back(doc);
        }
    }

    std::sort(data.begin(), data.end(),
              [](Document &a, Document &b) {
                  return a.getName() < b.getName();
              });
}

std::vector<Document> Repo::getAll() {
    return this->data;
}
