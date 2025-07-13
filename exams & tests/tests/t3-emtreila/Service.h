#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"


class Service {
private:
    Repo &repo;

public:
    Service(Repo &repo) : repo(repo) {
    }

    ~Service() = default;

    std::vector<Document> getAllService();

    double getScore(Document doc, const std::string &search);
};


#endif //SERVICE_H
