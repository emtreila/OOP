#ifndef ACTIONADD_H
#define ACTIONADD_H
#include <utility>

#include "Action.h"
#include "../repository/IRepository.h"
#include "../domain/TrenchCoat.h"


class ActionAdd : virtual public Action{
private:
    TrenchCoat addedCoat;
    IRepository &repo;

public:
    ActionAdd(IRepository &repo, const TrenchCoat& addedCoat) : repo(repo), addedCoat(std::move(addedCoat)) {}
    ~ActionAdd() override = default;
    void executeRedo() override;
    void executeUndo() override;

};


#endif //ACTIONADD_H
