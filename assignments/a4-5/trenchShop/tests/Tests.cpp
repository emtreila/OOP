#include "Tests.h"

#include "../domain/TrenchCoat.h"
#include "../repository/Repo.h"
#include "../service/Service.h"

#include <cassert>
#include <iostream>

void Tests::runDomainTests() {
    TrenchCoat coat1("M", "red", 100, 5, "https://www.google.com");

    // Test getters
    assert(coat1.getSize() == "M");
    assert(coat1.getColour() == "red");
    assert(coat1.getPrice() == 100);
    assert(coat1.getQuantity() == 5);
    assert(coat1.getPhotograph() == "https://www.google.com");

    // Test setters
    coat1.setSize("S");
    coat1.setColour("blue");
    coat1.setPrice(200);
    coat1.setQuantity(10);
    coat1.setPhotograph("https://www.facebook.com");

    assert(coat1.getSize() == "S");
    assert(coat1.getColour() == "blue");
    assert(coat1.getPrice() == 200);
    assert(coat1.getQuantity() == 10);
    assert(coat1.getPhotograph() == "https://www.facebook.com");

    // Test equality operator
    TrenchCoat coat2("S", "blue", 200, 10, "https://www.facebook.com");
    assert(coat1 == coat2);

    // Test copy constructor
    TrenchCoat coat3(coat1);
    assert(coat1 == coat3);

    // Test destructor
    TrenchCoat *coat4 = new TrenchCoat("S", "blue", 200, 10, "https://www.facebook.com");
    delete coat4;

    // Test for initial constructor
    TrenchCoat coat5;
    assert(coat5.getSize() == "");
    assert(coat5.getColour() == "");
    assert(coat5.getPrice() == 0);
    assert(coat5.getQuantity() == 0);
    assert(coat5.getPhotograph() == "");
}

void Tests::runRepoTests() {
    // Test addCoat()
    Repo repo;
    TrenchCoat coat1("M", "Red", 100, 10, "https://example.com");
    assert(repo.addCoat(coat1) == true); // Should succeed
    assert(repo.addCoat(coat1) == false); // Should fail (duplicate)
    assert(repo.getCoatsSize() == 1); // Only one coat should be in the repo

    // Test findCoat()
    TrenchCoat coat2("L", "Blue", 120, 5, "https://example.com");
    repo.addCoat(coat2);
    TrenchCoat found = repo.findCoat("L", "Blue");
    assert(found.getSize() == "L");
    assert(found.getColour() == "Blue");


    // Test removeCoat()
    TrenchCoat coat3("S", "Green", 90, 3, "https://example.com");
    repo.addCoat(coat3);
    assert(repo.removeCoat("S", "Green") == true); // Should succeed
    assert(repo.removeCoat("S", "Green") == false); // Should fail (already removed)

    // Test updateCoat()
    TrenchCoat updatedCoat("M", "Red", 110, 12, "https://example.com");
    assert(repo.updateCoat(updatedCoat) == true); // Should succeed

    // Test getAll()
    TrenchCoat coat4("XS", "White", 110, 4, "https://example.com");
    TrenchCoat coat5("XL", "Brown", 130, 6, "https://example.com");
    repo.addCoat(coat4);
    repo.addCoat(coat5);
    assert(repo.getAll().sizeOfVector() == 4);

    // Test getCoat()
    TrenchCoat coat6("XXL", "Gray", 140, 2, "https://example.com");
    repo.addCoat(coat6);
    TrenchCoat retrieved = repo.getCoat(4); // Index of coat6
    assert(retrieved.getSize() == "XXL");
    assert(retrieved.getColour() == "Gray");

    std::cout << "All tests passed successfully!" << std::endl;
}

void Tests::runServiceTests() {
    Repo repo;
    Service service(repo);

    // Test addCoatService()
    assert(service.addCoatService("M", "Red", 100.0, 10, "https://example.com") == true); // Should succeed
    assert(service.addCoatService("M", "Red", 100.0, 10, "https://example.com") == false); // Should fail (duplicate)
    assert(service.getCoatsSizeService() == 1); // Only one coat should be in the service

    // Test removeCoatService()
    assert(service.removeCoatService("M", "Red") == true); // Should succeed
    assert(service.removeCoatService("M", "Red") == false); // Should fail (already removed)

    // Test updateCoatService()
    service.addCoatService("L", "Blue", 120.0, 5, "https://example.com");
    TrenchCoat updatedCoat("L", "Blue", 130.0, 6, "https://example.com"); // Updated price and quantity
    assert(service.updateCoatService(updatedCoat) == true); // Should succeed

    // Test getAllService()
    service.addCoatService("S", "Green", 90.0, 3, "https://example.com");
    service.addCoatService("XL", "Brown", 130.0, 6, "https://example.com");
    assert(service.getAllService().sizeOfVector() == 3);

    // Test getCoatService()
    TrenchCoat coat = service.getCoatService(0);
    assert(coat.getSize() == "L");
    assert(coat.getColour() == "Blue");
}


void Tests::runTests() {
    runDomainTests();
    runRepoTests();
    runServiceTests();
}
