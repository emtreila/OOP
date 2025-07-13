#ifndef TASK_H
#define TASK_H
#include <string>


class Task {
private:
    std::string description;
    int duration;
    int priority;

public:
    Task();

    explicit Task(std::string description, int duration, int priority);

    std::string getDescription();

    int getPriority();

    int getDuration();

    std::string toString();

    ~Task() = default;
};


#endif //TASK_H
