#ifndef TESTS_H
#define TESTS_H
#include "../service/Service.h"
#include <cassert>

class Tests {
public:
    static void testAddProtein();
    static void testAddProteinService();
    static void testGetProteinsName();
    static void runTests();
};


#endif //TESTS_H
