#ifndef UI_H
#define UI_H
#include "../service/Service.h"

class Ui {
private:
    Service &service;

public:
    explicit Ui(Service &service): service(service) {
    }

    ~Ui() = default;

    void showMenu();

    void run();

    void addCarUi(const std::string &name, const std::string &model, int year, const std::string &color);

    void removeCarUi(const std::string &model, int year);
};


#endif //UI_H
