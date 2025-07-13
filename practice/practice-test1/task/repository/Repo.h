#ifndef REPO_H
#define REPO_H
#include "../DynamicVector.h"
#include "../domain/Task.h"


class Repo {
private:
    DynamicVector<Task> tasks;

public:
    Repo();

    ~Repo();

    bool addTask(const Task &task); // Adds a task

    const DynamicVector<Task> &getAll(); // Get all tasks
};


#endif //REPO_H
