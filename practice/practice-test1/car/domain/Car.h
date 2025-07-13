#ifndef CAR_H
#define CAR_H
#include <string>


class Car {
private:
    std::string name;
    std::string model;
    int year;
    std::string color;

public:
    Car();

    Car(const std::string &name,
        const std::string &model,
        int year,
        const std::string &color);

    ~Car();

    Car(const Car &car);

    const std::string &getName() const;

    const std::string &getModel() const;

    int getYear() const;

    const std::string &getColor() const;

    void setName(const std::string &newName);

    void setModel(const std::string &newModel);

    void setYear(int newYear);

    void setColor(const std::string &newColor);

    bool operator==(const Car &car) const;


};


#endif //CAR_H
