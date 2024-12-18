#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct {
	int *arr;
	int capacity;
	int front;
	int back;
} Queue;

Queue *queue();
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
void compactQueue(Queue *queue);
void printQueue(Queue *queue);
bool isQueueFull(Queue *queue);
bool isQueueEmpty(Queue *queue);
void freeQueue(Queue *queue);

#endif // QUEUE_H
