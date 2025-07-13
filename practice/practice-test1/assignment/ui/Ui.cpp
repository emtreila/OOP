#include "Ui.h"

void Ui::showMenu() {
    std::cout<<"\nMENU\n";
    std::cout << "0. Exit.\n";
    std::cout << "1. Add assignment.\n";
    std::cout << "2. Show all assignments.\n";
}

void Ui::addAssignmentUi(int id, std::string name, std::string solution) {
    const DynamicVector<Assignment> &assignments = this->service.getAssignments();
    try {
        id = int(id);
    } catch (std::exception &e) {
        std::cout << "Invalid id.\n";
        return;
    }

    for (int i = 0; i < assignments.sizeOfVector(); i++) {
        if (assignments.getElement(i).getId() == id) {
            std::cout << "Assignment already exists.\n";
            return;
        }
    }

    try {
        name = std::string(name);
    } catch (std::exception &e) {
        std::cout << "Invalid name.\n";
        return;
    }

    if (name.empty()) {
        std::cout << "Invalid name.\n";
        return;
    } else if (name.size() < 3) {
        std::cout << "Name too short.\n";
        return;
    }

    try {
        solution = std::string(solution);
    } catch (std::exception &e) {
        std::cout << "Invalid solution.\n";
        return;
    }

    if (solution.empty()) {
        std::cout << "Invalid solution.\n";
        return;
    }

    if (this->service.addAssignmentService(id, name, solution)) {
        std::cout << "Assignment added successfully.\n";
    } else {
        std::cout << "Assignment could not be added.\n";
    }
}

void Ui::run() {
    int option, id;
    std::string name, solution;



    while (true) {
        showMenu();
        std::cout<<"Choose an option: ";
        std::cin>>option;

        if (option == 0) {
            std::cout<<"Bye, bye!";
        }
        else if ( option == 1) {
            std::cout<<"Enter the id: ";
            std::cin>>id;
            std::cout<<"Enter the name: ";
            std::cin>>name;
            std::cout<<"Enter the solution: ";
            std::cin>>solution;

            addAssignmentUi(id, name, solution);
        }
        else if (option == 2) {
            const DynamicVector<Assignment> &assignments = this->service.getAssignments();
            for (int i = 0; i < assignments.sizeOfVector(); i++) {
                Assignment assignment = assignments.getElement(i);
                std::cout <<"Id: " << assignment.getId() << ", Name: " << assignment.getName() << ", Solution: " << assignment.getSolution() << "\n";
            }
        }
        else if (option == 3) {

        }
    }
}
