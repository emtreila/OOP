#ifndef SERVICE_H
#define SERVICE_H
#include<algorithm>
#include "Repo.h"


class Service {
private:
    Repo &repo;

public:
    Service(Repo &repo) : repo(repo) {
    }

    ~Service() = default;

    const std::vector<Idea> &getAllIdeasService() const;

    const std::vector<Researcher> &getAllResearchersService() const;

    void addIdea(const Idea &idea) const;

    void updateIdea(Idea &idea) const;

    std::vector<Idea> getIdeasWithStatusFoCreator(const std::string &status, const std::string &creator) const;
};


#endif //SERVICE_H
