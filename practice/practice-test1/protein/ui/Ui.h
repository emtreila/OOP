#ifndef UI_H
#define UI_H
#include "../service/Service.h"

class Ui {
private:
    Service &service;
public:
    explicit Ui(Service &service): service{service} {}

    ~Ui() = default;

    static void showMenu();

    void addProteinUi(const std::string &organism,
            const std::string &name,
            const std::string &sequence);

    void run();
};


#endif //UI_H
