#include "Ui.h"

#include <iostream>

#include "DishWasher.h"
#include "Refrigerator.h"

void Ui::showMenu() const {
    std::cout << "1. Add appliance" << std::endl;
    std::cout << "2. Show all appliances" << std::endl;
    std::cout << "3. Show inefficient appliances" << std::endl;
    std::cout << "4. Write to file" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void Ui::addApplianceUi() {
    std::string type;
    std::string id;
    std::string electricityClass;
    std::string hasFreezer;
    double consumedElectricity;
    std::cout << "Enter appliance type: ";
    std::cin >> type;
    std::cout << "Enter appliance id: ";
    std::cin >> id;
    if (type == "refrigerator") {
        std::cout << "Enter the electricity usage class: ";
        std::cin >> electricityClass;
        std::cout << " Does it have a freezer? (yes/no): ";
        std::cin >> hasFreezer;
        if (hasFreezer == "yes") {
            Appliance *a = new Refrigerator(id, electricityClass, true);
            this->service.addAppliance(a);
        } else {
            Appliance *a = new Refrigerator(id, electricityClass, false);
            this->service.addAppliance(a);
        }
    } else if (type == "dish_washer") {
        std::cout << "Enter consumed electricity for one hour: ";
        std::cin >> consumedElectricity;
        Appliance *a = new DishWasher(id, consumedElectricity);
        this->service.addAppliance(a);
    } else {
        std::cout << "Invalid appliance type." << std::endl;
    }
}

void Ui::getAllAppliancesUi() const {
    std::vector<Appliance *> appliances = this->service.getAllAppliances();
    for (const auto appliance : appliances) {
        std::cout << appliance->toString() << std::endl;
    }
}

void Ui::getAllWithConsumedElectricityLessThanUi() const {
    std::vector<Appliance *> appliances = this->service.getAllWithConsumedElectricityLessThan(100);
    std::cout<<"Inefficient appliances: "<<std::endl;
    for (const auto appliance : appliances) {
        std::cout << appliance->toString() << std::endl;
    }
}

void Ui::writeToFileUi() const {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    this->service.writeToFile(filename);
}


void Ui::run() {
    int option;
    while (true) {
        this->showMenu();
        std::cout << "Choose an option: ";
        std::cin >> option;
        if (option == 1) {
            this->addApplianceUi();
        } else if (option == 2) {
            this->getAllAppliancesUi();
        } else if (option == 3) {
            this->getAllWithConsumedElectricityLessThanUi();
        } else if (option == 4) {
            this->writeToFileUi();
        } else if (option == 5) {
            std::cout << "Exiting..." << std::endl;
            exit(0);
        } else {
            std::cout << "Invalid option. Try again." << std::endl;
        }
    }
}
