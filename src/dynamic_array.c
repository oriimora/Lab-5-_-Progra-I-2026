#include "../include/dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray *createArray(int capacity)
{
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));

    array->data = (int *)malloc(capacity * sizeof(int));

    array->size = 0;

    array->capacity = capacity;

    return array;
}
void addElement(DynamicArray *array, int value)
{
    if (array->size == array->capacity)
    {
        array->capacity = array->capacity * 2;

        array->data = (int *)realloc(array->data,
                                     array->capacity * sizeof(int));
    }

    array->data[array->size] = value;

    array->size++;
}

void removeElement(DynamicArray *array, int value)
{
    int index = -1;

    // Buscar el elemento
    for (int i = 0; i < array->size; i++)
    {
        if (array->data[i] == value)
        {
            index = i;
            break;
        }
    }

    // Si no existe, salir
    if (index == -1)
    {
        printf("Elemento no encontrado.\n");
        return;
    }

    // Mover los elementos una posición hacia la izquierda
    for (int i = index; i < array->size - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }

    array->size--;
}

int getElement(DynamicArray *array, int index)
{
    if (index < 0 || index >= array->size)
    {
        printf("Indice invalido.\n");
        return -1;
    }

    return array->data[index];
}
void printArray(DynamicArray *array)
{
    printf("Arreglo: ");

    for (int i = 0; i < array->size; i++)
    {
        printf("%d ", array->data[i]);
    }

    printf("\n");
}

void freeArray(DynamicArray *array)
{
    free(array->data);
    free(array);
}