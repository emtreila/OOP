#ifndef TESTS_H
#define TESTS_H
#include "../repository/Repo.h"
#include "../service/Service.h"
#include <cassert>

class Tests {
public:
    static void testRemoveRepo();
    static void testRemoveService();
    static void runTests();
    static void testGetVisitSchools();
};


#endif //TESTS_H
