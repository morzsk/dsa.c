#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_deque.h"

dsa_dynamic_deque *dsa_dynamic_deque_create(size_t element_size, int initial_capacity) {
	dsa_dynamic_deque *dynamic_deque = (dsa_dynamic_deque *) malloc(sizeof(dsa_dynamic_deque));
	if (!dynamic_deque) return NULL;

	dsa_dynamic_array *dynamic_array = dsa_dynamic_array_create(element_size, initial_capacity);
	if (!dynamic_array) return NULL;

	dynamic_deque->dynamic_array = dynamic_array;
	dynamic_deque->front = 0;
	dynamic_deque->back = -1;

	return dynamic_deque;
}

void dsa_dynamic_deque_destroy(dsa_dynamic_deque *dynamic_deque) {
	dsa_dynamic_array_destroy(dynamic_deque->dynamic_array);
	free(dynamic_deque);
	dynamic_deque = NULL;
}

void dsa_dynamic_deque_insert_front(dsa_dynamic_deque *dynamic_deque, const void *value) {
	dynamic_deque->back++;
	dsa_dynamic_array_insert(dynamic_deque->dynamic_array, 0, value);
}

void *dsa_dynamic_deque_remove_front(dsa_dynamic_deque *dynamic_deque) {
	void *value = dsa_dynamic_array_remove(dynamic_deque->dynamic_array, 0);
	dynamic_deque->back--;
	return value;
}

void dsa_dynamic_deque_insert_back(dsa_dynamic_deque *dynamic_deque, const void *value) {
	dynamic_deque->back++;
	dsa_dynamic_array_insert(dynamic_deque->dynamic_array, dynamic_deque->back, value);
}

void *dsa_dynamic_deque_remove_back(dsa_dynamic_deque *dynamic_deque) {
	void *value = dsa_dynamic_array_remove(dynamic_deque->dynamic_array, dynamic_deque->back);
	dynamic_deque->back--;
	return value;
}

bool dsa_dynamic_deque_is_full(dsa_dynamic_deque *dynamic_deque) {
	return dsa_dynamic_array_is_full(dynamic_deque->dynamic_array);
}

bool dsa_dynamic_deque_is_empty(dsa_dynamic_deque *dynamic_deque) {
	return dsa_dynamic_array_is_empty(dynamic_deque->dynamic_array);
}

void dsa_dynamic_deque_print(dsa_dynamic_deque *dynamic_deque, const char *type) {
	dsa_dynamic_array_print(dynamic_deque->dynamic_array, type);
}

void *dsa_dynamic_deque_peek_front(dsa_dynamic_deque *dynamic_deque) {
	return (char *) dynamic_deque->dynamic_array->array + 
		   (dynamic_deque->front * dynamic_deque->dynamic_array->element_size);
}

void *dsa_dynamic_deque_peek_back(dsa_dynamic_deque *dynamic_deque) {
	return (char *)dynamic_deque->dynamic_array->array +
           (dynamic_deque->back * dynamic_deque->dynamic_array->element_size);
}

