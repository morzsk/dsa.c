#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "hash.h"

dsa_ht_entry *dsa_ht_entry_create(char *key, void *value) {
	dsa_ht_entry *entry = (dsa_ht_entry *) malloc(sizeof(dsa_ht_entry));
	if (entry == NULL) {
		fprintf(stderr, "Failed to allocate memory for a new entry\n");
		return NULL;
	}

	entry->key = key;
	entry->value = value;
	return entry;
}

void dsa_ht_entry_destroy(dsa_ht_entry *entry) {
	if (!entry) {
		fprintf(stderr, "Attempted to destroy a NULL entry\n");
		return;
	}

	if (entry->key) {
		free(entry->key);
		entry->key = NULL;
	}

	if (entry->value) {
		free(entry->value);
		entry->value = NULL;
	}
	
	free(entry);
	entry = NULL;
}

dsa_ht_entry *dsa_hash_table_next(dsa_hash_table *hash_table, size_t *index);

dsa_hash_table *dsa_hash_table_create(size_t initial_capacity) {
	dsa_hash_table *hash_table = (dsa_hash_table *) malloc(sizeof(dsa_hash_table));
	if (hash_table == NULL) {
		fprintf(stderr, "Failed to allocate memory for a hash table\n");
		return NULL;
	}

	dsa_singly_linked_list **buckets = (dsa_singly_linked_list **) malloc(sizeof(dsa_singly_linked_list *) * initial_capacity);
	if (buckets == NULL) {
		fprintf(stderr, "Failed to allocate memory for a bucket\n");
		return NULL;
	}

	hash_table->buckets = buckets;
	hash_table->size = initial_capacity;
	hash_table->count = 0;
	return hash_table;
} 

void dsa_hash_table_destroy(dsa_hash_table *hash_table) {
    if (!hash_table) {
        fprintf(stderr, "Attempted to destroy a NULL hash table\n");
        return;
    }

    for (size_t i = 0; i < hash_table->size; i++) {
        dsa_ht_entry *entry = (dsa_ht_entry *) hash_table->buckets[i];
        if (entry) {
            dsa_ht_entry_destroy(entry);
        }
    }

    free(hash_table->buckets);
    hash_table->buckets = NULL;

    free(hash_table);
    hash_table = NULL;
}

void dsa_hash_table_insert(dsa_hash_table *hash_table, char *key, void *value) {
	if (!hash_table || !key || !value) {
        fprintf(stderr, "Invalid hash table or key or value\n");
        return;
    }

	size_t index = dsa_djb2_hash(key, hash_table->size);
	
    dsa_singly_linked_list *bucket = hash_table->buckets[index];
    if (!bucket) {
        hash_table->buckets[index] = dsa_singly_linked_list_create();
        bucket = hash_table->buckets[index];
    }

    dsa_sll_node *current = bucket->head;
    while (current) {
        dsa_ht_entry *entry = (dsa_ht_entry *)current->value;
        if (strcmp(entry->key, key) == 0) {
            free(entry->value);
            entry->value = strdup(value);
            return;
        }
        current = current->next;
    }

    dsa_ht_entry *new_entry = dsa_ht_entry_create(strdup(key), strdup(value));
    dsa_singly_linked_list_insert_head(bucket, new_entry);
    hash_table->count++;
}

char *dsa_hash_table_get(dsa_hash_table *hash_table, char *key) {
    if (!hash_table || !key) {
        fprintf(stderr, "Invalid hash table or key\n");
        return NULL;
    }

    size_t index = dsa_djb2_hash(key, hash_table->size);
    dsa_singly_linked_list *bucket = hash_table->buckets[index];
    if (!bucket) {
        fprintf(stderr, "Error: Key '%s' not found in hash table (bucket is empty).\n", key);
        return NULL;
    }

    dsa_sll_node *current = bucket->head;
    while (current) {
        dsa_ht_entry *entry = (dsa_ht_entry *)current->value;
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        current = current->next;
    }

    fprintf(stderr, "Error: Key '%s' not found in hash table.\n", key);
    return NULL;
}	

void dsa_hash_table_remove(dsa_hash_table *hash_table, char *key) {
    if (!hash_table || !key) {
        fprintf(stderr, "Invalid hash table or key\n");
        return;
    }

    size_t index = dsa_djb2_hash(key, hash_table->size);
    dsa_singly_linked_list *bucket = hash_table->buckets[index];
    if (!bucket) {
        fprintf(stderr, "Error: Key '%s' not found in hash table (bucket is empty).\n", key);
        return;
    }

    // Traverse the linked list to find and remove the key
    dsa_sll_node *prev = NULL;
    dsa_sll_node *current = bucket->head;

    while (current) {
        dsa_ht_entry *entry = (dsa_ht_entry *)current->value;
        if (strcmp(entry->key, key) == 0) {
            // Remove the node
            if (prev) {
                prev->next = current->next;
            } else {
                bucket->head = current->next;
            }
            if (current == bucket->tail) {
                bucket->tail = prev;
            }

            dsa_ht_entry_destroy(entry);
            free(current);
            hash_table->count--;

            printf("Key '%s' removed from hash table.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }

    fprintf(stderr, "Error: Key '%s' not found in hash table.\n", key);
}

bool dsa_hash_table_is_full(dsa_hash_table *hash_table) {
    if (!hash_table) {
        fprintf(stderr, "Invalid hash table\n");
        return false;
    }

    double load_factor = (double)hash_table->count / hash_table->size;
    return load_factor >= 0.75;
}

bool dsa_hash_table_is_empty(dsa_hash_table *hash_table) {
    if (!hash_table) {
        fprintf(stderr, "Invalid hash table\n");
        return false;
    }

    return hash_table->count == 0;
}

void dsa_hash_table_print(dsa_hash_table *hash_table, const char* type) {
    if (!hash_table) {
        fprintf(stderr, "Invalid hash table\n");
        return;
    }

    printf("Hash Table:\n");
    for (size_t i = 0; i < hash_table->size; i++) {
        dsa_singly_linked_list *bucket = hash_table->buckets[i];

        printf("%zu: ", i);

        if (bucket && bucket->head) {
            dsa_sll_node *current = bucket->head;
            while (current) {
                dsa_ht_entry *entry = (dsa_ht_entry *)current->value;
                printf("{ \"%s\": ", entry->key);

                // Print value based on type
                if (strcmp(type, "int") == 0) {
                    printf("%d", *(int *)entry->value);
                } else if (strcmp(type, "float") == 0) {
                    printf("%f", *(float *)entry->value);
                } else if (strcmp(type, "double") == 0) {
                    printf("%lf", *(double *)entry->value);
                } else if (strcmp(type, "char") == 0) {
                    printf("'%c'", *(char *)entry->value);
                } else if (strcmp(type, "string") == 0) {
                    printf("\"%s\"", (char *)entry->value);
                } else if (strcmp(type, "short") == 0) {
                    printf("%d", *(short *)entry->value);
                } else if (strcmp(type, "long") == 0) {
                    printf("%ld", *(long *)entry->value);
                } else if (strcmp(type, "long long") == 0) {
                    printf("%lld", *(long long *)entry->value);
                } else if (strcmp(type, "unsigned int") == 0) {
                    printf("%u", *(unsigned int *)entry->value);
                } else if (strcmp(type, "bool") == 0) {
                    printf("%s", *(int *)entry->value ? "true" : "false");
                } else if (strcmp(type, "size_t") == 0) {
                    printf("%zu", *(size_t *)entry->value);
                } else {
                    printf("?");
                }

                printf(" }");

                current = current->next;
                if (current) {
                    printf(" -> ");
                }
            }
        } else {
            printf("∅");
        }

        printf("\n");
    }
}

double dsa_hash_table_load_factor(dsa_hash_table *hash_table) {
	return (double) hash_table->count / hash_table->size;
}
