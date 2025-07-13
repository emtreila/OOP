#include <iostream>

#include "Person.h"
#include "Ui.h"

int main() {
    std::string name;
    std::cout << "Enter the name of the person: ";
    std::cin >> name;

    Person person(name);
    Service service(person);
    Ui ui(service);

    ui.run();

    return 0;
}
