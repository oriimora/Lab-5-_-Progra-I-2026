#include "../include/linked_list.h"

Node* createNode(int data)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node *head)
{
    Node *temp = head;

    printf("Lista: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
void insertAtPosition(Node **head, int data, int position)
{
    if (position == 0)
    {
        insertAtBeginning(head, data);
        return;
    }

    Node *newNode = createNode(data);
    Node *temp = *head;

    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Posicion invalida\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node **head, int data)
{
    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Elemento no encontrado\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

Node* search(Node *head, int data)
{
    Node *temp = head;

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

void freeList(Node *head)
{
    Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}