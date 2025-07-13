#ifndef SERVICE_H
#define SERVICE_H
#include "../DynamicVector.h"
#include "../domain/Task.h"
#include "../repository/Repo.h"

class Service {
private:
    Repo &repo;
public:
    explicit Service(Repo &repo): repo{repo} {}

    ~Service() = default;

    bool addTaskService(const std::string& description, unsigned int duration, unsigned int priority); // Adds a task

    const DynamicVector<Task> &getAllService() const; // Get all tasks

    DynamicVector<Task> priorityTasksService(unsigned int priority) const; // Get all tasks with a priority less than a given priority
};


#endif //SERVICE_H
