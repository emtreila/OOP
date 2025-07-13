#ifndef TESTS_H
#define TESTS_H
#include "../domain/Car.h"
#include "../repository/Repo.h"
#include "../service/Service.h"
#include <iostream>
#include <cassert>

class Tests {
public:
    static void testAddRepo();

    static void testAddService();

    static void testVintageCars();

    static void runTests();
};


#endif //TESTS_H
