#ifndef UI_H
#define UI_H
#include "Service.h"


class Ui {
private:
    Service &service;
public:
    Ui(Service &service) : service(service) {
    };
    ~Ui() = default;

    void showMenu() const;

    void run();

    void addApplianceUi();

    void getAllAppliancesUi() const;

    void getAllWithConsumedElectricityLessThanUi() const;

    void writeToFileUi() const;
};


#endif //UI_H
