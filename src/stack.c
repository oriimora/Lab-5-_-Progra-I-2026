#include "../include/stack.h"

Stack* createStack(void)
{
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int value)
{
    SNode *newNode = (SNode*) malloc(sizeof(SNode));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack vacio, no se puede hacer pop\n");
        return -1;
    }

    SNode *temp = stack->top;
    int value = temp->data;

    stack->top = stack->top->next;
    free(temp);

    return value;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack vacio, no hay elemento en el top\n");
        return -1;
    }

    return stack->top->data;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void freeStack(Stack *stack)
{
    SNode *temp;

    while (stack->top != NULL)
    {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }

    free(stack);
}