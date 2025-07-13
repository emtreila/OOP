#ifndef UNDOREDOCOMMAND_H
#define UNDOREDOCOMMAND_H

#include "../domain/Estate.h"
#include <stdbool.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10
#define CAPACITY_MULTIPLIER 2

// undo type
typedef enum {
    UNDO_ERROR,
    UNDO_ADD,
    UNDO_REMOVE,
    UNDO_UPDATE
} UndoType;

// redo type
typedef enum {
    REDO_ERROR,
    REDO_ADD,
    REDO_REMOVE,
    REDO_UPDATE
} RedoType;

// undo command
typedef struct {
    UndoType undoType;
    Estate estate;
} UndoCommand;

// redo command
typedef struct {
    RedoType redoType;
    Estate estate;
} RedoCommand;

// dynamic array for undo commands
typedef struct {
    UndoCommand *data;
    int capacity;
    int size;
} UndoDynamicArray;

// dynamic array for redo commands
typedef struct {
    RedoCommand *data;
    int capacity;
    int size;
} RedoDynamicArray;

// undo redo command
typedef struct {
    UndoDynamicArray uda;
    RedoDynamicArray rda;
} UndoRedoCommand;

// function to create undo redo dynamic array
UndoRedoCommand createUndoRedoCommand();

// function to destroy undo redo dynamic array
void destroyUndoRedoCommand(UndoRedoCommand *urc);

// function to push undo command
bool pushUndoCommand(UndoRedoCommand *urc, UndoCommand undo_command);

// function to pop undo command
UndoCommand popUndoCommand(UndoRedoCommand *urc);

// function to push redo command
bool pushRedoCommand(UndoRedoCommand *urc, RedoCommand redo_command);

// function to pop redo command
RedoCommand popRedoCommand(UndoRedoCommand *urc);

#endif //UNDOREDOCOMMAND_H
