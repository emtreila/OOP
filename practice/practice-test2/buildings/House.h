#ifndef HOUSE_H
#define HOUSE_H
#include "Building.h"


class House : virtual  public Building{
private:
    std::string type;
    bool isHistorical;
public:
    House();

    explicit House(const std::string &address, int constructionYear, const std::string &type, bool isHistorical);

    ~House() override = default;

    bool mustBeRestored() override;

    bool canBeDemolished() override;

    std::string toString() override;
};


#endif //HOUSE_H
