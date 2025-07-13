#include "Tests.h"
#include "../domain/Task.h"
#include "../repository/Repo.h"
#include "../service/Service.h"

#include <cassert>
#include <iostream>


void Tests::testPriorityTasksService() {
    Repo repo;
    Service service(repo);


    repo.addTask(Task("A", 30, 2));
    repo.addTask(Task("B", 20, 5));
    repo.addTask(Task("C", 50, 3));
    repo.addTask(Task("D", 10, 1));


    auto result = service.priorityTasksService(4);
    assert(result.sizeOfVector() == 3);
    assert(result.getElement(0).getDuration() == 50);
    assert(result.getElement(1).getDuration() == 30);
    assert(result.getElement(2).getDuration() == 10);

    assert(service.priorityTasksService(1).sizeOfVector() == 0);

    assert(service.priorityTasksService(10).sizeOfVector() == 4);

    assert(service.priorityTasksService(2).sizeOfVector() == 1);

    std::cout << "All PriorityTasksService tests passed!" << std::endl;
}

void Tests::testAddTaskRepo() {
    Repo repo;
    Task t1("Task 1", 30, 2);
    Task t2("Task 2", 40, 3);

    assert(repo.addTask(t1) == true);

    assert(repo.addTask(t1) == false);

    assert(repo.addTask(t2) == true);

    std::cout << "All addTask tests passed!" << std::endl;
}

void Tests::testAddTaskService() {
    Repo repo;
    Service service(repo);

    assert(service.addTaskService("Task 1", 2, 30) == true);

    assert(service.addTaskService("Task 1", 2, 30) == false);

    assert(service.addTaskService("Task 2", 3, 40) == true);

    std::cout << "All addTaskService tests passed!" << std::endl;
}

void Tests::runTests() {
    testPriorityTasksService();
    testAddTaskRepo();
    testAddTaskService();
}