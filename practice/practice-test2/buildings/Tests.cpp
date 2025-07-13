#include "Tests.h"

#include <cassert>
#include <iostream>
#include <ostream>

#include "Block.h"
#include "Controller.h"
#include "House.h"

void Tests::runTests() {
    testAddBuilding();
    std::cout<<"testAddBuilding passed!"<<std::endl;
    testGetAllBuildings();
    std::cout<<"testGetAllBuildings passed!"<<std::endl;

}

void Tests::testGetAllBuildings() {
    Controller controller;

    Building *building1 = new Block("Building 1", 2000, 5, 10);
    Building *building2 = new House("Building 2", 1990, "Villa", true);
    Building *building3 = new Block("Building 3", 2010, 10, 20);

    controller.addBuilding(building1);
    controller.addBuilding(building2);
    controller.addBuilding(building3);

    std::vector<Building *> buildings = controller.getAllBuildings();

    assert(buildings[0]->getConstructionYear() == 1990);
    assert(buildings[1]->getConstructionYear() == 2000);
    assert(buildings[2]->getConstructionYear() == 2010);

    delete building1;
    delete building2;
    delete building3;
}

void Tests::testAddBuilding() {
    Controller controller;

    Building *building1 = new Block("Building 1", 2000, 5, 10);
    Building *building2 = new House("Building 2", 1990, "Villa", true);

    controller.addBuilding(building1);
    controller.addBuilding(building2);

    std::vector<Building *> buildings = controller.getAllBuildings();

    assert(buildings.size() == 2);
    assert(buildings[0]->getAddress() == "Building 1");
    assert(buildings[1]->getAddress() == "Building 2");

    delete building1;
    delete building2;
}