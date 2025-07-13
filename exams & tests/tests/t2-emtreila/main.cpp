
#include <iostream>

#include "Service.h"
#include "Ui.h"

int main() {
    Service service;
    Ui ui(service);
    ui.run();
}
