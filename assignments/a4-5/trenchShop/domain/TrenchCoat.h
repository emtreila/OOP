#ifndef TRENCHCOAT_H
#define TRENCHCOAT_H

#include <iostream>
#include <string>

class TrenchCoat {
private:
    std::string size;
    std::string colour;
    double price;
    unsigned int quantity;
    std::string photograph;

public:
    // implicit constructor
    TrenchCoat();

    // explicit constructor
    TrenchCoat(const std::string &size,
               const std::string &colour,
               double price,
               unsigned int quantity,
               const std::string &photograph);

    // destroyer
    ~TrenchCoat();

    // copy constructor
    TrenchCoat(const TrenchCoat &t);


    // GETTERS AND SETTERS
    std::string getSize() const;

    std::string getColour() const;

    double getPrice() const;

    unsigned int getQuantity() const;

    std::string getPhotograph() const;

    void setSize(const std::string newSize);

    void setColour(const std::string newColour);

    void setPrice(double newPrice);

    void setQuantity(unsigned int newQuantity);

    void setPhotograph(const std::string newPhotograph);

    bool operator==(const TrenchCoat &t) const;
};

#endif //TRENCHCOAT_H
