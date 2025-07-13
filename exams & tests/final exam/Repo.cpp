#include "Repo.h"

Repo::Repo() {
    readFromFileIdeas();
    readFromFileResearchers();
}

void Repo::readFromFileIdeas() {
    std::ifstream file;
    file.open("data_idea.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data_ideas = std::vector<Idea>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string title;
        std::string description;
        std::string status;
        std::string creator;
        std::string strduration;

        if (std::getline(ss, title, ';') &&
            std::getline(ss, description, ';') &&
            std::getline(ss, status, ';') &&
            std::getline(ss, creator, ';') &&
            std::getline(ss, strduration, ';')) {
            int duration = std::stoi(strduration);

            Idea idea(title, description, status, creator, duration);
            this->data_ideas.push_back(idea);
        }
    }

    std::sort(this->data_ideas.begin(), this->data_ideas.end(),
              [](Idea &a, Idea &b) {
                  return a.getDuration() < b.getDuration();
              });
}

void Repo::readFromFileResearchers() {
    std::ifstream file;
    file.open("data_researcher.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    this->data_researchers = std::vector<Researcher>();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        std::string position;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, position, ';')) {
            Researcher researcher(name, position);
            this->data_researchers.push_back(researcher);
        }
    }
}

const std::vector<Idea> &Repo::getAllIdeas() const {
    return this->data_ideas;
}

const std::vector<Researcher> &Repo::getAllResearchers() const {
    return this->data_researchers;
}

void Repo::addIdea(const Idea &idea) {
    this->data_ideas.push_back(idea);
    std::ofstream file("data_idea.txt", std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    file << idea.getTitle() << ";"
            << idea.getDescription() << ";"
            << idea.getStatus() << ";"
            << idea.getCreator() << ";"
            << idea.getDuration() << ";\n";
}

void Repo::updateIdea(const Idea &updatedIdea) {
    for (auto &idea: this->data_ideas) {
        if (idea.getTitle() == updatedIdea.getTitle()) {
            idea = updatedIdea;
            break;
        }
    }

    std::ofstream file("data_idea.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }

    for (const auto &idea: this->data_ideas) {
        file << idea.getTitle() << ";"
                << idea.getDescription() << ";"
                << idea.getStatus() << ";"
                << idea.getCreator() << ";"
                << idea.getDuration() << ";\n";
    }
}
