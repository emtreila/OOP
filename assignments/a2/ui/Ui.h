#ifndef UI_H
#define UI_H

#include "../service/Service.h"

#include<stdio.h>
#include <string.h>

#define MAX_TYPE_LENGTH 101
#define MAX_DIGITS_LENGTH 15

//structure to hold the UI
typedef struct {
    EstateService service;
} EstateUi;

EstateUi createUi(EstateService estate_service); //function to create a new UI

void run(); //function to run the UI

void show_menu(); //function to display the menu

//function to add a new estate
void addEstateUi(EstateUi *ui, char type[MAX_TYPE_LENGTH], char address[ADDRESS_LENGTH], double surface, double price);

//function to delete an estate
void deleteEstateUi(EstateUi *ui, char toDelete[ADDRESS_LENGTH]);

//function to update an estate
void updateEstateUi(EstateUi *ui, char newtype[MAX_TYPE_LENGTH], char address[ADDRESS_LENGTH], double newSurface,
                    double newPrice);

//function for req 4
void estatesWithStringInAddressUi(EstateUi *ui, char *substring);

//function for req 5
void estatesWithTypeAndSurfaceUi(EstateUi *ui, char *type, double surface);

void undoUi(EstateUi *ui);

void redoUi(EstateUi *ui);

double read_surface();

double read_price();

#endif //UI_H
