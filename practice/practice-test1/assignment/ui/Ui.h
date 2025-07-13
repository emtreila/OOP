#ifndef UI_H
#define UI_H
#include "../service/Service.h"
#include <iostream>

class Ui {
private:
    Service &service;

public:
    explicit Ui(Service &service): service(service) {
    }

    ~Ui() = default;

    void showMenu();

    void addAssignmentUi(int id, std::string name, std::string solution);

    void run();
};


#endif //UI_H
