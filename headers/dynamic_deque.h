#ifndef DSA_DYNAMIC_DEQUE_H
#define DSA_DYNAMIC_DEQUE_H

#include <stdbool.h>
#include "dynamic_array.h"

typedef struct {
	dsa_dynamic_array *dynamic_array;
	size_t front;
	size_t back;
} dsa_dynamic_deque;

dsa_dynamic_deque *dsa_dynamic_deque_create(size_t element_size, int initial_capacity);
void dsa_dynamic_deque_destroy(dsa_dynamic_deque *dynamic_deque);

void dsa_dynamic_deque_insert_front(dsa_dynamic_deque *dynamic_dequew, const void *value);
void *dsa_dynamic_deque_remove_front(dsa_dynamic_deque *dynamic_deque);

void dsa_dynamic_deque_insert_back(dsa_dynamic_deque *dynamic_dequew, const void *value);
void *dsa_dynamic_deque_remove_back(dsa_dynamic_deque *dynamic_deque);

void dsa_dynamic_deque_set(dsa_dynamic_deque *dynamic_deque, size_t index, const void *value);
void *dsa_dynamic_deque_get(dsa_dynamic_deque *dynamic_deque, size_t index);

bool dsa_dynamic_deque_is_full(dsa_dynamic_deque *dynamic_deque);
bool dsa_dynamic_deque_is_empty(dsa_dynamic_deque *dynamic_deque);

void dsa_dynamic_deque_print(dsa_dynamic_deque *dynamic_deque, const char *type);

void *dsa_dynamic_deque_peek_front(dsa_dynamic_deque *dynamic_deque);
void *dsa_dynamic_deque_peek_back(dsa_dynamic_deque *dynamic_deque); 

#endif // !DSA_DYNAMIC_DEQUE_H
