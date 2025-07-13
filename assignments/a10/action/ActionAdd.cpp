#include "ActionAdd.h"

void ActionAdd::executeRedo() {
    this->repo.addCoat(this->addedCoat);
}

void ActionAdd::executeUndo() {
    this->repo.removeCoat(this->addedCoat.getSize(), this->addedCoat.getColour());
}