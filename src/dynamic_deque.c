#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_deque.h"

dsa_dynamic_deque *dsa_dynamic_deque_create(int initial_capacity) {
	dsa_dynamic_deque *dynamic_deque = (dsa_dynamic_deque *) malloc(sizeof(dsa_dynamic_deque));
	dsa_dynamic_array *dynamic_array = dsa_dynamic_array_create(initial_capacity);

	dynamic_deque->dynamic_array = dynamic_array;
	dynamic_deque->front = 0;
	dynamic_deque->back = 0;

	return dynamic_deque;
}

void dsa_dynamic_deque_destroy(dsa_dynamic_deque *dynamic_deque) {
	dsa_dynamic_array_destroy(dynamic_deque->dynamic_array);
	free(dynamic_deque);
	dynamic_deque = NULL;
}

void dsa_dynamic_deque_insert_front(dsa_dynamic_deque *dynamic_deque, const int value) {
	if (dsa_dynamic_deque_is_full(dynamic_deque)) {
		dsa_dynamic_array_resize(dynamic_deque->dynamic_array, 2);
	}
	dsa_dynamic_array_insert(dynamic_deque->dynamic_array, 0, value);
}

int dsa_dynamic_deque_remove_front(dsa_dynamic_deque *dynamic_deque) {
	if (dsa_dynamic_deque_is_empty(dynamic_deque)) return -1;

	int value = dsa_dynamic_array_remove(dynamic_deque->dynamic_array, 0);
	return value;
}

void dsa_dynamic_deque_insert_back(dsa_dynamic_deque *dynamic_deque, const int value) {
	if (dsa_dynamic_deque_is_full(dynamic_deque)) {
		dsa_dynamic_array_resize(dynamic_deque->dynamic_array, 2);
	}

	dsa_dynamic_array_insert(dynamic_deque->dynamic_array, dynamic_deque->back, value);
	dynamic_deque->back++;
}

int dsa_dynamic_deque_remove_back(dsa_dynamic_deque *dynamic_deque) {
	if ((dynamic_deque->dynamic_array->capacity / dynamic_deque->dynamic_array->size) == 2) {
		dsa_dynamic_array_resize(dynamic_deque->dynamic_array, 0.5);
	}

	int value = dsa_dynamic_array_remove(dynamic_deque->dynamic_array, dynamic_deque->back);
	dynamic_deque->back--;
	return value;
}

bool dsa_dynamic_deque_is_full(dsa_dynamic_deque *dynamic_deque) {
	return dsa_dynamic_array_is_full(dynamic_deque->dynamic_array);
}

bool dsa_dynamic_deque_is_empty(dsa_dynamic_deque *dynamic_deque) {
	return dsa_dynamic_array_is_empty(dynamic_deque->dynamic_array);
}

void dsa_dynamic_deque_print(dsa_dynamic_deque *dynamic_deque) {
	dsa_dynamic_array_print(dynamic_deque->dynamic_array);
}

int dsa_dynamic_deque_peek_front(dsa_dynamic_deque *dynamic_deque) {
	return dynamic_deque->dynamic_array->array[dynamic_deque->front];
}

int dsa_dynamic_deque_peek_back(dsa_dynamic_deque *dynamic_deque) {
	return dynamic_deque->dynamic_array->array[dynamic_deque->back];
}

