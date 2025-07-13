#include "Ui.h"

void Ui::showMenu() {
    std::cout << "\nMENU\n";
    std::cout << "0. EXIT\n";
    std::cout << "1. Add car.\n";
    std::cout << "2. Remove car.\n";
    std::cout << "3. Show all cars.\n";
    std::cout << "4. Show all vintage cars.\n";
}

void Ui::addCarUi(const std::string &name, const std::string &model, int year, const std::string &color) {
    if (this->service.addCarService(name, model, year, color)) {
        std::cout << "Car added successfully!\n";
    } else {
        std::cout << "Car already exists!\n";
    }
}

void Ui::removeCarUi(const std::string &model, int year) {
    if (this->service.removeCarService(model, year)) {
        std::cout << "Car removed successfully!\n";
    } else {
        std::cout << "Car doesn't exist!\n";
    }
}

void Ui::run() {
    int option, year;
    std::string name, model, color;

    while (true) {
        showMenu();
        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 0) {
            std::cout << "Bye, bye!";
            return;
        } else if (option == 1) {
            std::cout << "Enter the name: ";
            std::cin >> name;
            std::cout << "Enter the model: ";
            std::cin >> model;
            std::cout << "Enter the year: ";
            std::cin >> year;
            std::cout << "Enter the color: ";
            std::cin >> color;
            this->addCarUi(name, model, year, color);
        } else if (option == 2) {
            std::cout << "Enter the model: ";
            std::cin >> model;
            std::cout << "Enter the year: ";
            std::cin >> year;
            this->removeCarUi(model, year);
        } else if (option == 3) {
            const DynamicVector<Car> &cars = this->service.getAllService();
            for (int i = 0; i < cars.sizeOfVector(); i++) {
                Car car = cars.getElement(i);
                std::cout << " Name: " << car.getName() << ", Model: " << car.getModel() << ", Year: " << car.getYear()
                        << ", Color: " << car.getColor() << "\n";
            }
        } else if (option == 4) {
            std::cout<<"Vintage cars:\n";
            const DynamicVector<Car> &vintageCars = this->service.getVintageCarsService();
            for (int i = 0; i < vintageCars.sizeOfVector(); i++) {
                Car car = vintageCars.getElement(i);
                std::cout << " Name: " << car.getName() << ", Model: " << car.getModel() << ", Year: " << car.getYear()
                        << ", Color: " << car.getColor() << "\n";
            }
        }
    }
}
