#include "Ui.h"

void Ui::showMenu() {
    std::cout << "\nMENU\n";
    std::cout << "0. EXIT\n";
    std::cout << "1. Add school.\n";
    std::cout << "2. Show all schools.\n";
    std::cout << "3. Show 3 closest schools.\n";
}

void Ui::addSchoolUi(const std::string &name, float address_long, float address_lat, int day, int month, int year) {
    if (this->service.addSchoolService(name, address_long, address_lat, day, month, year)) {
        std::cout << "School added successfully!\n";
    } else {
        std::cout << "School already exists!\n";
    }
}

void Ui::run() {
    int option;
    std::string name;
    float address_long, address_lat;
    int day, month, year;

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
            std::cout << "Enter the longitude: ";
            std::cin >> address_long;
            std::cout << "Enter the latitude: ";
            std::cin >> address_lat;
            std::cout << "Enter the day: ";
            std::cin >> day;
            std::cout << "Enter the month: ";
            std::cin >> month;
            std::cout << "Enter the year: ";
            std::cin >> year;

            this->addSchoolUi(name, address_long, address_lat, day, month, year);
        } else if (option == 2) {
            const DynamicVector<School> &schools = this->service.getAllSchoolsName();

            for (int i = 0; i < schools.sizeOfVector(); i++) {
                School school = schools.getElement(i);
                std::cout << " Name: " << school.getName() << ", Address: " << school.getLong() << ", : " << school.
                        getAlt() << ", Date: " << school.getDay() << "." << school.getMonth() << "." << school.getYear()
                        << "\n";
            }
        } else if (option == 3) {
            std::cout << "Enter the longitude: ";
            std::cin >> address_long;
            std::cout << "Enter the latitude: ";
            std::cin >> address_lat;
            // DynamicVector<School> mock = service.getAllSchoolsName();
            // for (int i = 0; i<3; i++) {
            //     School closest[3];
            //     service.closestSchools(address_long,address_lat,&closest[3], mock);
            //     for (int j=0; j<=)
            // }
        }
    }
}
