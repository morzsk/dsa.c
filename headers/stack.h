#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
	int *arr;
	int capacity;
	int top;
} Stack;

Stack *stack();
void push(Stack *stack, int value);
int pop(Stack *stack);
void peek(Stack *stack);
void printStack(Stack *stack);
bool isStackFull(Stack *stack);
bool isStackEmpty(Stack *stack);
void freeStack(Stack *stack);

#endif // STACK_H
