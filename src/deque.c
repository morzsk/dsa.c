#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "deque.h"

#define INITIAL_CAPACITY 10

Deque *deque() {
	Deque *deque = (Deque *) malloc(sizeof(Deque));
	deque->arr = (int *) malloc(INITIAL_CAPACITY * sizeof(int));
	deque->capacity = INITIAL_CAPACITY;
	deque->front = 0;
	deque->back = -1;
	return deque;
}

void pushFront(Deque *deque, int value) {
	if (deque->front == 0) {
		return;
	}
	deque->arr[--deque->front] = value;
}

void pushBack(Deque *deque, int value) {
	if (deque->back == deque->capacity) {
		deque->capacity *= 2;
		deque->arr = (int *) realloc(deque->arr, deque->capacity * sizeof(int));
	}
	deque->arr[++deque->back] = value;
}

int popFront(Deque *deque) {
	if (deque->front + 1 > deque->back) { return -1; }
	int value = deque->arr[deque->front];
	deque->front++;
	compactDeque(deque);

	return value;
}

int popBack(Deque *deque) {
	if (deque->back - 1 < deque->front) { return -1; }
	return deque->arr[deque->back--];
}

void compactDeque(Deque *deque) {
	int size = deque->back - deque->front + 1;
	if (size <= 0) {
		deque->front = 0;
		deque->back = -1;
	}

	int *newArr = (int *) malloc(deque->capacity * sizeof(int));
	memmove(newArr, &deque->arr[deque->front], size * sizeof(int));
	free(deque->arr);

	deque->arr = newArr;
	deque->back = size - 1;
	deque->front = 0;
}

void printDeque(Deque *deque) {
	printf("{ ");
	for (int i = 0; i <= deque->back; i++) {
		printf("%d", deque->arr[i]);
		if (i < deque->back) {
			printf(", ");
		} 
	}
	printf(" }\n");
}

