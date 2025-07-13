#ifndef REPO_H
#define REPO_H
#include "../DynamicVector.h"
#include "../domain/Assignment.h"
#include <fstream>

class Repo {
private:
    DynamicVector<Assignment> assignments;
    std::string filename;

public:
    Repo();

    explicit Repo(const std::string &filename);

    ~Repo() = default;

    void readFromFile();

    bool addAssignment(int id,
                       std::string name,
                       std::string solution);

    const DynamicVector<Assignment> &getAll() const;

    int getNrOfAssignments() const;

    Assignment getAssignment(int index);
};


#endif //REPO_H
