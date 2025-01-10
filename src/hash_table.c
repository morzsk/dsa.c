#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "hash.h"

dsa_ht_entry *dsa_ht_entry_create(char *key, char *value) {
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

	dsa_ht_entry **buckets = (dsa_ht_entry **) calloc(initial_capacity, sizeof(dsa_ht_entry *));
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

void dsa_hash_table_insert(dsa_hash_table *hash_table, char *key, char *value) {
	if (!hash_table || !key || !value) {
        fprintf(stderr, "Invalid hash table or key or value\n");
        return;
    }

	size_t index = dsa_djb2_hash(key, hash_table->size);
	
	hash_table->buckets[index] = dsa_ht_entry_create(strdup(key), strdup(value));
    hash_table->count++;
}

char *dsa_hash_table_get(dsa_hash_table *hash_table, char *key) {
    if (!hash_table || !key) {
        fprintf(stderr, "Invalid hash table or key\n");
        return NULL;
    }

    size_t index = dsa_djb2_hash(key, hash_table->size);
    dsa_ht_entry *entry = hash_table->buckets[index];
    if (!entry) {
        fprintf(stderr, "Key '%s' not found in hash table\n", key);
        return NULL;
    }

    if (strcmp(entry->key, key) == 0) {
        return entry->value;
    } else {
        fprintf(stderr, "Key '%s' not found at expected location\n", key);
        return NULL;
    }
}	

void dsa_hash_table_remove(dsa_hash_table *hash_table, char *key) {
    if (!hash_table || !key) {
        fprintf(stderr, "Invalid hash table or key\n");
        return;
    }

    size_t index = dsa_djb2_hash(key, hash_table->size);
    dsa_ht_entry *entry = hash_table->buckets[index];
    if (!entry) {
        fprintf(stderr, "Key '%s' not found in hash table\n", key);
        return;
    }

	if (strcmp(entry->key, key) == 0) {
        dsa_ht_entry_destroy(entry);
        hash_table->buckets[index] = NULL;
        hash_table->count--;

        printf("Key '%s' removed from hash table\n", key);
    } else {
        fprintf(stderr, "Key '%s' not found at expected location\n", key);
    }
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

void dsa_hash_table_print(dsa_hash_table *hash_table) {
    if (!hash_table) {
        fprintf(stderr, "Invalid hash table\n");
        return;
    }

    printf("Hash Table:\n");
    for (size_t i = 0; i < hash_table->size; i++) {
        dsa_ht_entry *entry = hash_table->buckets[i];
        if (entry) {
            printf("Bucket %zu: Key = %s, Value = %s\n", i, entry->key, entry->value);
        } else {
            printf("Bucket %zu: (empty)\n", i);
        }
    }
} 

double dsa_hash_table_load_factor(dsa_hash_table *hash_table) {
	return (double) hash_table->count / hash_table->size;
}
