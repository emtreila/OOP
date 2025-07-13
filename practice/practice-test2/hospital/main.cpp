#include <iostream>

#include "Controller.h"
#include "Ui.h"

int main() {
    Controller controller;
    Ui ui(controller);

    ui.run();
}
