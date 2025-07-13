#ifndef ACTIONUPDATE_H
#define ACTIONUPDATE_H
#include "Action.h"
#include "../repository/IRepository.h"


class ActionUpdate : public Action {
private:
    IRepository &repo;
    TrenchCoat oldCoat, newCoat;

public:
    ActionUpdate(IRepository &repo, const TrenchCoat &oldC, const TrenchCoat &newC)
        : repo(repo), oldCoat(oldC), newCoat(newC) {
    }

    void executeUndo() override;

    void executeRedo() override;
};


#endif //ACTIONUPDATE_H
