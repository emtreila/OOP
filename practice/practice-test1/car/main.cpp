#include "repository/Repo.h"
#include "service/Service.h"
#include "tests/Tests.h"
#include "ui/Ui.h"

int main() {
    Repo repository;
    Service service(repository);
    Ui ui(service);

    service.addCarService("Fiat", "Bravo", 2007, "red");
    service.addCarService("Fiat", "Idea", 2003, "black" );
    service.addCarService("Audi", "A5", 2007, "blue");
    service.addCarService("BMW", "Coupe", 2013, "pink");
    service.addCarService("Ford", "Fiesta", 1976, "yellow");

    Tests::runTests();
    //ui.run();
}