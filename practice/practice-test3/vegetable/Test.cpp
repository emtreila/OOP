//
// Created by mela on 29.05.2025.
//

#include "Test.h"

#include <iostream>

#include "Service.h"

void Test::testFunction() {
    // test the getVegetableByName function
    Repo repo;
    Service service(repo);
    Vegetable veg = service.getVegetableByName("Onion");
    if (veg.getName() == "Onion") {
        std::cout << "Test passed: Vegetable found." << std::endl;
    } else {
        std::cout << "Test failed: Vegetable not found." << std::endl;
    }
}
