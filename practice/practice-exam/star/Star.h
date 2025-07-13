#ifndef STAR_H
#define STAR_H
#include <string>


class Star {
private:
    std::string name;
    std::string constellation;
    int RA, Dec, diameter;

public:
    Star();

    Star(std::string name, std::string constellation, int RA, int Dec, int diameter);

    ~Star() = default;

    std::string getName() const;

    std::string getConstellation() const;

    int getRA() const;

    int getDec() const;

    int getDiameter() const;

    void setName(const std::string &name);

    void setConstellation(const std::string &constellation);

    void setRA(int RA);

    void setDec(int Dec);

    void setDiameter(int diameter);

    std::string toString() const;
};


#endif //STAR_H
