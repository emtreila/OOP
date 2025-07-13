#ifndef UI_H
#define UI_H
#include "../service/Service.h"
#include <iostream>

class Ui {
private:
    Service &service;

public:
    explicit Ui(Service &service): service{service} {
    }
    ~Ui() = default;

    void showMenu();

    void removeSchoolUi(const std::string &name, float address_long, float address_lat);

    void run();
};


#endif //UI_H
