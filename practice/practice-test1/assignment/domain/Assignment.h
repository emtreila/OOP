#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <string>

#include "../DynamicVector.h"


class Assignment {
private:
    int id;
    std::string name;
    std::string solution;

public:
    Assignment();

    Assignment(int id, const std::string &name, const std::string &solution);

    ~Assignment();

    Assignment(const Assignment &assignment);

    int getId() const;

    const std::string &getName() const;

    const std::string &getSolution() const;

    void setId(int id);

    void setName(const std::string &name);

    void setSolution(const std::string &solution);
};


#endif //ASSIGNMENT_H
