#ifndef REPO_H
#define REPO_H
#include <vector>

#include "Idea.h"
#include "Researcher.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

class Repo {
private:
    std::vector<Idea> data_ideas;
    std::vector<Researcher> data_researchers;

public:
    Repo();

    ~Repo() = default;

    void readFromFileIdeas();

    void readFromFileResearchers();

    const std::vector<Idea> &getAllIdeas() const;

    const std::vector<Researcher> &getAllResearchers() const;

    void addIdea(const Idea &idea);

    void updateIdea(const Idea &idea);
};


#endif //REPO_H
