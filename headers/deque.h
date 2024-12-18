#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

	typedef struct {
		int *arr;
		int capacity;
		int front;
		int back;
	} Deque;

	Deque *deque();
	void pushFront(Deque *deque, int value);
	void pushBack(Deque *deque, int value);
	int popFront(Deque *deqeue);
	int popBack(Deque *deqeue);
	void compactDeque(Deque *deque);
	void printDeque(Deque *deque);
	bool isDequeEmpty(Deque *deque);
	void freeDeque(Deque *deque);

#endif // DEQUE_H
