#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define INITIAL_CAPACITY 10

Stack *stack() {
	Stack *stack = (Stack *) malloc(sizeof(Stack));
	stack->arr = (int *) malloc(INITIAL_CAPACITY * sizeof(int));
	stack->capacity = INITIAL_CAPACITY;
	stack->top = -1;
	return stack;
}

void push(Stack *stack, int value) {
	if (isStackFull(stack)) {
		stack->capacity *= 2;
		stack->arr = (int *) realloc(stack->arr, stack->capacity * sizeof(int));
	}
	stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
	if (isStackEmpty(stack)) { return -1; }
	return stack->arr[stack->top--];
}

int peek(Stack *stack) {
	return stack->top;
}

void printStack(Stack *stack) {
	printf("{ ");
	for (int i = 0; i <= stack->top; i++) {
		printf("%d", stack->arr[i]);
		if (i < stack->top) {
			printf(", ");
		} 
	}
	printf(" }\n");
}

bool isStackFull(Stack *stack) {
	return (stack->top + 1 == stack->capacity);
}

bool isStackEmpty(Stack *stack) {
	return (stack->top == -1);
}
