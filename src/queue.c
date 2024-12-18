#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "queue.h"

#define INITIAL_CAPACITY 10

Queue *queue() {
	Queue *queue = (Queue *) malloc(sizeof(Queue));
	queue->arr = (int *) malloc(INITIAL_CAPACITY * sizeof(int));
	queue->capacity = INITIAL_CAPACITY;
	queue->front = 0;
	queue->back = -1;
	return queue;
}

void enqueue(Queue *queue, int value) {
	if (isQueueFull(queue)){
		queue->capacity *= 2;
		queue->arr = (int *) realloc(queue->arr, queue->capacity * sizeof(int));
	}
	queue->arr[++queue->back] = value;  	
}

int dequeue(Queue *queue) {
	if (isQueueEmpty(queue)) {return -1;}
	int value = queue->arr[queue->front];
    queue->front++;
	compactQueue(queue);

	return value;
}

void compactQueue(Queue *queue) {
    int size = queue->back - queue->front + 1;
    if (size <= 0) {
        queue->front = 0;
        queue->back = -1;
        return;
    }

    int *newArr = (int *) malloc(queue->capacity * sizeof(int));
    memmove(newArr, &queue->arr[queue->front], size * sizeof(int));
    free(queue->arr);

    queue->arr = newArr;
    queue->back = size - 1;
    queue->front = 0;
}

void printQueue(Queue *queue) {
	printf("{ ");
	for (int i = 0; i <= queue->back; i++) {
		printf("%d", queue->arr[i]);
		if (i < queue->back) {
			printf(", ");
		} 
	}
	printf(" }\n");
}

bool isQueueFull(Queue *queue) {
	return (queue->back + 1 == queue->capacity);
}

bool isQueueEmpty(Queue *queue) {
	return (queue->front > queue->back);
}

