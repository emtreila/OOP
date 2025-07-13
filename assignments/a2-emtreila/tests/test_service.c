#include "test_service.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "./service/Service.h"
#include "./repository/Repo.h"
#include "./structures//DynamicArray.h"

void test_addEstateService() {
    EstateRepo repo = createRepository();
    EstateService service = createService(repo);

    bool added = addEstateService(&service, HOUSE, "Address 1", 100.5, 50000);
    assert(added == true);

    added = addEstateService(&service, HOUSE, "Address 1", 120.5, 55000);
    assert(added == false);

    destroyService(&service);
}

void test_updateEstateService() {
    EstateRepo repo = createRepository();
    EstateService service = createService(repo);

    addEstateService(&service, HOUSE, "Address 1", 100.5, 50000);

    bool updated = updateEstateService(&service, HOUSE, "Address 1", 150.0, 60000);
    assert(updated == true);

    updated = updateEstateService(&service, HOUSE, "Non-existing Address", 200.0, 70000);
    assert(updated == false);

    destroyService(&service);
}

void test_deleteEstateService() {
    EstateRepo repo = createRepository();
    EstateService service = createService(repo);

    addEstateService(&service, HOUSE, "Address 1", 100.5, 50000);

    bool deleted = deleteEstateService(&service, "Address 1");
    assert(deleted == true); // Estate should be deleted successfully

    deleted = deleteEstateService(&service, "Non-existing Address");
    assert(deleted == false);

    destroyService(&service);
}

void test_estatesWithStringInAddress() {
    EstateRepo repo = createRepository();
    EstateService service = createService(repo);

    addEstateService(&service, HOUSE, "Address 1", 100.5, 50000);
    addEstateService(&service, HOUSE, "Address 2", 120.0, 55000);
    addEstateService(&service, HOUSE, "Another Address", 150.0, 60000);

    DynamicArray estates = estatesWithStringInAddress(&service, "Address");
    assert(estates.size == 3);

    estates = estatesWithStringInAddress(&service, "Another");
    assert(estates.size == 1);

    estates = estatesWithStringInAddress(&service, "");
    assert(estates.size == 3);


    destroyService(&service);
}

void test_estatesWithTypeAndSurface() {
    EstateRepo repo = createRepository();
    EstateService service = createService(repo);


    addEstateService(&service, HOUSE, "Address 1", 100.5, 50000);
    addEstateService(&service, HOUSE, "Address 2", 120.0, 55000);
    addEstateService(&service, APARTMENT, "Apartment 1", 80.0, 35000);
    addEstateService(&service, HOUSE, "Address 3", 150.0, 70000);


    DynamicArray estates = estatesWithTypeAndSurface(&service, HOUSE, 90);
    assert(estates.size == 3);


    estates = estatesWithTypeAndSurface(&service, APARTMENT, 60);
    assert(estates.size == 1);


    destroyService(&service);
}


void test_undoService() {
    EstateRepo repo = createRepository();
    EstateService service = createService(repo);

    addEstateService(&service, HOUSE, "Address 1", 100.5, 50000);
    addEstateService(&service, HOUSE, "Address 2", 120.0, 55000);

    deleteEstateService(&service, "Address 1");

    bool undone = undoService(&service);
    assert(undone == true);

    DynamicArray estates = estatesWithStringInAddress(&service, "Address 1");
    assert(estates.size == 1);

    destroyService(&service);
}

void test_redoService() {
    EstateRepo repo = createRepository();
    EstateService service = createService(repo);

    addEstateService(&service, HOUSE, "Address 1", 100.5, 50000);
    addEstateService(&service, HOUSE, "Address 2", 120.0, 55000);

    deleteEstateService(&service, "Address 1");
    undoService(&service);

    bool redone = redoService(&service);
    assert(redone == true);

    DynamicArray estates = estatesWithStringInAddress(&service, "Address 1");
    assert(estates.size == 0);


    destroyService(&service);
}

void runServiceTests() {
    test_addEstateService();
    test_updateEstateService();
    test_deleteEstateService();
    test_estatesWithStringInAddress();
    test_estatesWithTypeAndSurface();
    test_undoService();
    test_redoService();

    printf("All service tests passed!\n");
}
