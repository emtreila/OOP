#ifndef UI_H
#define UI_H
#include "Controller.h"


class Ui {
private:
    Controller &controller;

public:
    Ui(Controller &controller) : controller(controller) {
    };

    ~Ui() = default;

    void showMenu() const;

    void run();

    bool checkAddress(Building *building);

    void addBuildingUi();

    void getAllBuildingsUi() const;

    void getAllBuildingsToBeRestoredUi() const;

    void getAllBuildingsToBeDemolishedUi() const;

    void writeToFileUi() const;
};


#endif //UI_H
