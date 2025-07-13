#ifndef RESEARCHER_H
#define RESEARCHER_H
#include <string>

class Researcher {
private:
    std::string name;
    std::string position;

public:
    Researcher();

    explicit Researcher(const std::string &name, const std::string &position);

    ~Researcher() = default;

    const std::string &getName() const;

    const std::string &getPosition() const;

    void setName(const std::string &name);

    void setPosition(const std::string &position);

    std::string toString() const;
};


#endif //RESEARCHER_H
