#include "Repo.h"

Repo::Repo() = default;

Repo::~Repo() = default;

bool Repo::addTask(const Task& task) {
    /**
     * Adds a task
     * @param task: the task to be added
     * return: true if the task was added, false otherwise
     */
    try {
        Task found = this->tasks.find(task);
    } catch (std::exception&) {
        this->tasks.add(task);
        return true;
    }
    return false;
}

const DynamicVector<Task> &Repo::getAll() {
    /**
     * Get all tasks
     * return: a reference to the dynamic vector of tasks
     */
    return this->tasks;
}
