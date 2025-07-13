#include "UndoRedoCommand.h"

// function to create undo redo dynamic array
UndoRedoCommand createUndoRedoCommand() {
    // creating undo dynamic array
    UndoDynamicArray uda;
    uda.capacity = INITIAL_CAPACITY;
    uda.size = 0;
    uda.data = (UndoCommand*) malloc(uda.capacity * sizeof(UndoCommand));

    // if we couldn't allocate memory for undo stack, we set the capacity and size to 0
    if (uda.data == NULL) {
        uda.capacity = 0;
        uda.size = 0;
        perror("Couldn't allocate undo stack!");
    }

    // creating redo dynamic array
    RedoDynamicArray rda;
    rda.capacity = INITIAL_CAPACITY;
    rda.size = 0;
    rda.data = (RedoCommand*) malloc(rda.capacity * sizeof(RedoCommand));

    // if we couldn't allocate memory for redo stack, we free the memory allocated for undo stack
    if (rda.data == NULL) {
        uda.capacity = 0;
        uda.size = 0;
        free(uda.data);

        rda.capacity = 0;
        rda.size = 0;
        perror("Couldn't allocate redo stack!");
    }

    // creating undo redo command
    UndoRedoCommand urc = {
        .uda = uda,
        .rda = rda
    };

    return urc;
}

// function to destroy undo redo dynamic array
void destroyUndoRedoCommand(UndoRedoCommand *urc) {
    // freeing undo dynamic array
    urc->uda.capacity = 0;
    urc->uda.size = 0;

    if (urc->uda.data != NULL) {
        free(urc->uda.data);
        urc->uda.data = NULL;
    }

    // freeing redo dynamic array
    urc->rda.capacity = 0;
    urc->rda.size = 0;

    if (urc->rda.data != NULL) {
        free(urc->rda.data);
        urc->rda.data = NULL;
    }
}

// function to push undo command
bool pushUndoCommand(UndoRedoCommand *urc, UndoCommand undo_command) {
    if (urc->uda.data == NULL) {
        return false;
    }

    if (urc->uda.size >= urc->uda.capacity) { // if we reached the capacity of the undo stack
        int newCapacity = urc->uda.capacity * CAPACITY_MULTIPLIER; // we double the capacity
        UndoCommand *newData = (UndoCommand*) realloc(urc->uda.data, newCapacity * sizeof(UndoCommand));

        if (newData == NULL) { // if we couldn't allocate memory for the new undo stack
            return false;
        }

        // we update the undo stack
        urc->uda.data = newData;
        urc->uda.capacity = newCapacity;
    }
    // we add the undo command to the undo stack
    urc->uda.data[urc->uda.size++] = undo_command;
    return true;
}

// function to pop undo command
UndoCommand popUndoCommand(UndoRedoCommand *urc) {
    if (urc->uda.data == NULL) { // if the undo stack is not allocated
        UndoCommand uc = {
            .undoType = UNDO_ERROR
        };
        return uc;
    }

    if (urc->uda.size == 0) { // if the undo stack is empty
        UndoCommand uc = {
            .undoType = UNDO_ERROR
        };
        return uc;
    }

    // we return the last undo command from the undo stack
    return urc->uda.data[--urc->uda.size];
}

// function to push redo command
bool pushRedoCommand(UndoRedoCommand *urc, RedoCommand redo_command) {
    if (urc->rda.data == NULL) {
        return false;
    }

    if (urc->rda.size >= urc->rda.capacity) { // if we reached the capacity of the redo stack
        int newCapacity = urc->rda.capacity * CAPACITY_MULTIPLIER; // we double the capacity
        RedoCommand *newData = (RedoCommand*) realloc(urc->rda.data, newCapacity * sizeof(RedoCommand));

        if (newData == NULL) {
            return false;
        }

        // we update the redo stack
        urc->rda.data = newData;
        urc->rda.capacity = newCapacity;
    }

    // we add the redo command to the redo stack
    urc->rda.data[urc->rda.size++] = redo_command;
    return true;
}

// function to pop redo command
RedoCommand popRedoCommand(UndoRedoCommand *urc) {
    if (urc->rda.data == NULL) {
        RedoCommand rc = {
            .redoType = REDO_ERROR
        };
        return rc;
    }

    if (urc->rda.size == 0) {
        RedoCommand rc = {
            .redoType = REDO_ERROR
        };
        return rc;
    }

    // we return the last redo command from the redo stack
    return urc->rda.data[--urc->rda.size];
}