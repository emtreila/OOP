#include "Ui.h"


void Ui::showMenu() {
    std::cout << "Menu:" << "\n";
    std::cout << "1. Add analysis\n";
    std::cout << "2. Show all analyses\n";
    std::cout << "3. Check if person is ill\n";
    std::cout << "4. Write to file\n";
    std::cout << "0. Exit\n";
}

void Ui::addAnalysisUi() {
    std::string type;
    std::string date;
    int sysvalue;
    int diavalue;
    double value;
    std::cout << "Enter analysis type: ";
    std::cin >> type;
    std::cout << "Enter analysis date: ";
    std::cin >> date;
    if (type == "BMI") {
        std::cout << "Enter BMI value: ";
        std::cin >> value;
        MedicalAnalysis *analysis = new BMI(date, value);
        this->service.addAnalysisService(analysis);
    } else if (type == "BP") {
        std::cout << "Enter systolic value: ";
        std::cin >> sysvalue;
        std::cout << "Enter diastolic value: ";
        std::cin >> diavalue;
        MedicalAnalysis *analysis = new BP(date, sysvalue, diavalue);
        this->service.addAnalysisService(analysis);
    } else {
        std::cout << "Invalid analysis type." << "\n";
    }
}

void Ui::showAllAnalysesUi() {
    std::vector<MedicalAnalysis *> analyses = this->service.getAllAnalysesService();
    for (auto analyse: analyses) {
        std::cout << analyse->toString() << "\n";
    }
}

void Ui::isIllUi() {
    int month;
    std::cout << "Enter month: ";
    std::cin >> month;
    if (this->service.isIllService(month)) {
        std::cout << "Person is ill." << "\n";
    } else {
        std::cout << "Person is healthy." << "\n";
    }
}

void Ui::writeToFileUi() {
    std::string filename;
    std::string date1;
    std::string date2;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    std::cout << "Enter start date (YYYY.MM.DD): ";
    std::cin >> date1;
    std::cout << "Enter end date (YYYY.MM.DD): ";
    std::cin >> date2;
    this->service.writeToFileService(filename, date1, date2);
}

void Ui::run() {
    int option;
    std::string name;

    BMI *bmi = new BMI("2025.01.01", 20);
    this->service.addAnalysisService(bmi);
    BP *bp = new BP("2025.01.01", 120, 80);
    this->service.addAnalysisService(bp);

    while (true) {
        this->showMenu();
        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 0) {
            std::cout << "Exiting..." << "\n";
            exit(1);
        } else if (option == 1) {
            this->addAnalysisUi();
        } else if (option == 2) {
            this->showAllAnalysesUi();
        } else if (option == 3) {
            this->isIllUi();
        } else if (option == 4) {
            this->writeToFileUi();
        } else {
            std::cout << "Invalid option. Try again." << "\n";
        }
    }
}
