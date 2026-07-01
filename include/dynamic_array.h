#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createArray(int capacity);

void addElement(DynamicArray *array, int value);

void removeElement(DynamicArray *array, int value);

int getElement(DynamicArray *array, int index);

void printArray(DynamicArray *array);

void freeArray(DynamicArray *array);

#endif
