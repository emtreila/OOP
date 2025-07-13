#ifndef ITEM_H
#define ITEM_H
#include <string>


class Item {
private:
    std::string category, name;
    int quantity;

public:
    Item();

    explicit Item(std::string category, std::string name, int quantity);

    std::string getCategory();

    std::string getName();

    int getQuantity();

    std::string toString();

    ~Item() = default;
};


#endif //ITEM_H
