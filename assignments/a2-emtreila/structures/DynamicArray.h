#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "../domain/Estate.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10
#define CAPACITY_MULTIPLIER 2


typedef struct {
    Estate *data;
    int capacity;
    int size;
} DynamicArray;

// function to create a new dynamic array
DynamicArray createDynamicArray();

// function to destroy a dynamic array
void destroyDynamicArray(DynamicArray *da);

// function to find an estate in a dynamic array
int findDynamicArray(DynamicArray *da, Estate estate);

// function to add an estate to a dynamic array
bool addDynamicArray(DynamicArray *da, Estate estate);

// function to remove an estate from a dynamic array
bool removeDynamicArray(DynamicArray *da, int index);

// function to update an estate in a dynamic array
bool updateDynamicArray(DynamicArray *da, int index, Estate updatedEstate);

#endif //DYNAMICARRAY_H
