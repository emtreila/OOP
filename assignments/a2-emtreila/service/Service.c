#include "Service.h"

#include <ctype.h>

//function to create a new service
EstateService createService(EstateRepo estate_repo) {
    EstateService service = {
        .repo = estate_repo,
        .urc = createUndoRedoCommand()
    };
    return service;
}

//function to free the memory allocated for the service
void destroyService(EstateService *service) {
    destroyRepository(&service->repo); //free dynamically allocated memory in the repository
    destroyUndoRedoCommand(&service->urc);
}

//function to add a new estate to the service
bool addEstateService(EstateService *service, EstateType type, char address[ADDRESS_LENGTH], double surface,
                      double price) {
    //create a new estate
    Estate newEstate = createEstate(type, address, surface, price);

    //check if an estate with that address already exists
    int foundIndex = findEstateRepo(newEstate, &service->repo);
    if (foundIndex != -1) {
        return false;
    }

    //add the new estate to the repository
    bool wasAdded = false;
    addEstateRepo(newEstate, &service->repo, &wasAdded);

    if (wasAdded) {
        UndoCommand uc = {
            .undoType = UNDO_ADD,
            .estate = newEstate
        };
        pushUndoCommand(&service->urc, uc);
    }

    return wasAdded;
}

//function to delete an estate from the service
bool deleteEstateService(EstateService *service, char toDelete[ADDRESS_LENGTH]) {
    Estate mock = {0};
    strcpy(mock.address, toDelete);

    // search the estate to be removed
    // if it exists, save it for adding it to undo
    int foundIndex = findEstateRepo(mock, &service->repo);
    if (foundIndex == -1) {
        return false;
    }

    Estate deleted = service->repo.estates.data[foundIndex];

    //delete the estate with the given address from the repository
    bool wasDeleted = false;
    deleteEstateRepo(toDelete, &service->repo, &wasDeleted);
    if (wasDeleted) {
        UndoCommand uc = {
            .undoType = UNDO_REMOVE,
            .estate = deleted
        };
        pushUndoCommand(&service->urc, uc);
    }

    return wasDeleted;
}

//function to update an estate from the service
bool updateEstateService(EstateService *service, EstateType newType, char address[ADDRESS_LENGTH], double newSurface,
                         double newPrice) {
    Estate newEstate = createEstate(newType, address, newSurface, newPrice);

    // search for the old estate
    // to save it in the undo
    int foundIndex = findEstateRepo(newEstate, &service->repo);
    if (foundIndex == -1) {
        return false;
    }

    Estate old = service->repo.estates.data[foundIndex];

    //update the estate with the given address in the repository
    bool wasUpdated = false;
    updateEstateRepo(newEstate, &service->repo, &wasUpdated);

    if (wasUpdated) {
        UndoCommand uc = {
            .undoType = UNDO_UPDATE,
            .estate = old
        };
        pushUndoCommand(&service->urc, uc);
    }

    return wasUpdated;
}

//function to get all estates that have a certain substring in their address
DynamicArray estatesWithStringInAddress(EstateService *service, char *substring) {
    //create a new dynamic vector of estates
    DynamicArray filteredEstates = createDynamicArray();

    DynamicArray estates = getEstatesRepo(&service->repo);

    for (int i = 0; i < estates.size; i++) {
        //check if the substring is empty or if the address contains the substring
        if (strlen(substring) == 0 || strstr(estates.data[i].address, substring) != NULL) {
            //add the estate to the dynamic vector
            addDynamicArray(&filteredEstates, estates.data[i]);
        }
    }

    //sort the filtered estates by price in ascending order
    for (int i = 0; i < filteredEstates.size; i++) {
        for (int j = i + 1; j < filteredEstates.size; j++) {
            if (filteredEstates.data[i].price > filteredEstates.data[j].price) {
                Estate temp = filteredEstates.data[i];
                filteredEstates.data[i] = filteredEstates.data[j];
                filteredEstates.data[j] = temp;
            }
        }
    }

    return filteredEstates;
}


//function to get all estates of a certain type and with a surface greater than a given value
DynamicArray estatesWithTypeAndSurface(EstateService *service, EstateType type, double surface) {
    //create a new dynamic vector of estates
    DynamicArray filteredEstates = createDynamicArray();

    DynamicArray estates = getEstatesRepo(&service->repo);

    for (int i = 0; i < estates.size; i++) {
        //check if the estate has the given type and surface greater than the given value
        if (estates.data[i].type == type && estates.data[i].surface > surface) {
            //add the estate to the dynamic vector
            addDynamicArray(&filteredEstates, estates.data[i]);
        }
    }

    //sort the filtered estates by price in ascending order
    for (int i = 0; i < filteredEstates.size; i++) {
        for (int j = i + 1; j < filteredEstates.size; j++) {
            if (filteredEstates.data[i].price > filteredEstates.data[j].price) {
                double temp = filteredEstates.data[i].price;
                filteredEstates.data[i].price = filteredEstates.data[j].price;
                filteredEstates.data[j].price = temp;
            }
        }
    }

    return filteredEstates;
}

//function to undo the last operation
bool undoService(EstateService *service) {
    UndoCommand popped = popUndoCommand(&service->urc);

    if (popped.undoType == UNDO_ERROR) {
        return false;
    }

    bool success = false;
    switch (popped.undoType) {
        case UNDO_ADD: {
            deleteEstateRepo(popped.estate.address, &service->repo, &success);
            if (success) {
                // push redo add for readding the estate
                RedoCommand rc = {
                    .redoType = REDO_ADD,
                    .estate = popped.estate
                };
                pushRedoCommand(&service->urc, rc);
            }
            break;
        }
        case UNDO_REMOVE: {
            addEstateRepo(popped.estate, &service->repo, &success);
            if (success) {
                // push redo remove for re-removing the estate
                RedoCommand rc = {
                    .redoType = REDO_REMOVE,
                    .estate = popped.estate
                };
                pushRedoCommand(&service->urc, rc);
            }
            break;
        }
        case UNDO_UPDATE: {
            int foundIndex = findEstateRepo(popped.estate, &service->repo);
            if (foundIndex == -1) {
                return false;
            }

            Estate old = service->repo.estates.data[foundIndex];

            updateEstateRepo(popped.estate, &service->repo, &success);
            if (success) {
                // push redo update for re-updating the estate with the old value
                RedoCommand rc = {
                    .redoType = REDO_UPDATE,
                    .estate = old
                };
                pushRedoCommand(&service->urc, rc);
            }
            break;
        }
        default: break;
    }

    return success;
}

// function to redo the last undo-ed operation
bool redoService(EstateService *service) {
    RedoCommand popped = popRedoCommand(&service->urc);

    if (popped.redoType == REDO_ERROR) {
        return false;
    }

    bool success = false;
    switch (popped.redoType) {
        case REDO_ADD: {
            addEstateRepo(popped.estate, &service->repo, &success);
            break;
        }
        case REDO_REMOVE: {
            deleteEstateRepo(popped.estate.address, &service->repo, &success);
            break;
        }
        case REDO_UPDATE: {
            updateEstateRepo(popped.estate, &service->repo, &success);
            break;
        }
        default: break;
    }

    return success;
}
