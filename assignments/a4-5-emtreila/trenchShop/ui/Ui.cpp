#include "Ui.h"
#include <limits> // for std::numeric_limits
#include <cstring>

Ui::~Ui() = default;

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
    if (size.empty()) {
        std::cout << "Invalid size!\n";
        return;
    }

    if (colour.empty()) {
        std::cout << "Invalid colour!\n";
        return;
    }

    if (price < 0) {
        std::cout << "Invalid price!\n";
        return;
    }

    if (quantity < 0) {
        std::cout << "Invalid quantity!\n";
        return;
    }

    if (photo.empty()) {
        std::cout << "Invalid link!\n";
        return;
    }


    if (this->service.addCoatService(size, colour, price, quantity, photo)) {
        std::cout << "Trench coat added successfully!\n";
    } else {
        std::cout << "Trench coat already exists!\n";
    }
}

void Ui::removeCoatUi(const std::string &size, const std::string &colour) {
    if (size.empty()) {
        std::cout << "Invalid size!\n";
        return;
    }

    if (colour.empty()) {
        std::cout << "Invalid colour!\n";
        return;
    }

    if (this->service.removeCoatService(size, colour)) {
        std::cout << "Trench coat removed successfully!\n";
    } else {
        std::cout << "Trench coat does not exist!\n";
    }
}

void Ui::updateCoatUi(const std::string &size, const std::string &colour, double price, unsigned int quantity,
                      const std::string &photo) {
    if (size.empty()) {
        std::cout << "Invalid size!\n";
        return;
    }

    if (colour.empty()) {
        std::cout << "Invalid colour!\n";
        return;
    }

    if (price < 0) {
        std::cout << "Invalid price!\n";
        return;
    }

    if (quantity < 0) {
        std::cout << "Invalid quantity!\n";
        return;
    }

    if (photo.empty()) {
        std::cout << "Invalid link!\n";
        return;
    }

    if (this->service.updateCoatService(TrenchCoat(size, colour, price, quantity, photo))) {
        std::cout << "Trench coat updated successfully!\n";
    } else {
        std::cout << "Trench coat does not exist!\n";
    }
}

void Ui::seeAllTrenchCoats() {
    const DynamicVector<TrenchCoat> &coats = this->service.getAllService();
    if (coats.sizeOfVector() == 0) {
        std::cout << "No trench coats in the store!\n";
        return;
    }

    for (int i = 0; i < coats.sizeOfVector(); i++) {
        TrenchCoat coat = coats.getElement(i);
        std::cout << i << ". " << "Size: " << coat.getSize() << " Colour: " << coat.getColour() << " Price: " << coat.
                getPrice() <<
                " Quantity: " << coat.getQuantity() << " Photograph: " << coat.getPhotograph() << "\n";
    }
}


void Ui::goShopping(int &totalPrice) {
    int option;
    std::string givenSize;
    int index = 0;

    const DynamicVector<TrenchCoat> &coats = this->service.getAllService();
    DynamicVector<TrenchCoat> bag;

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
                if (coats.sizeOfVector() == 0) {
                    std::cout << "No trench coats available!\n";
                    break;
                }

                if (index >= coats.sizeOfVector()) {
                    index = 0;
                }

                TrenchCoat coat = coats.getElement(index);

                if (givenSize.empty() || coat.getSize() == givenSize) {
                    std::cout << index << ". Size: " << coat.getSize()
                            << " , Colour: " << coat.getColour()
                            << " , Price: " << coat.getPrice()
                            << " , Quantity: " << coat.getQuantity() << "\n";

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
                        bag.add(coat);
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
            std::cout << "\nSHOPPING BASKET:\n";
            for (int i = 0; i < bag.sizeOfVector(); i++) {
                TrenchCoat coat = bag.getElement(i);
                std::cout << i << ". Size: " << coat.getSize()
                        << " , Colour: " << coat.getColour()
                        << " , Price: " << coat.getPrice()
                        << " , Quantity: " << coat.getQuantity() << "\n";
            }
            std::cout << "\nTOTAL PRICE: " << totalPrice << "\n";
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
                    std::cout << "Size = ";
                    std::cin >> size;
                    std::cout << "Colour = ";
                    std::cin >> colour;
                    std::cout << "Price = ";
                    std::cin >> price;
                    std::cout << "Quantity = ";
                    std::cin >> quantity;
                    std::cout << "Photo link = ";
                    std::cin >> photo;
                    addCoatUi(size, colour, price, quantity, photo);
                } else if (option2 == 2) {
                    std::cout << "Size = ";
                    std::cin >> size;
                    std::cout << "Colour = ";
                    std::cin >> colour;
                    removeCoatUi(size, colour);
                } else if (option2 == 3) {
                    std::cout << "Size = ";
                    std::cin >> size;
                    std::cout << "Colour = ";
                    std::cin >> colour;
                    std::cout << "Price = ";
                    std::cin >> price;
                    std::cout << "Quantity = ";
                    std::cin >> quantity;
                    std::cout << "Photo link = ";
                    std::cin >> photo;
                    updateCoatUi(size, colour, price, quantity, photo);
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
