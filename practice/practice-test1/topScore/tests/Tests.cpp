#include "Tests.h"

void Tests::testAddRepo() {
    Repo repo;

    Scorer s1("Player A", "Country 1", "Team X", 10);
    Scorer s2("Player B", "Country 2", "Team Y", 15);
    Scorer s3("Player C", "Country 1", "Team X", 5);

    assert(repo.addScorer(s1) == true);

    assert(repo.addScorer(s1) == false);

    assert(repo.addScorer(s2) == true);

    assert(repo.addScorer(s3) == true);

    std::cout << "All addScorer tests passed!" << std::endl;
}

void Tests::testAddService() {
    Repo repo;
    Service service(repo);

    // Case 1: Adding a new scorer should return true
    assert(service.addScorerService("Player A", "Country 1", "Team X", 10) == true);

    // Case 2: Adding the same scorer again should return false
    assert(service.addScorerService("Player A", "Country 1", "Team X", 10) == false);

    // Case 3: Adding a different scorer should return true
    assert(service.addScorerService("Player B", "Country 2", "Team Y", 15) == true);

    // Case 4: Adding a scorer with the same nationality and team but different goals should return true
    assert(service.addScorerService("Player C", "Country 1", "Team X", 5) == true);

    std::cout << "All addScorerService tests passed!" << std::endl;
}

void Tests::testPlayersByTeamService() {
    Repo repo;
    Service service(repo);

    repo.addScorer(Scorer("Player A", "Country 1", "Team X", 10));
    repo.addScorer(Scorer("Player B", "Country 2", "Team Y", 5));
    repo.addScorer(Scorer("Player C", "Country 1", "Team X", 20));
    repo.addScorer(Scorer("Player D", "Country 1", "Team X", 15));

    DynamicVector<Scorer> result = service.getPlayersByTeamService("Team X");
    assert(result.sizeOfVector() == 3);
    assert(result.getElement(0).getGoals() == 10);
    assert(result.getElement(1).getGoals() == 15);
    assert(result.getElement(2).getGoals() == 20);

    result = service.getPlayersByTeamService("Team Z");
    assert(result.sizeOfVector() == 0);

    result = service.getPlayersByTeamService("Team Y");
    assert(result.sizeOfVector() == 1);

    std::cout << "All getPlayersByTeamService tests passed!" << std::endl;
}

void Tests::runTests() {
    testAddRepo();
    testAddService();
    testPlayersByTeamService();
}
