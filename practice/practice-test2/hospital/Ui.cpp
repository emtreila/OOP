#include "Ui.h"

#include <iostream>
#include <ostream>

#include "NeonatalUnit.h"
#include "Surgery.h"

void Ui::showMenu() {
    std::cout << "1. Add Department" << std::endl;
    std::cout << "2. Show All Departments" << std::endl;
    std::cout << "3. Show Efficient Departments" << std::endl;
    std::cout << "4. Write to File" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void Ui::addDepartmentUi() {
    std::string hospitalName, departmentName;
    int numberOfDoctors, numberOfPatients, numberOfNewborns, numberOfMothers;
    double averageGrade;

    std::cout << "Enter hospital name: ";
    std::cin >> hospitalName;
    std::cout << "Enter number of doctors: ";
    std::cin >> numberOfDoctors;
    std::cout << "Enter department name: ";
    std::cin >> departmentName;
    if (departmentName == "surgery") {
        std::cout<<"Enter number of patients: ";
        std::cin >> numberOfPatients;
        HospitalDepartment *department = new Surgery(hospitalName, numberOfDoctors, numberOfPatients);
        this->controller.addDepartment(department);
    }
    else if (departmentName == "neonatal_unit") {
        std::cout<<"Enter number of newborns: ";
        std::cin >> numberOfNewborns;
        std::cout<<"Enter number of mothers: ";
        std::cin >> numberOfMothers;
        std::cout<<"Enter average grade: ";
        std::cin >> averageGrade;
        HospitalDepartment *department = new NeonatalUnit(hospitalName, numberOfDoctors, numberOfMothers, numberOfNewborns, averageGrade);
        this->controller.addDepartment(department);
    }
}

void Ui::showAllDepartmentsUi() {
    std::vector<HospitalDepartment *> departments = this->controller.getAllDepartments();
    std::cout<<"All departments: " << std::endl;
    for (auto department: departments) {
        std::cout << department->toString()<<"\n";;
    }
}

void Ui::showEfficientDepartmentsUi() {
    std::vector<HospitalDepartment *> departments = this->controller.getAllEfficientDepartments();
    std::cout<<"Efficient departments: " << std::endl;
    for (auto department: departments) {
        std::cout << department->toString() << std::endl;
    }
}

void Ui::writeToFileUi() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    try {
        this->controller.writeToFile(filename);
        std::cout << "Data written to file successfully." << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Error writing to file: " << e.what() << std::endl;
    }
}

void Ui::run() {
    int option;
    HospitalDepartment *department = new Surgery("hospital", 5, 10);
    this->controller.addDepartment(department);
    department = new NeonatalUnit("hospital", 5, 10, 10, 9.5);
    this->controller.addDepartment(department);

    while (true) {
        showMenu();
        std::cout<<"Choose an option: ";
        std::cin >> option;

        if (option == 1) {
            addDepartmentUi();
        } else if (option == 2) {
            showAllDepartmentsUi();
        } else if (option == 3) {
            showEfficientDepartmentsUi();
        } else if (option == 4) {
            writeToFileUi();
        } else if (option == 5) {
            std::cout<<"Bye!"<<std::endl;
            exit(1);
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}
