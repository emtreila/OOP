#include "Service.h"

const std::vector<Idea> &Service::getAllIdeasService() const {
    return this->repo.getAllIdeas();
}

const std::vector<Researcher> &Service::getAllResearchersService() const {
    return this->repo.getAllResearchers();
}

void Service::addIdea(const Idea &idea) const {
    this->repo.addIdea(idea);
}

void Service::updateIdea(Idea &idea) const {
    this->repo.updateIdea(idea);
}

std::vector<Idea> Service::getIdeasWithStatusFoCreator(const std::string &status, const std::string &creator) const {
    std::vector<Idea> ideas;
    for (const auto &idea: this->repo.getAllIdeas()) {
        if (idea.getStatus() == status && idea.getCreator() == creator) {
            ideas.push_back(idea);
        }
    }
    std::sort(ideas.begin(), ideas.end(),
              [](Idea &a, Idea &b) {
                  return a.getDuration() < b.getDuration();
              });
    return ideas;
}
