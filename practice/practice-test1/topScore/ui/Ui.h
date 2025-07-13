#ifndef UI_H
#define UI_H
#include "../service/Service.h"
#include <iostream>

class Ui {
private:
    Service &service;

public:
    Ui(Service &service): service{service} {
    }

    ~Ui() = default;

    void showMenu();

    void run();

    void addScorerUi(const std::string &name, const std::string &nationality, const std::string &team, int goals);
};


#endif //UI_H
