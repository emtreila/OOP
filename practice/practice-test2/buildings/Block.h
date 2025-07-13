#ifndef BLOCK_H
#define BLOCK_H
#include "Building.h"


class Block : virtual public Building {
private:
    int totalApartments;
    int occupiedApartments;

public:
    Block();

    Block(const std::string &address, int constructionYear, int totalApartments, int occupiedApartments);

    ~Block() override = default;

    bool mustBeRestored() override;

    bool canBeDemolished() override;

    std::string toString() override;
};


#endif //BLOCK_H
