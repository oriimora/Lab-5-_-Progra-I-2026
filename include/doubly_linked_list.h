#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode* createDNode(int data);
void insertAtBeginningD(DNode **head, int data);
void insertAtEndD(DNode **head, int data);
void insertAtPositionD(DNode **head, int data, int position);
void deleteNodeD(DNode **head, int data);
DNode* searchD(DNode *head, int data);
void printListForwardD(DNode *head);
void printListBackwardD(DNode *head);
void freeListD(DNode *head);

#endif