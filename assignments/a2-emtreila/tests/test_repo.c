#include "test_repo.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "./repository/Repo.h"
#include "./structures/DynamicArray.h"
#include "./domain/Estate.h"

void testCreateRepository() {
    EstateRepo repo = createRepository();
    assert(repo.estates.size == 0);
    destroyRepository(&repo);
}

void testAddEstateRepo() {
    EstateRepo repo = createRepository();
    Estate estate = createEstate(HOUSE, "123 Main St", 120.5, 250000);
    bool success;

    addEstateRepo(estate, &repo, &success);
    assert(success);
    assert(repo.estates.size == 1);

    destroyRepository(&repo);
}

void testDeleteEstateRepo() {
    EstateRepo repo = createRepository();
    Estate estate1 = createEstate(HOUSE, "123 Main St", 120.5, 250000);
    Estate estate2 = createEstate(APARTMENT, "456 Oak St", 100.0, 200000);
    bool success;

    addEstateRepo(estate1, &repo, &success);
    addEstateRepo(estate2, &repo, &success);
    assert(repo.estates.size == 2);


    deleteEstateRepo("123 Main St", &repo, &success);
    assert(success);
    assert(repo.estates.size == 1);

    destroyRepository(&repo);
}

void testUpdateEstateRepo() {
    EstateRepo repo = createRepository();
    Estate estate = createEstate(HOUSE, "123 Main St", 120.5, 250000);
    bool success;

    addEstateRepo(estate, &repo, &success);
    assert(success);

    Estate updatedEstate = createEstate(HOUSE, "123 Main St", 120.5, 300000);
    updateEstateRepo(updatedEstate, &repo, &success);
    assert(success);

    destroyRepository(&repo);
}

void testFindEstateRepo() {
    EstateRepo repo = createRepository();
    Estate estate1 = createEstate(HOUSE, "123 Main St", 120.5, 250000);
    Estate estate2 = createEstate(APARTMENT, "456 Oak St", 100.0, 200000);
    bool success;

    addEstateRepo(estate1, &repo, &success);
    addEstateRepo(estate2, &repo, &success);

    Estate searchEstate = createEstate(HOUSE, "123 Main St", 120.5, 250000);
    int index = findEstateRepo(searchEstate, &repo);
    assert(index != -1);


    searchEstate = createEstate(APARTMENT, "456 Oak St", 100.0, 200000);
    index = findEstateRepo(searchEstate, &repo);
    assert(index != -1);

    searchEstate = createEstate(HOUSE, "789 Pine St", 100.0, 150000);
    index = findEstateRepo(searchEstate, &repo);
    assert(index == -1);

    destroyRepository(&repo);
}


void runRepoTests() {
    testCreateRepository();
    testAddEstateRepo();
    testDeleteEstateRepo();
    testUpdateEstateRepo();
    testFindEstateRepo();

    printf("All repository tests passed!\n");
}
