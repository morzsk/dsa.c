#ifndef DSA_DYNAMIC_ARRAY_H
#define DSA_DYNAMIC_ARRAY_H

#include <stdbool.h>

typedef struct {
	int *array;
	int size;
	int capacity;
} dsa_dynamic_array;

dsa_dynamic_array *dsa_dynamic_array_create(int initial_capacity);
void dsa_dynamic_array_destroy(dsa_dynamic_array *dynamic_array);

void dsa_dynamic_array_insert(dsa_dynamic_array *dynamic_array, int index, const int value);
int dsa_dynamic_array_remove(dsa_dynamic_array *dynamic_array, int index);

int dsa_dynamic_array_get(dsa_dynamic_array *dynamic_array, int index);
void dsa_dynamic_array_set(dsa_dynamic_array *dynamic_array, int index, int value);

bool dsa_dynamic_array_is_full(dsa_dynamic_array *dynamic_array);
bool dsa_dynamic_array_is_empty(dsa_dynamic_array *dynamic_array);

void dsa_dynamic_array_resize(dsa_dynamic_array *dynamic_array, float new_capacity);
void dsa_dynamic_array_shift_elements(dsa_dynamic_array *dynamic_array, int index, int direction);

void dsa_dynamic_array_print(dsa_dynamic_array *dynamic_array);

#endif // !DSA_DYNAMIC_ARRAY_H
