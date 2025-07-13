#include "Ui.h"

#include <iostream>

void Ui::showMenu() {
    std::cout<<"1. Add car\n";
    std::cout<<"2. Get cars with max price\n";
    std::cout<<"3. Write to file\n";
    std::cout<<"4. Exit\n";
}

void Ui::addCarUi() {
    std::string bodyStyle;
    std::string engineType;
    int autonomy;

    std::cout << "Enter body style: ";
    std::cin >> bodyStyle;
    std::cout << "Enter engine type: ";
    std::cin >> engineType;
    std::cout << "Enter autonomy: ";
    std::cin >> autonomy;

    this->service.addCar(bodyStyle, engineType, autonomy);
}

void Ui::getCars() {

    std::vector<Car *> cars = this->service.getCars();
    for (auto car: cars) {
        std::cout<<car->computePrice();
    }
}

void Ui::writeToFileUi() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    this->service.writeToFile(filename, this->service.getCars());
}
void Ui::run() {
    int option;

    while (true) {
        this->showMenu();
        std::cout << "Enter option: ";
        std::cin >> option;

        if (option == 1) {
            this->addCarUi();
        } else if (option == 2) {
            this->getCars();
        } else if (option == 3) {
            //this->writeToFileUi();
        } else if (option == 4) {
            std::cout<<"Bye!\n";
            exit(0);
        } else {
            std::cout << "Invalid option\n";
        }
    }
}