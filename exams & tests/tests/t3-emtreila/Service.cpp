#include "Service.h"

std::vector<Document> Service::getAllService() {
    return this->repo.getAll();
}

double Service::getScore(Document doc, const std::string &search) {
    const std::string &name = doc.getName();

    if (name.find(search) == 0) {
        return double(search.size()) / double(name.size());
    }

    int matchCount = 0;
    for (int i = 0; i < search.size() && i < name.size(); ++i) {
        if (search[i] == name[i]) {
            ++matchCount;
        }
    }

    return double(matchCount) / double(search.size());
}
