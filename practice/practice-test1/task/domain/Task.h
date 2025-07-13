#ifndef TASK_H
#define TASK_H
#include <string>


class Task {
private:
    std::string description;
    unsigned int duration;
    unsigned int priority;

public:
    Task();

    Task(const std::string &description, unsigned int duration, unsigned int priority);

    ~Task();

    Task(const Task &task);

    std::string getDescription();

    unsigned int getDuration() const;

    unsigned int getPriority() const;

    void setDescription(const std::string &description);

    void setDuration(unsigned int duration);

    void setPriority(unsigned int priority);

    bool operator==(const Task &) const;
};


#endif //TASK_H
