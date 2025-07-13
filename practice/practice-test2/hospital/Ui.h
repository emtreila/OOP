#ifndef UI_H
#define UI_H
#include "Controller.h"


class Ui {
private:
    Controller &controller;
public:
    explicit Ui(Controller &controller) : controller(controller) {}

    ~Ui() = default;

    void showMenu();

    void run();

    void addDepartmentUi();

    void showAllDepartmentsUi();

    void showEfficientDepartmentsUi();

    void writeToFileUi();
};


#endif //UI_H
