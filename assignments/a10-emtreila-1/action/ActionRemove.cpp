#include "ActionRemove.h"

void ActionRemove::executeRedo() {
    this->repo.removeCoat(this->deletedCoat.getSize(), this->deletedCoat.getColour());
}

void ActionRemove::executeUndo() {
    this->repo.addCoat(this->deletedCoat);
}