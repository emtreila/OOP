#ifndef SERVICE_H
#define SERVICE_H
#include "../repository/Repo.h"

class Service {
private:
    Repo &repo;

public:
    explicit Service(Repo &repo): repo{repo} {
    }

    ~Service() = default;

    bool addScorerService(const std::string &name, const std::string &nationality, const std::string &team, int goals); // add a new player

    const DynamicVector<Scorer> &getAllService();

    int getNumberOfPlayersService();

    Scorer getPlayerService(int index);

    DynamicVector<Scorer> getPlayersByTeamService(const std::string &team); // get all the players from a given team
};


#endif //SERVICE_H
