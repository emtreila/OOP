#include "Service.h"

std::vector<Document> Service::getAllService() {
    return this->repo.getAll();
}

double Service::getScore(Document doc, const std::string &search) {
    const std::string &name = doc.getName();

    if (name.find(search) == 0) { // if `search` is a prefix of `name`
        return 1.0 + static_cast<double>(search.size()) / name.size(); // 1.0  = higher score for prefix matches
    }

    int matchCount = 0;
    for (int i = 0; i < search.size() && i < name.size(); ++i) {
        if (search[i] == name[i]) {
            ++matchCount;
        }
    }

    return static_cast<double>(matchCount) / search.size();
}
