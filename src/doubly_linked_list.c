#include "../include/doubly_linked_list.h"

DNode* createDNode(int data)
{
    DNode *newNode = (DNode*) malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginningD(DNode **head, int data)
{
    DNode *newNode = createDNode(data);

    newNode->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void insertAtEndD(DNode **head, int data)
{
    DNode *newNode = createDNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    DNode *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPositionD(DNode **head, int data, int position)
{
    if (position == 0)
    {
        insertAtBeginningD(head, data);
        return;
    }

    DNode *newNode = createDNode(data);
    DNode *temp = *head;

    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Posicion invalida\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteNodeD(DNode **head, int data)
{
    DNode *temp = *head;

    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Elemento no encontrado\n");
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

DNode* searchD(DNode *head, int data)
{
    DNode *temp = head;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void printListForwardD(DNode *head)
{
    DNode *temp = head;

    printf("Lista (adelante): ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void printListBackwardD(DNode *head)
{
    if (head == NULL)
    {
        printf("Lista (atras): NULL\n");
        return;
    }

    DNode *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Lista (atras): ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

void freeListD(DNode *head)
{
    DNode *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}