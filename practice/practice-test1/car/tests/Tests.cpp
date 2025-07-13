#include "Tests.h"

void Tests::testAddRepo() {
    Repo repo;

    assert(repo.addCar(Car("Toyota", "Camry", 2020, "red")) == true);
    assert(repo.addCar(Car("Honda", "Civic", 2018, "blue")) == true);
    assert(repo.addCar(Car("Ford", "Focus", 2019, "white")) == true);

    assert(repo.addCar(Car("Toyota", "Camry", 2020, "red")) == false);
    assert(repo.addCar(Car("Honda", "Civic", 2018, "blue")) == false);

    const auto &cars = repo.getAll();
    assert(cars.sizeOfVector() == 3);

    std::cout << "All addCar tests passed!" << std::endl;
}

void Tests::testAddService() {
    Repo repo;
    Service service(repo);

    assert(service.addCarService("Toyota", "Camry", 2020, "Red") == true);
    assert(service.addCarService("Honda", "Civic", 2018, "Blue") == true);
    assert(service.addCarService("Ford", "Focus", 2019, "Black") == true);

    assert(service.addCarService("Toyota", "Camry", 2020, "Red") == false);
    assert(service.addCarService("Honda", "Civic", 2018, "Blue") == false);

    const auto &cars = repo.getAll();
    assert(cars.sizeOfVector() == 3);

    std::cout << "All addCarService tests passed!" << std::endl;
}

void Tests::testVintageCars() {
    Repo repo;
    Service service(repo);

    repo.addCar(Car("Ford", "Mustang", 1967, "Red"));
    repo.addCar(Car("Chevrolet", "Camaro", 1975, "Blue"));
    repo.addCar(Car("Volkswagen", "Beetle", 1950, "Yellow"));
    repo.addCar(Car("Toyota", "Corolla", 1995, "White"));
    repo.addCar(Car("Honda", "Civic", 2005, "Black"));

    auto result = service.getVintageCarsService();
    assert(result.sizeOfVector() == 3);

    assert(result.getElement(0).getColor() == "Blue");
    assert(result.getElement(1).getColor() == "Red");
    assert(result.getElement(2).getColor() == "Yellow");
    
    std::cout << "All getVintageCarsService tests passed!" << std::endl;
}

void Tests::runTests() {
    testAddRepo();
    testAddService();
    testVintageCars();
}
