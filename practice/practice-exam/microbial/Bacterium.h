#ifndef BACTERIUM_H
#define BACTERIUM_H
#include <string>


class Bacterium {
private:
    std::string name;
    std::string species;
    int size;
    std::string diseases;

public:
    Bacterium();

    explicit Bacterium(const std::string &name, const std::string &species, int size, const std::string &diseases);

    const std::string &getName() const;

    const std::string &getSpecies() const;

    int getSize() const;

    const std::string &getDiseases() const;

    void setName(const std::string &name);

    void setSpecies(const std::string &species);

    void setSize(int size);

    void setDiseases(const std::string &diseases);

    std::string toString() const;
};


#endif //BACTERIUM_H
