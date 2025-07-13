#ifndef SERVICE_H
#define SERVICE_H

#include "../repository/Repo.h"
#include "../undo_redo/UndoRedoCommand.h"
#include <string.h>

//structure to hold the service
typedef struct {
    EstateRepo repo;
    UndoRedoCommand urc;
} EstateService;


void destroyService(EstateService *service); //frees the memory allocated for service

EstateService createService(EstateRepo estate_repo); //function to create a new service

bool addEstateService(EstateService *service, EstateType type, char address[ADDRESS_LENGTH], double surface,
                      double price); //function to add a new estate to the service

//function to delete an estate from the service
bool deleteEstateService(EstateService *service, char toDelete[ADDRESS_LENGTH]);

bool updateEstateService(EstateService *service, EstateType newType, char address[ADDRESS_LENGTH], double newSurface,
                         double newPrice); //function to update an estate from the service

//function to get all estates that have a certain substring in their address
DynamicArray estatesWithStringInAddress(EstateService *service, char *substring);

//function to get all estates of a certain type and with a surface greater than a given value
DynamicArray estatesWithTypeAndSurface(EstateService *service, EstateType type, double surface);

//function to undo the last operation
bool undoService(EstateService *service);

// function to redo the last undo-ed operation
bool redoService(EstateService *service);

#endif //SERVICE_H
