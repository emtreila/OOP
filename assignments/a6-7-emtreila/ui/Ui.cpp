#include "Ui.h"
#include <limits> // for std::numeric_limits
#include <cstring>

#include "../formatter/CSVFormatter.h"
#include "../formatter/HTMLFormatter.h"
#include "../domain/TrenchCoat.h"

Ui::~Ui() {
    if (format != nullptr) {
        delete format;
    }
}

void Ui::showModeMenu() {
    std::cout << "\nCHOOSE A MODE:\n";
    std::cout << "0. EXIT.\n";
    std::cout << "1. Administrator mode.\n";
    std::cout << "2. User mode.\n";
}

void Ui::showAdministratorMenu() {
    std::cout << "\n ADMINISTRATOR MENU \n";
    std::cout << "0. EXIT. \n";
    std::cout << "1. Add a new trench coat.\n";
    std::cout << "2. Remove a trench coat. \n";
    std::cout << "3. Update the information of a trench coat.\n";
    std::cout << "4. See all trench coats in the store. \n";
}


void Ui::showUserMenu() {
    std::cout << "0. EXIT.\n";
    std::cout << "1. Go shopping.\n";
    std::cout << "2. Show shopping basket.\n";
}

void Ui::showShoppingMenu() {
    std::cout << "\n0. EXIT\n";
    std::cout << "1. Add to basket.\n";
    std::cout << "2. Next. (don't add to basket)\n";
}

void Ui::addCoatUi(const std::string &size, const std::string &colour, double price, unsigned int quantity,
                   const std::string &photo) {
    try {
        this->service.addCoatService(size, colour, price, quantity, photo);
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }
}

void Ui::removeCoatUi(const std::string &size, const std::string &colour) {
    try {
        this->service.removeCoatService(size, colour);
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }
}

void Ui::updateCoatUi(const std::string &size, const std::string &colour, double price, unsigned int quantity,
                      const std::string &photo) {
    TrenchCoat newCoat = TrenchCoat(size, colour, price, quantity, photo);
    try {
        this->service.updateCoatService(newCoat);
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }
}

void Ui::seeAllTrenchCoats() {
    const std::vector<TrenchCoat> &coats = this->service.getAllService();
    if (coats.empty()) {
        std::cout << "No trench coats in the store!\n";
        return;
    }

    for (auto &i: coats) {
        std::cout << i;
    }
}


void Ui::goShopping(int &totalPrice) {
    int option;
    std::string givenSize;
    int index = 0;

    const std::vector<TrenchCoat> &coats = this->service.getAllService();
    std::vector<TrenchCoat> bag;

    while (true) {
        std::cout << "Please choose a format (CSV / HTML): ";
        std::cin >> this->selectedFormat;
        if (this->selectedFormat == "CSV") {
            this->format = new CSVFormatter();
            break;
        }
        if (this->selectedFormat == "HTML") {
            this->format = new HTMLFormatter();
            break;
        }
        std::cout << "Invalid option!";
    }

    while (true) {
        showUserMenu();
        std::cout << "Choose an option: ";
        std::cin >> option;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline after int input

        if (option == 0) {
            std::cout << "Bye, bye!\n";
            exit(0);
        } else if (option == 1) {
            std::cout << "Enter the size (or leave empty for all): ";
            std::getline(std::cin, givenSize);

            index = 0;
            bool continueBrowsing = true;

            while (continueBrowsing) {
                if (coats.empty()) {
                    std::cout << "No trench coats available!\n";
                    break;
                }

                if (index >= coats.size()) {
                    index = 0;
                }

                TrenchCoat coat = coats.at(index);

                if (givenSize.empty() || coat.getSize() == givenSize) {
                    std::cout << coat;

                    std::string command = "start " + coat.getPhotograph();
                    system(command.c_str());

                    showShoppingMenu();
                    int shopOption;
                    std::cout << "Choose an option: ";
                    std::cin >> shopOption;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline

                    if (shopOption == 0) {
                        continueBrowsing = false;
                    } else if (shopOption == 1) {
                        bag.push_back(coat);
                        totalPrice += coat.getPrice();
                        this->service.removeCoatService(coat.getSize(), coat.getColour());
                        std::cout << "Trench coat added to basket!\n";
                        std::cout << "Total sum: " << totalPrice << "\n";
                    } else if (shopOption == 2) {
                        std::cout << "Next coat!\n";
                    } else {
                        std::cout << "Invalid choice!\n";
                    }
                }
                index++;
            }
        } else if (option == 2) {
            std::string filename;
            std::cout << "Enter the filename: ";
            std::cin >> filename;

            auto formatted = this->format->format(bag);
            this->format->save(filename, formatted);
            std::cout << "Saved in the file " << filename << ".\n";

            if (this->selectedFormat == "CSV") {
                std::string command = "notepad.exe " + filename;
                system(command.c_str());
            } else {
                std::string command = "start " + filename;
                system(command.c_str());
            }
        } else {
            std::cout << "Invalid choice!\n";
        }
    }
}


void Ui::run() {
    int option1, option2, totalPrice = 0;

    std::string size;
    std::string colour;
    double price;
    unsigned int quantity;
    std::string photo;

    while (true) {
        showModeMenu();
        std::cout << "Choose an option: ";
        std::cin >> option1;
        if (option1 == 0) {
            std::cout << "Bye, bye!\n";
            return;
        }

        if (option1 == 1) {
            while (true) {
                showAdministratorMenu();

                std::cout << "Choose an option: ";
                std::cin >> option2;

                if (option2 == 0) {
                    std::cout << "Bye, bye!\n";
                    return;
                } else if (option2 == 1) {
                    TrenchCoat coat;
                    std::cin.ignore();
                    std::cout << "Enter the coat details (size, colour, price, quantity, photograph): ";
                    std::cin >> coat;
                    addCoatUi(coat.getSize(), coat.getColour(), coat.getPrice(), coat.getQuantity(),
                              coat.getPhotograph());
                } else if (option2 == 2) {
                    std::cout << "Size = ";
                    std::cin >> size;
                    std::cout << "Colour = ";
                    std::cin >> colour;
                    removeCoatUi(size, colour);
                } else if (option2 == 3) {
                    TrenchCoat newCoat;
                    std::cout << "Enter the new coat details (size, colour, price, quantity, photograph): ";
                    std::cin >> newCoat;
                    updateCoatUi(newCoat.getSize(), newCoat.getColour(), newCoat.getPrice(), newCoat.getQuantity(),
                                 newCoat.getPhotograph());
                } else if (option2 == 4) {
                    seeAllTrenchCoats();
                } else {
                    std::cout << "Invalid choice!\n";
                }
            }
        } else if (option1 == 2) {
            while (true) {
                goShopping(totalPrice);
            }
        } else {
            std::cout << "Invalid choice!\n";
        }
    }
}
