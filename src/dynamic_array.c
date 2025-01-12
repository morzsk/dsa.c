#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

#define INITIAL_CAPACITY 10

dsa_dynamic_array *dsa_dynamic_array_create(size_t element_size, size_t initial_capacity) {
	dsa_dynamic_array *dynamic_array = (dsa_dynamic_array *) malloc(sizeof(dsa_dynamic_array));
	if (!dynamic_array) return NULL;

	void *array = (int *) malloc(element_size * initial_capacity);
	if (!array) {
		free(dynamic_array);
		return NULL;
	};

	dynamic_array->array = array;
	dynamic_array->element_size = element_size;
	dynamic_array->size = 0;
	dynamic_array->capacity = initial_capacity;

	return dynamic_array;
}

void dsa_dynamic_array_destroy(dsa_dynamic_array *dynamic_array) {
    free(dynamic_array->array);
    free(dynamic_array);
    dynamic_array = NULL;
}

void dsa_dynamic_array_insert(dsa_dynamic_array *dynamic_array, size_t index, const void *value) {
    if (index < 0) return;

	if (index > dynamic_array->size) {
		dsa_dynamic_array_resize(dynamic_array, 2);
	}

	if (dsa_dynamic_array_is_full(dynamic_array)) {
		dsa_dynamic_array_resize(dynamic_array, 2);
	}

	dsa_dynamic_array_shift_elements(dynamic_array, index, 1);

	void *target = (char *) dynamic_array->array + (index * dynamic_array->element_size);
	memcpy(target, value, dynamic_array->element_size);

	dynamic_array->size++;
}

void *dsa_dynamic_array_remove(dsa_dynamic_array *dynamic_array, size_t index) {
	if (index < 0 || index >= dynamic_array->size) return NULL;

	if ((dynamic_array->capacity / dynamic_array->size) == 2) {
		dsa_dynamic_array_resize(dynamic_array, 0.5);	
	}

	void *value = malloc(dynamic_array->element_size);
	if (!value) return NULL;

	void *source = (char *) dynamic_array->array + (index * dynamic_array->element_size);
	memcpy(value, source, dynamic_array->element_size);

	dsa_dynamic_array_shift_elements(dynamic_array, index, -1);
	dynamic_array->size--;

	return value;
};

void *dsa_dynamic_array_get(dsa_dynamic_array *dynamic_array, size_t index) {
	if (index < 0 || index >= dynamic_array->size) {
		return NULL;
	}

	return (char *) dynamic_array->array + (index * dynamic_array->element_size);
}

void dsa_dynamic_array_set(dsa_dynamic_array *dynamic_array, size_t index, const void *value) {
	if (index < 0 || index >= dynamic_array->size) {
		return;
	}

	if (index > dynamic_array->size) {
		dynamic_array->size = index;
	}

	void *target = (char *) dynamic_array->array + (index * dynamic_array->element_size);

	memcpy(target, value, dynamic_array->element_size);
}

bool dsa_dynamic_array_is_full(dsa_dynamic_array *dynamic_array) {
	return dynamic_array->size == dynamic_array->capacity;
}

bool dsa_dynamic_array_is_empty(dsa_dynamic_array *dynamic_array) {
	return dynamic_array->size == 0;
}

void dsa_dynamic_array_resize(dsa_dynamic_array *dynamic_array, float multiplier) {
    size_t new_capacity = (size_t) (dynamic_array->capacity * multiplier);
    if (new_capacity < dynamic_array->size) {
        fprintf(stderr, "Resize would truncate data\n");
        return;
    }

    void *new_array = realloc(dynamic_array->array, dynamic_array->element_size * new_capacity);
    if (!new_array) {
        perror("Failed to resize dynamic array");
        exit(EXIT_FAILURE);
    }

    dynamic_array->array = new_array;
    dynamic_array->capacity = new_capacity;
}

void dsa_dynamic_array_shift_elements(dsa_dynamic_array *dynamic_array, size_t index, int direction) {
	if (direction > 0) {
		for (size_t i = dynamic_array->size; i > index; i--) {
			void *dest = (char *) dynamic_array->array + (i * dynamic_array->element_size);
			void *src = (char *) dynamic_array->array + ((i - 1) * dynamic_array->element_size);
			memcpy(dest, src, dynamic_array->element_size);
		}
	} else if (direction < 0) {
		for (size_t i = index; i < dynamic_array->size - 1; i++) {
			void *dest = (char *) dynamic_array->array + (i * dynamic_array->element_size);
			void *src = (char *) dynamic_array->array + ((i + 1) * dynamic_array->element_size);
			memcpy(dest, src, dynamic_array->element_size);
		}
	}
}


void dsa_dynamic_array_print(dsa_dynamic_array *dynamic_array, const char *type) {
    printf("{ ");
    for (size_t i = 0; i < dynamic_array->size; i++) {
        void *element = (char *) dynamic_array->array + (i * dynamic_array->element_size);

        if (strcmp(type, "int") == 0) {
            printf("%d", *(int *)element);
        } else if (strcmp(type, "float") == 0) {
            printf("%f", *(float *)element);
        } else if (strcmp(type, "double") == 0) {
            printf("%lf", *(double *)element);
        } else if (strcmp(type, "char") == 0) {
            printf("'%c'", *(char *)element);
        } else if (strcmp(type, "string") == 0) {
            printf("\"%s\"", *(char **)element);
        } else if (strcmp(type, "short") == 0) {
            printf("%d", *(short *)element);
        } else if (strcmp(type, "long") == 0) {
            printf("%ld", *(long *)element);
        } else if (strcmp(type, "long long") == 0) {
            printf("%lld", *(long long *)element);
        } else if (strcmp(type, "unsigned int") == 0) {
            printf("%u", *(unsigned int *)element);
        } else if (strcmp(type, "bool") == 0) {
            printf("%s", *(int *)element ? "true" : "false");
        } else if (strcmp(type, "size_t") == 0) {
            printf("%zu", *(size_t *)element);
        } else {
            printf("?");
        }

        if (i < dynamic_array->size - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}
