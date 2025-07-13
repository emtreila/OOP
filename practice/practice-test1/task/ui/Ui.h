#ifndef UI_H
#define UI_H
#include "../service/Service.h"
#include<iostream>

class Ui {
private:
    Service &service;

public:
    explicit Ui(Service &service): service(service) {
    }

    ~Ui() = default;

    void run();

    static void showMenu();

    void addUi(const std::string &description, unsigned int duration, unsigned int priority);

};


#endif //UI_H
