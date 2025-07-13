#include "ActionUpdate.h"

void ActionUpdate::executeUndo() {
    repo.updateCoat(oldCoat);
}

void ActionUpdate::executeRedo() {
    repo.updateCoat(newCoat);
}
