#include "Repo.h"


//function to create a new repository
EstateRepo createRepository() {
    EstateRepo repoEstates;
    repoEstates.estates = createDynamicArray();
    return repoEstates;
}

//function to destroy the repo and free the allocated memory
void destroyRepository(EstateRepo *repo) {
    destroyDynamicArray(&repo->estates);
}

//function to add a new estate to the repository
void addEstateRepo(Estate newEstate, EstateRepo *repo, bool *success) {
    *success = addDynamicArray(&repo->estates, newEstate);
}

//function to delete an estate from the repository
void deleteEstateRepo(char *address, EstateRepo *repo, bool *success) {
    Estate mock = {0};
    strcpy(mock.address, address);
    int foundIndex = findDynamicArray(&repo->estates, mock);
    *success = removeDynamicArray(&repo->estates, foundIndex);
}

//function to update an estate from the repository
void updateEstateRepo(Estate updatedEstate, EstateRepo *repo, bool *success) {
    int foundIndex = findDynamicArray(&repo->estates, updatedEstate);
    *success = updateDynamicArray(&repo->estates, foundIndex, updatedEstate);
}

//function to find an estate in the repository
int findEstateRepo( Estate estate, EstateRepo *repo) {
    return findDynamicArray(&repo->estates, estate);
}

//function to get the estates from the repository
DynamicArray getEstatesRepo(EstateRepo *repo) {
    return repo->estates;
}