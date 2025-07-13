#ifndef BUILDING_H
#define BUILDING_H
#include <string>


class Building {
protected:
    std::string address;
    int constructionYear;
public:
    Building();

    explicit Building(const std::string &address, int constructionYear);

    virtual ~Building() = default;

    std::string getAddress() const;

    int getConstructionYear() const;

    virtual bool mustBeRestored() = 0;

    virtual bool canBeDemolished() = 0;

    virtual std::string toString() = 0;
};


#endif //BUILDING_H
