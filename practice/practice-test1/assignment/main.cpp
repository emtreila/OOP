#include <iostream>
#include "ui/Ui.h"
#include "service/Service.h"
#include "repository/Repo.h"

int main() {
    Repo repo;
    try {
        repo.readFromFile();  // Read from file
        std::cout << "Assignments loaded successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    Service service(repo);
    Ui ui(service);
    ui.run();
}