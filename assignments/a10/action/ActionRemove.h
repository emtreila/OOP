#ifndef ACTIONREMOVE_H
#define ACTIONREMOVE_H
#include "Action.h"
#include "../repository/IRepository.h"
#include "../domain/TrenchCoat.h"


class ActionRemove : virtual public Action {
private:
    TrenchCoat deletedCoat;
    IRepository &repo;

public:
    ActionRemove(IRepository &repo, TrenchCoat deletedCoat) : repo(repo), deletedCoat(std::move(deletedCoat)) {
    }

    ~ActionRemove() override = default;

    void executeRedo() override;

    void executeUndo() override;
};


#endif //ACTIONREMOVE_H
