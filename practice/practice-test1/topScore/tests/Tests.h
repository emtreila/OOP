#ifndef TESTS_H
#define TESTS_H
#include "../service/Service.h"
#include "../repository/Repo.h"
#include "../service/Service.h"
#include <cassert>
#include <iostream>

class Tests {
public:
    static void testPlayersByTeamService();

    static void testAddRepo();

    static void testAddService();

    static void runTests();
};


#endif //TESTS_H
