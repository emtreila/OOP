#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include <tuple>

class Item {
private:
    std::string name;
    std::string category;
    int currentPrice;
    std::vector<std::tuple<int, std::string, int> > offers;

public:
    Item();

    Item(const std::string &name, const std::string &category, int currentPrice);

    const std::string &getName() const;

    const std::string &getCategory() const;

    int getCurrentPrice() const;

    const std::vector<std::tuple<int, std::string, int> > &getOffers() const;

    void setName(const std::string &name);

    void setCategory(const std::string &category);

    void setCurrentPrice(int price);

    void addOffer(int userId, const std::string &date, int sum);

    std::string toString() const;
};

#endif // ITEM_H
