#ifndef UI_H
#define UI_H
#include "Service.h"


class Ui {
private:
    Service &service;
public:
    Ui(Service &service) : service(service) {
    }

    ~Ui() = default;

    void showMenu();

    void run();

    void addCarUi();

    void getCars();

    void writeToFileUi();
};


#endif //UI_H
