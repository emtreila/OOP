#include "Service.h"

bool Service::addScorerService(const std::string &name, const std::string &nationality, const std::string &team,
                               int goals) {
    /**
     * Adds a scorer
     * @param name: the name of the player
     * @param nationality: the nationality of the player
     * @param team: the team of the player
     * @param goals: the number of goals scored by the player
     * return: true if the player was added, false otherwise
     */
    Scorer scorer = Scorer(name, nationality, team, goals);
    return this->repo.addScorer(scorer);
}

const DynamicVector<Scorer> &Service::getAllService() {
    return this->repo.getAll();
}

int Service::getNumberOfPlayersService() {
    return this->repo.getNumberOfPlayers();
}

Scorer Service::getPlayerService(int index) {
    return this->repo.getPlayer(index);
}

DynamicVector<Scorer> Service::getPlayersByTeamService(const std::string &team) {
    /**
     * Get all players from a given team
     * @param team: the team
     * return: a dynamic vector of players
     */
    DynamicVector<Scorer> filtered;

    int numPlayers = this->repo.getNumberOfPlayers();

    for (int i = 0; i < numPlayers; i++) {
        if (this->repo.getPlayer(i).getTeam().compare(team) == 0) {
            filtered.add(this->repo.getPlayer(i));
        }
    }
    // Sort the players in ascending order of goals
    for (int i = 0; i < filtered.sizeOfVector(); i++) {
        for (int j = i + 1; j < filtered.sizeOfVector(); j++) {
            if (filtered.getElement(i).getGoals() > filtered.getElement(j).getGoals()) {
                Scorer aux = filtered.getElement(i);
                filtered.setElement(i, filtered.getElement(j));
                filtered.setElement(j, aux);
            }
        }
    }
    return filtered;
}
