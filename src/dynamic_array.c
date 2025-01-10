#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

#define INITIAL_CAPACITY 10

dsa_dynamic_array *dsa_dynamic_array_create(int initial_capacity) {
	dsa_dynamic_array *dynamic_array = (dsa_dynamic_array *) malloc(sizeof(dsa_dynamic_array));
	if (!dynamic_array) return NULL;

	int *array = (int *) malloc(sizeof(int) * initial_capacity);
	if (!array) return NULL;

	dynamic_array->array = array;
	dynamic_array->size = 0;
	dynamic_array->capacity = initial_capacity;

	return dynamic_array;
}

void dsa_dynamic_array_destroy(dsa_dynamic_array *dynamic_array) {
	free(dynamic_array->array);
	dynamic_array->array = NULL;
	
	free(dynamic_array);
	dynamic_array = NULL;
}

void dsa_dynamic_array_insert(dsa_dynamic_array *dynamic_array, int index, const int value) {
    if (index < 0) return;

	if (index > dynamic_array->size) {
		dsa_dynamic_array_resize(dynamic_array, 2);
	}

	if (dsa_dynamic_array_is_full(dynamic_array)) {
		dsa_dynamic_array_resize(dynamic_array, 2);
	}

	dsa_dynamic_array_shift_elements(dynamic_array, index, 1);
	dynamic_array->array[index] = value;
	dynamic_array->size++;
}

int dsa_dynamic_array_remove(dsa_dynamic_array *dynamic_array, int index) {
	if ((dynamic_array->capacity / dynamic_array->size) == 2) {
		dsa_dynamic_array_resize(dynamic_array, 0.5);	
	}

	int value = dynamic_array->array[index];
	dsa_dynamic_array_shift_elements(dynamic_array, index, -1);
	dynamic_array->size--;

	return value;
};

int dsa_dynamic_array_get(dsa_dynamic_array *dynamic_array, int index) {
	return dynamic_array->array[index];
}

void dsa_dynamic_array_set(dsa_dynamic_array *dynamic_array, int index, int value) {
	if (index > dynamic_array->size) {
		dynamic_array->size = index;
	}

	dynamic_array->array[index] = value;
}

bool dsa_dynamic_array_is_full(dsa_dynamic_array *dynamic_array) {
	return dynamic_array->size == dynamic_array->capacity;
}

bool dsa_dynamic_array_is_empty(dsa_dynamic_array *dynamic_array) {
	return dynamic_array->size == 0;
}

void dsa_dynamic_array_resize(dsa_dynamic_array *dynamic_array, float new_capacity) {
	int *array = (int *) realloc(dynamic_array->array, sizeof(int) * new_capacity);
	if (!array) {
		perror("Failed to resize dynamic array");
		exit(EXIT_FAILURE);
	}

	dynamic_array->capacity *= new_capacity;
	dynamic_array->array = array;
}

void dsa_dynamic_array_shift_elements(dsa_dynamic_array *dynamic_array, int index, int direction) {
	if (direction > 0) {
		for (int i = dynamic_array->size; i >= index; i--) {
			dynamic_array->array[i + 1] = dynamic_array->array[i];
		}
	} else if (direction < 0) {
		for (int i = index; i <= dynamic_array->size; i++) {
			dynamic_array->array[i] = dynamic_array->array[i + 1];
		}
	}
}

void dsa_dynamic_array_print(dsa_dynamic_array *dynamic_array) {
	printf("{ ");
	for (int i = 0; i <= dynamic_array->capacity; i++) {
		printf("%d", dynamic_array->array[i]);
		if (i < dynamic_array->capacity) {
			printf(", ");
		} 
	}
	printf(" }\n");
}

