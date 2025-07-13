#ifndef ASTRONOMER_H
#define ASTRONOMER_H
#include <string>


class Astronomer {
private:
    std::string name;
    std::string constelation;

public:
    Astronomer();

    Astronomer(std::string name, std::string constelation);

    ~Astronomer() = default;

    std::string getName() const;

    std::string getConstelation() const;

    void setName(const std::string &name);

    void setConstelation(const std::string &constelation);
};


#endif //ASTRONOMER_H
