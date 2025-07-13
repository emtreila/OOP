#ifndef REPO_H
#define REPO_H

#include "../domain/Estate.h"
#include "../structures/DynamicArray.h"
#include <stdbool.h>
#include <string.h>


//structure to hold the repository
typedef struct {
    DynamicArray estates;
} EstateRepo;

void destroyRepository(EstateRepo *repo); //frees the memory allocated for the repository

EstateRepo createRepository(); //creates a new repository

void addEstateRepo(Estate newEstate, EstateRepo *repo, bool *success); //adds a new estate to the repository

void deleteEstateRepo(char *address, EstateRepo *repo, bool *success); //deletes an estate from the repository

void updateEstateRepo(Estate updatedEstate, EstateRepo *repo, bool *success); //updates an estate from the repository

int findEstateRepo(Estate estate, EstateRepo *repo); //finds an estate in the repository

DynamicArray getEstatesRepo(EstateRepo *repo); //gets the estates from the repository
#endif //REPO_H
