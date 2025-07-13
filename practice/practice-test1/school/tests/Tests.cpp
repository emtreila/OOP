#include "Tests.h"

void Tests::testRemoveRepo() {
    Repo repo;

    repo.addSchool(School("Greenwood High", 40.7128, -74.0060, 12, 5, 2001, true));
    repo.addSchool(School("Sunnyvale Elementary", 37.3688, -122.0363, 8, 3, 1998, false));
    repo.addSchool(School("Riverside Academy", 34.0522, -118.2437, 20, 11, 2010, true));

    assert(repo.removeSchool("Sunnyvale Elementary", 37.3688, -122.0363) == true);

    assert(repo.removeSchool("Sunnyvale Elementary", 37.3688, -122.0363) == false);

    assert(repo.removeSchool("Greenwood High", 40.7128, -74.0060) == true);

    assert(repo.removeSchool("NonExistent School", 45.0000, -90.0000) == false);

    const auto &schools = repo.getAll();
    assert(schools.sizeOfVector() == 1);
    assert(schools.getElement(0).getName() == "Riverside Academy");

    std::cout << "All removeSchool tests passed!" << std::endl;
}

void Tests::testGetVisitSchools() {
    Repo repo;
    Service service(repo);

    repo.addSchool(School("Old School", 40.7128, -74.0060, 10, 6, 1995, false));
    repo.addSchool(School("Recent School", 37.3688, -122.0363, 5, 8, 2020, false));
    repo.addSchool(School("Exact Date School", 34.0522, -118.2437, 15, 3, 2023, false));
    repo.addSchool(School("Future School", 35.6895, 139.6917, 12, 7, 2030, false));

    DynamicVector<School> visitSchools = service.getVisitSchools(12, 3, 2023);

    assert(repo.getSchool(0).getVisited() == true);

    assert(repo.getSchool(1).getVisited() == true);

    assert(repo.getSchool(2).getVisited() == false);

    assert(repo.getSchool(3).getVisited() == false);

    assert(visitSchools.sizeOfVector() == 2);
    assert(visitSchools.getElement(0).getName() == "Exact Date School");
    assert(visitSchools.getElement(1).getName() == "Future School");

    std::cout << "All getVisitSchools tests passed!" << std::endl;
}

void Tests::testRemoveService() {
    Repo repo;
    Service service(repo);

    repo.addSchool(School("Greenwood High", 40.7128, -74.0060, 12, 5, 2001, true));
    repo.addSchool(School("Sunnyvale Elementary", 37.3688, -122.0363, 8, 3, 1998, false));
    repo.addSchool(School("Riverside Academy", 34.0522, -118.2437, 20, 11, 2010, true));

    assert(service.removeSchoolService("Sunnyvale Elementary", 37.3688, -122.0363) == true);

    assert(service.removeSchoolService("Sunnyvale Elementary", 37.3688, -122.0363) == false);

    assert(service.removeSchoolService("Greenwood High", 40.7128, -74.0060) == true);

    assert(service.removeSchoolService("NonExistent School", 45.0000, -90.0000) == false);

    const auto &schools = repo.getAll();
    assert(schools.sizeOfVector() == 1);
    assert(schools.getElement(0).getName() == "Riverside Academy");

    std::cout << "All removeSchoolService tests passed!" << std::endl;
}


void Tests::runTests() {
    testRemoveRepo();
    testRemoveService();
    testGetVisitSchools();
}

