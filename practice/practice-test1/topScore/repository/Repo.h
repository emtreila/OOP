#ifndef REPO_H
#define REPO_H
#include "../domain/Scorer.h"
#include "../DynamicVector.h"


class Repo {
private:
    DynamicVector<Scorer> scorers;

public:
    Repo();
    ~Repo();

    bool addScorer(const Scorer &scorer); // adds a new player to the repository

    const DynamicVector<Scorer>& getAll();

    int getNumberOfPlayers();

    Scorer getPlayer(int index);

};


#endif //REPO_H
