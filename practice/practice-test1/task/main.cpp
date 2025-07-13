#include "repository/Repo.h"
#include "service/Service.h"
#include "tests/Tests.h"
#include "ui/Ui.h"

int main() {

    Repo repository;
    Service service(repository);
    Ui ui(service);

    service.addTaskService("Solve_OOP_assignment",120,1);
    service.addTaskService("Respond_to_emails",45,2);
    service.addTaskService("Eat_sushi",30,3);
    service.addTaskService("Visit_parent",240,1);
    service.addTaskService("Buy_a_jacket",120,2);

    //ui.run();
    Tests::runTests();

}