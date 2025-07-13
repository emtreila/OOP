#include "Ui.h"

void Ui::showMenu() {
    std::cout<<"\nMENU\n";
    std::cout<<"0. EXIT\n";
    std::cout<<"1. Remove school.\n";
    std::cout<<"2. Show all schools.\n";
    std::cout<<"3. Show all schools that have to be visited.\n";
}

void Ui::removeSchoolUi(const std::string &name, float address_long, float address_lat) {
    if (this->service.removeSchoolService(name, address_long, address_lat)) {
        std::cout<<"School removed successfully!\n";
    } else {
        std::cout<<"School doesn't exist!\n";
    }
}

void Ui::run() {
    int option;
    std::string name;
    float address_long, address_lat;
    int day, month, year;
    bool visited;

    while (true) {
        showMenu();
        std::cout<<"Choose an option: ";
        std::cin>>option;

        if (option == 0) {
            std::cout<<"Bye, bye!";
            return;
        }
        else if (option == 1) {
            std::cout<<"Enter the name: ";
            std::cin>>name;
            std::cout<<"Enter the longitude: ";
            std::cin>>address_long;
            std::cout<<"Enter the latitude: ";
            std::cin>>address_lat;
            this->removeSchoolUi(name, address_long, address_lat);
        }

        else if (option == 2) {
            const DynamicVector<School> &schools = this->service.getAllSchoolsName();

            for (int i = 0; i < schools.sizeOfVector(); i++) {
                School school = schools.getElement(i);
                std::cout<<" Name: "<<school.getName()<<", Address: "<<school.getLong()<<", : "<<school.getAlt()<<", Date: "<<school.getDay()<<"."<<school.getMonth()<<"."<<school.getYear()<<", Visited: "<<school.getVisited()<<"\n";
            }
        }
        else if (option == 3) {
            std::cout<<"Enter the day: ";
            std::cin>>day;
            std::cout<<"Enter the month: ";
            std::cin>>month;
            std::cout<<"Enter the year: ";
            std::cin>>year;
            DynamicVector<School> schools = this->service.getVisitSchools(day, month, year);

            for (int i = 0; i < schools.sizeOfVector(); i++) {
                School school = schools.getElement(i);
                std::cout<<" Name: "<<school.getName()<<", Address: "<<school.getLong()<<", "<<school.getAlt()<<", Date: "<<school.getDay()<<"."<<school.getMonth()<<"."<<school.getYear()<<", Visited: "<<school.getVisited()<<"\n";
            }
        }
    }
}
