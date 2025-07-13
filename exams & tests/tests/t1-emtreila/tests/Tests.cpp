#include "Tests.h"

#include <cassert>
#include <iostream>
#include "../repository/Repo.h"
#include "../service/Service.h"


void Tests::testAddSchoolRepo() {
    Repo repo;
    School s1("name1", 1, 1, 1, 1, 1);
    School s2("name2", 2, 2, 2, 2, 2);

    assert(repo.addSchool(s1) == true);

    assert(repo.addSchool(s1) == false);

    assert(repo.addSchool(s2) == true);

    std::cout << "All addSchool tests passed!" << std::endl;
}

void Tests::testAddSchoolService() {
    Repo repo;
    Service service(repo);

    assert(service.addSchoolService("name1", 1, 1,1,1,1) == true);

    assert(service.addSchoolService("name1", 1, 1,1,1,1) == false);

    assert(service.addSchoolService("name2", 2, 2,2,2,2) == true);

    std::cout << "All addSchoolService tests passed!" << std::endl;
}

void Tests::runTests() {
    testAddSchoolRepo();
    testAddSchoolService();
}
