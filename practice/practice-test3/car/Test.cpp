//
// Created by mela on 28.05.2025.
//

#include "Test.h"

#include <cassert>
#include <iostream>

#include "Service.h"

void Test::test_getCarsByManufacturer() {
    Repo repo;
    Service service(repo);

    auto toyotaCars = service.getCarsByManufacturer("Fiat");
    assert(toyotaCars.size() == 2);

    auto fordCars = service.getCarsByManufacturer("Audi");
    assert(fordCars.size() == 1);

    auto ladaCars = service.getCarsByManufacturer("Porsche");
    assert(ladaCars.empty());

    std::cout << "All manufacturer count tests passed!\n";
}
