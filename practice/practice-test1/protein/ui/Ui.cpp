#include "Ui.h"

void Ui::showMenu() {
    std::cout << "\nMENU\n";
    std::cout << "0. EXIT\n";
    std::cout << "1. Add a protein.\n";
    std::cout << "2. Show all proteins.\n";
    std::cout << "3. Show all proteins sorted by organism.\n";
}

void Ui::addProteinUi(const std::string &organism, const std::string &name, const std::string &sequence) {

    if (this->service.addProteinService(organism,name,sequence)) {
        std::cout<<"Protein added successfully!\n";
    }
    else {
        std::cout<<"Protein already exists!\n";
    }
}


void Ui::run() {
    int option;
    std::string organism, name, sequence;

    while (true) {
        showMenu();
        std::cout<<"Enter an option: ";
        std::cin>>option;

        if (option == 0) {
            std::cout<<"Bye, bye!\n";
            return;
        }
        else if (option == 1) {
            std::cout<<"Enter the organism: ";
            std::cin>>organism;
            std::cout<<"Enter the name: ";
            std::cin>>name;
            std::cout<<"Enter the sequence: ";
            std::cin>>sequence;
            this->addProteinUi(organism,name,sequence);
        }
        else if (option == 2) {
            const DynamicVector<Protein> &proteins = this->service.getAllService();
            for (int i = 0; i < proteins.sizeOfVector(); i++) {
                Protein protein = proteins.getElement(i);
                std::cout<<"Organism: "<<protein.getOrganism()<<", Name: "<<protein.getName()<<", Sequence: "<<protein.getSequence()<<"\n";
            }
        }
        else if (option == 3) {
            std::cout<<"Enter the name: ";
            std::cin>>name;
            const DynamicVector<Protein> &proteins = this->service.getProteinsByName(name);
            for (int i = 0; i < proteins.sizeOfVector(); i++) {
                Protein protein = proteins.getElement(i);
                std::cout<<"Organism: "<<protein.getOrganism()<<", Name: "<<protein.getName()<<", Sequence: "<<protein.getSequence()<<"\n";
            }
        }
    }
}
