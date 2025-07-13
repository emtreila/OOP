#include "Estate.h"
#include <string.h>

Estate createEstate(EstateType type, char address[ADDRESS_LENGTH], double surface, double price) {
    //create a new estate with the given parameters
    Estate estate;

    estate.type = type;
    strcpy(estate.address, address);
    estate.surface = surface;
    estate.price = price;

    return estate;
}

char *getType(Estate *estate) {
    //return the type of the estate as a string
    switch (estate->type) {
        case HOUSE:
            return "house";
        case APARTMENT:
            return "apartment";
        case PENTHOUSE:
            return "penthouse";
        default:
            return "unknown";
    }
}

char *getAddress(Estate *estate) {
    //return the address of the estate
    return estate->address;
}

double getSurface(Estate *estate) {
    //return the surface of the estate
    return estate->surface;
}

double getPrice(Estate *estate) {
    //return the price of the estate
    return estate->price;
}

void setType(Estate *estate, EstateType newType) {
    //set the type of the estate
    estate->type = newType;
}

void setAddress(Estate *estate, char newAddress[101]) {
    //set the address of the estate
    strcpy(estate->address, newAddress);
}

void setSurface(Estate *estate, double newSurface) {
    //set the surface of the estate
    estate->surface = newSurface;
}

void setPrice(Estate *estate, double newPrice) {
    //set the price of the estate
    estate->price = newPrice;
}
