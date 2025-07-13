//
// Created by mela on 25.05.2025.
//

#ifndef CAR_H
#define CAR_H
#include <string>


class Car {
private:
    std::string model;
    std::string name;
    int year;
    std::string color;

public:
    Car();

    Car(const std::string &name, const std::string &model, int year, const std::string &color);

    ~Car() = default;

    const std::string &getModel() const;

    void setModel(const std::string &model);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getYear() const;

    void setYear(int year);

    const std::string &getColor() const;

    void setColor(const std::string &color);

    std::string toString() const;
};


#endif //CAR_H
