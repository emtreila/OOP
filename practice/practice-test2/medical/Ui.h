

#ifndef UI_H
#define UI_H
#include "Service.h"
#include <iostream>
#include "BMI.h"
#include "BP.h"

class Ui {
private:
    Service &service;

public:
    explicit Ui(Service &service) : service(service) {};

    ~Ui() = default;

    void showMenu();

    void run();

    void addAnalysisUi();

    void showAllAnalysesUi();

    void isIllUi();

    void writeToFileUi();
};



#endif //UI_H
