#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct SNode {
    int data;
    struct SNode *next;
} SNode;

typedef struct {
    SNode *top;
} Stack;

Stack* createStack(void);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
int isEmpty(Stack *stack);
void freeStack(Stack *stack);

#endif