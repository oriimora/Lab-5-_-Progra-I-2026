#include <stdio.h>
#include "include/dynamic_array.h"
#include "include/linked_list.h"

int main()
{
    // ----------------------------
    // ARREGLO DINÁMICO (lo que ya hiciste)
    // ----------------------------
    DynamicArray *array = createArray(3);

    addElement(array, 10);
    addElement(array, 20);
    addElement(array, 30);
    addElement(array, 40);

    printArray(array);

    // ----------------------------
    // LISTA ENLAZADA (AQUÍ EMPIEZA)
    // ----------------------------

    Node *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);

    printList(head);

    return 0;
}