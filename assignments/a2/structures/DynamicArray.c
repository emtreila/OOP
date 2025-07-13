#include "DynamicArray.h"

// function to create a new dynamic array
DynamicArray createDynamicArray() {
    DynamicArray da;
    da.size = 0;
    da.capacity = INITIAL_CAPACITY;
    da.data = (Estate *) malloc(INITIAL_CAPACITY * sizeof(Estate)); // allocate memory for the dynamic array
    // check if the memory was allocated
    if (da.data == NULL) {
        perror("Could not allocate dynamic array!");
    }
    return da;
}

// function to destroy a dynamic array
void destroyDynamicArray(DynamicArray *da) {
    // free the memory allocated for the dynamic array
    da->capacity = 0;
    da->size = 0;
    free(da->data);
    da->data = NULL;
}

bool addDynamicArray(DynamicArray *da, Estate estate) {
    if (da->data == NULL) { // if the dynamic array is not initialized
        return false;
    }

    if (da->size >= da->capacity) { // if the dynamic array is full
        int newCapacity = da->capacity * CAPACITY_MULTIPLIER; // double the capacity
        Estate *newData = (Estate *) realloc(da->data, newCapacity * sizeof(Estate));

        if (newData == NULL) { // if the memory was not allocated
            return false;
        }
        da->data = newData;
        da->capacity = newCapacity;
    }
    // add the estate to the dynamic array
    da->data[da->size++] = estate;
    return true;
}

// function to find an estate in a dynamic array
int findDynamicArray(DynamicArray *da, Estate estate) {
    if (da->data == NULL) { // if the dynamic array is not initialized
        return -1;
    }

    for (int i = 0; i < da->size; i++) { // iterate through the dynamic array
        if (strcmp(da->data[i].address, estate.address) == 0) { // if the estate was found return the index
            return i;
        }
    }

    return -1;
}

// function to remove an estate from a dynamic array
bool removeDynamicArray(DynamicArray *da, int index) {
    if (da->data == NULL) { // if the dynamic array is not initialized
        return false;
    }

    if (index < 0 || index >= da->size) { // if the index is invalid
        return false;
    }

    // remove the estate from the dynamic array
    Estate* removed = &da->data[--da->size];
    da->data[index] = *removed;
    return true;
}

// function to update an estate in a dynamic array
bool updateDynamicArray(DynamicArray *da, int index, Estate updatedEstate) {
    if (da->data == NULL) { // if the dynamic array is not initialized
        return false;
    }

    if (index < 0 || index >= da->size) { // if the index is invalid
        return false;
    }

    da->data[index] = updatedEstate; // update the estate in the dynamic array

    return true;
}
