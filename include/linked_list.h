#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// funciones
Node* createNode(int data);
void insertAtBeginning(Node **head, int data);
void insertAtEnd(Node **head, int data);
void insertAtPosition(Node **head, int data, int position);
void deleteNode(Node **head, int data);
Node* search(Node *head, int data);
void printList(Node *head);

void freeList(Node *head);

#endif