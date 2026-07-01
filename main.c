#include <stdio.h>
#include "include/dynamic_array.h"
#include "include/linked_list.h"
#include "include/doubly_linked_list.h"

int main()
{
    // ARREGLO DINÁMICO
    DynamicArray *array = createArray(3);

    addElement(array, 10);
    addElement(array, 20);
    addElement(array, 30);
    addElement(array, 40);

    printArray(array);

    // LISTA ENLAZADA
    Node *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);

    printList(head);

    insertAtPosition(&head, 25, 1);
    printList(head);

    deleteNode(&head, 20);
    printList(head);

    Node *found = search(head, 30);

    if (found != NULL)
    {
        printf("Elemento encontrado: %d\n", found->data);
    }
    else
    {
        printf("No encontrado\n");
    }

    freeArray(array);
    freeList(head);
// LISTA DOBLEMENTE ENLAZADA
    DNode *dhead = NULL;

    insertAtBeginningD(&dhead, 10);
    insertAtBeginningD(&dhead, 20);
    insertAtEndD(&dhead, 30);

    printListForwardD(dhead);
    printListBackwardD(dhead);

    insertAtPositionD(&dhead, 25, 1);
    printListForwardD(dhead);

    deleteNodeD(&dhead, 20);
    printListForwardD(dhead);

    DNode *foundD = searchD(dhead, 30);

    if (foundD != NULL)
    {
        printf("Elemento encontrado (doble): %d\n", foundD->data);
    }
    else
    {
        printf("No encontrado (doble)\n");
    }

    freeListD(dhead);
    return 0;
}