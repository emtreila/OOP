#include "Service.h"

bool Service::addTaskService(const std::string& description, unsigned int duration, unsigned int priority) {
    /**
     * Adds a task
     * @param description: the description of the task
     * @param duration: the duration of the task
     * @param priority: the priority of the task
     * return: true if the task was added, false otherwise
     */
    Task newTask = Task(description, duration, priority);
    return this->repo.addTask(newTask);
}

const DynamicVector<Task> &Service::getAllService() const {
    /**
     * Get all tasks
     * return: a reference to the dynamic vector of tasks
     */
    return this->repo.getAll();
}

DynamicVector<Task> Service::priorityTasksService(const unsigned int priority) const {
    /**
     * Get all tasks with a priority less than a given priority
     * @param priority: the given priority
     * return: a dynamic vector of tasks
     */
    const DynamicVector<Task> &tasks = this->repo.getAll();
    DynamicVector<Task> result;
    for (int i = 0; i < tasks.sizeOfVector(); i++) {
        if (tasks.getElement(i).getPriority() < priority) {
            result.add(tasks.getElement(i));
        }
    }
    // Sort the tasks in descending order of duration
    for (int i = 0; i < result.sizeOfVector(); i++) {
        for (int j = i + 1; j < result.sizeOfVector(); j++) {
            if (result.getElement(i).getDuration() < result.getElement(j).getDuration()) {
                Task aux = result.getElement(i);
                result.setElement(i, result.getElement(j));
                result.setElement(j, aux);
            }
        }
    }
    return result;
}
