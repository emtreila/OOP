//
// Created by mela on 28.05.2025.
//

#ifndef VEGETABLE_H
#define VEGETABLE_H
#include <string>


class Vegetable {
private:
    std::string family;
    std::string name;
    std::string parts;

public:
    Vegetable();

    explicit Vegetable(const std::string &family, const std::string &name, const std::string &parts);

    ~Vegetable() = default;

    std::string getFamily();

    std::string getName();

    std::string getParts();
};


#endif //VEGETABLE_H
