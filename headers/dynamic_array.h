#ifndef DSA_DYNAMIC_ARRAY_H
#define DSA_DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	void *array;
	size_t element_size;
	size_t size;
	size_t capacity;
} dsa_dynamic_array;

dsa_dynamic_array *dsa_dynamic_array_create(size_t element_size, size_t initial_capacity);
void dsa_dynamic_array_destroy(dsa_dynamic_array *dynamic_array);

void dsa_dynamic_array_insert(dsa_dynamic_array *dynamic_array, size_t index, const void *value);
void *dsa_dynamic_array_remove(dsa_dynamic_array *dynamic_array, size_t index);

void *dsa_dynamic_array_get(dsa_dynamic_array *dynamic_array, size_t index);
void dsa_dynamic_array_set(dsa_dynamic_array *dynamic_array, size_t index, const void *value);

bool dsa_dynamic_array_is_full(dsa_dynamic_array *dynamic_array);
bool dsa_dynamic_array_is_empty(dsa_dynamic_array *dynamic_array);

void dsa_dynamic_array_resize(dsa_dynamic_array *dynamic_array, float new_capacity);
void dsa_dynamic_array_shift_elements(dsa_dynamic_array *dynamic_array, size_t index, int direction);

void dsa_dynamic_array_print(dsa_dynamic_array *dynamic_array, const char *type);

#endif // !DSA_DYNAMIC_ARRAY_H
