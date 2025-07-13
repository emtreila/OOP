#ifndef BIOLOGIST_H
#define BIOLOGIST_H
#include <string>


class Biologist {
private:
    std::string name;
    std::string species;

public:
    Biologist();

    explicit Biologist(const std::string &name, const std::string &species);

    const std::string &getName() const;

    const std::string &getSpecies() const;

    void setName(const std::string &name);

    void setSpecies(const std::string &species);

    std::string toString() const;
};


#endif //BIOLOGIST_H
