#include <iostream>

#include "Controller.h"
#include "Tests.h"
#include "Ui.h"

int main() {
    Controller controller;
    Ui ui(controller);
    //Tests tests;
    ui.run();
    //tests.runTests();

}
