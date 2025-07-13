#include "Ui.h"

#include <iostream>

#include "Block.h"
#include "House.h"

void Ui::showMenu() const {
    std::cout << std::endl;
    std::cout << "Menu: " << std::endl;
    std::cout << "1. Add building" << std::endl;
    std::cout << "2. Show all buildings" << std::endl;
    std::cout << "3. Save all buildings that must be restored to a file and that must be demolished to another file." <<
            std::endl;
    std::cout << "0. Exit" << std::endl;
}

bool Ui::checkAddress(Building *building) {
    for (auto b: this->controller.getAllBuildings()) {
        if (b->getAddress() == building->getAddress()) {
            return false;
        }
    }
    return true;
}

void Ui::addBuildingUi() {
    std::string address, building, type, historicalHouse;
    int constructionYear, totalNoOfApartments, occupiedApartments;
    std::cout << "Enter address: ";
    std::cin >> address;
    std::cout << "Enter construction year: ";
    std::cin >> constructionYear;
    std::cout << "Enter type (house, block): ";
    std::cin >> building;
    if (building == "house") {
        std::cout << "Enter the house type: ";
        std::cin >> type;
        std::cout << "Is it a historical house? (yes/no): ";
        std::cin >> historicalHouse;
        if (historicalHouse == "yes") {
            Building *b = new House(address, constructionYear, type, true);
            if (!this->checkAddress(b)) {
                std::cout << "This address already exists." << std::endl;
                return;
            }
            this->controller.addBuilding(b);
        } else {
            Building *b = new House(address, constructionYear, type, false);
            if (!this->checkAddress(b)) {
                std::cout << "This address already exists." << std::endl;
                return;
            }
            this->controller.addBuilding(b);
        }
    } else {
        std::cout << "Enter total number of apartments: ";
        std::cin >> totalNoOfApartments;
        std::cout << "Enter number of occupied apartments: ";
        std::cin >> occupiedApartments;
        Building *b = new Block(address, constructionYear, totalNoOfApartments, occupiedApartments);
        if (!this->checkAddress(b)) {
            std::cout << "This address already exists." << std::endl;
            return;
        }
        this->controller.addBuilding(b);
    }
}

void Ui::getAllBuildingsUi() const {
    std::vector<Building *> buildings = this->controller.getAllBuildings();
    std::cout << "All buildings: " << std::endl;
    for (const auto building: buildings) {
        std::cout << building->toString() << std::endl;
    }
}

void Ui::writeToFileUi() const {
    std::string filename1 = "buildings_to_be_restored.txt";
    std::string filename2 = "buildings_to_be_demolished.txt";
    std::vector<Building *> buildingsToBeRestored = this->controller.getAllBuildingsToBeRestored();
    std::vector<Building *> buildingsToBeDemolished = this->controller.getAllBuildingsToBeDemolished();
    this->controller.writeToFile(filename1, buildingsToBeRestored);
    this->controller.writeToFile(filename2, buildingsToBeDemolished);
    std::cout<< "Buildings to be restored and demolished have been written to files." << std::endl;
}



void Ui::run() {
    int option;

    Block b("Bucuresti", 2000, 10, 5);
    House h("Constanta", 2000, "Vila", true);
    this->controller.addBuilding(&b);
    this->controller.addBuilding(&h);

    while (true) {
        this->showMenu();
        std::cout << "Enter option: ";
        std::cin >> option;
        if (option == 0) {
            std::cout << "Exiting..." << std::endl;
            exit(0);
        } else if (option == 1) {
            this->addBuildingUi();
        } else if (option == 2) {
            this->getAllBuildingsUi();
        } else if (option == 3) {
            this->writeToFileUi();
        } else {
            std::cout << "Invalid option. Try again." << std::endl;
        }
    }
}
