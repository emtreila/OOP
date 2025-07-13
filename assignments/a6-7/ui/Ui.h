#ifndef UI_H
#define UI_H

#include  "../service/Service.h"
#include <string>
#include <iostream>

#include "../formatter/Formatter.h"

class Ui {
private:
    Service &service;
    Formatter *format=nullptr;
    std::string selectedFormat;

public:
    Ui(Service &service): service{service} {
    }

    ~Ui();

    void run();

    void showModeMenu();

    void showAdministratorMenu();

    void showUserMenu();

    void addCoatUi(const std::string &size,
                   const std::string &colour,
                   double price,
                   unsigned int quantity,
                   const std::string &photo);

    void removeCoatUi(const std::string &size, const std::string &colour);

    void updateCoatUi(const std::string &size,
                      const std::string &colour,
                      double price,
                      unsigned int quantity,
                      const std::string &photo);

    void seeAllTrenchCoats();

    void goShopping(int &totalPrice);

    void showShoppingMenu();
};

#endif //UI_H