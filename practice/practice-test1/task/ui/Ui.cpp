#include "Ui.h"

#include <utility>

void Ui::showMenu() {
    std::cout << "\nMENU\n";
    std::cout << "0. EXIT.\n";
    std::cout << "1. Add a new task.\n";
    std::cout << "2. Show all the tasks.\n";
    std::cout << "3. Show all tasks with a priority less than a given priority.\n";
}

void Ui::addUi(const std::string &description, unsigned int duration, unsigned int priority) {
    if (this->service.addTaskService(description, duration, priority)) {
        std::cout << "Task added successfully!\n";
    } else {
        std::cout << "Task already exists!\n";
    }
}



void Ui::run() {
    int option;
    std::string description;
    unsigned int duration;
    unsigned int priority;

    while (true) {
        showMenu();
        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 0) {
            std::cout << "Bye, bye!\n";
            return;

        } else if (option == 1) {
            std::cout << "Description: ";
            std::cin >> description;
            std::cout << "Duration: ";
            std::cin >> duration;
            std::cout << "Priority: ";
            std::cin >> priority;
            addUi(description, duration, priority);

        } else if (option == 2) {
            const DynamicVector<Task> &tasks = this->service.getAllService();
            for (int i = 0; i < tasks.sizeOfVector(); i++) {
                Task task = tasks.getElement(i);
                std::cout << "Description: " << task.getDescription() << " , Duration: " << task.getDuration() <<
                        " , Priority: " << task.
                        getPriority() << "\n";
            }

        } else if (option == 3) {
            std::cout << "Priority: ";
            std::cin >> priority;

            DynamicVector<Task> tasks = this->service.priorityTasksService(priority);
            for (int i = 0; i < tasks.sizeOfVector(); i++) {
                Task task = tasks.getElement(i);
                std::cout << "Description: " << task.getDescription() << " , Duration: " << task.getDuration() <<
                        " , Priority: " << task.
                        getPriority() << "\n";
            }
        } else {
            std::cout << "Invalid option!\n";
        }
    }
}
