#ifndef ESTATE_H
#define ESTATE_H

#define ADDRESS_LENGTH 101

typedef enum {
    HOUSE,
    APARTMENT,
    PENTHOUSE
} EstateType;

typedef struct {
    EstateType type;
    char address[ADDRESS_LENGTH];
    double surface;
    double price;
} Estate;

//creates a new estate
Estate createEstate(EstateType type, char address[ADDRESS_LENGTH], double surface, double price);

//getters and setters
char *getType(Estate *estate);

char *getAddress(Estate *estate);

double getSurface(Estate *estate);

double getPrice(Estate *estate);

void setType(Estate *estate, EstateType newType);

void setAddress(Estate *estate, char newAddress[101]);

void setSurface(Estate *estate, double newSurface);

void setPrice(Estate *estate, double newPrice);

#endif //ESTATE_H
