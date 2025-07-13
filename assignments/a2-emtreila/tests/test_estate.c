#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "./domain/Estate.h"

void testCreateEstate() {
    Estate estate = createEstate(HOUSE, "123 Main St", 120.5, 250000);
    assert(estate.type == HOUSE);
    assert(strcmp(estate.address, "123 Main St") == 0);
    assert(estate.surface == 120.5);
    assert(estate.price == 250000);
}

void testGetType() {
    Estate estate = createEstate(PENTHOUSE, "456 Luxury Ave", 200.0, 500000);
    assert(strcmp(getType(&estate), "penthouse") == 0);
    estate.type = APARTMENT;
    assert(strcmp(getType(&estate), "apartment") == 0);
    estate.type = HOUSE;
    assert(strcmp(getType(&estate), "house") == 0);
}

void testGetAddress() {
    Estate estate = createEstate(HOUSE, "789 Elm St", 100.0, 150000);
    assert(strcmp(getAddress(&estate), "789 Elm St") == 0);
}

void testGetSurface() {
    Estate estate = createEstate(APARTMENT, "101 Oak St", 80.0, 200000);
    assert(getSurface(&estate) == 80.0);
}

void testGetPrice() {
    Estate estate = createEstate(PENTHOUSE, "202 Skyview Rd", 150.0, 1000000);
    assert(getPrice(&estate) == 1000000);
}

void testSetType() {
    Estate estate = createEstate(HOUSE, "303 Maple Dr", 120.0, 300000);
    setType(&estate, APARTMENT);
    assert(estate.type == APARTMENT);
    setType(&estate, PENTHOUSE);
    assert(estate.type == PENTHOUSE);
}

void testSetAddress() {
    Estate estate = createEstate(HOUSE, "404 Pine Blvd", 130.0, 350000);
    setAddress(&estate, "505 Birch Ave");
    assert(strcmp(estate.address, "505 Birch Ave") == 0);
}

void testSetSurface() {
    Estate estate = createEstate(APARTMENT, "606 Cedar Ln", 90.0, 250000);
    setSurface(&estate, 110.0);
    assert(estate.surface == 110.0);
}

void testSetPrice() {
    Estate estate = createEstate(PENTHOUSE, "707 Maple St", 180.0, 750000);
    setPrice(&estate, 800000);
    assert(estate.price == 800000);
}

void runEstateTests() {
    testCreateEstate();
    testGetType();
    testGetAddress();
    testGetSurface();
    testGetPrice();
    testSetType();
    testSetAddress();
    testSetSurface();
    testSetPrice();
    printf("All domain tests passed!\n");
}