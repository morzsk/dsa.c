#ifndef DSA_DYNAMIC_DEQUE_H
#define DSA_DYNAMIC_DEQUE_H

#include <stdbool.h>
#include "dynamic_array.h"

typedef struct {
	dsa_dynamic_array *dynamic_array;
	int front;
	int back;
} dsa_dynamic_deque;

dsa_dynamic_deque *dsa_dynamic_deque_create(int initial_capacity);
void dsa_dynamic_deque_destroy(dsa_dynamic_deque *dynamic_deque);

void dsa_dynamic_deque_insert_front(dsa_dynamic_deque *dynamic_dequew, const int value);
int dsa_dynamic_deque_remove_front(dsa_dynamic_deque *dynamic_deque);

void dsa_dynamic_deque_insert_back(dsa_dynamic_deque *dynamic_dequew, const int value);
int dsa_dynamic_deque_remove_back(dsa_dynamic_deque *dynamic_deque);

void dsa_dynamic_deque_set(dsa_dynamic_deque *dynamic_deque, int index, const int value);
int dsa_dynamic_deque_get(dsa_dynamic_deque *dynamic_deque, int index);

bool dsa_dynamic_deque_is_full(dsa_dynamic_deque *dynamic_deque);
bool dsa_dynamic_deque_is_empty(dsa_dynamic_deque *dynamic_deque);

void dsa_dynamic_deque_print(dsa_dynamic_deque *dynamic_deque);

int dsa_dynamic_deque_peek_front(dsa_dynamic_deque *dynamic_deque);
int dsa_dynamic_deque_peek_back(dsa_dynamic_deque *dynamic_deque); 

#endif // !DSA_DYNAMIC_DEQUE_H
