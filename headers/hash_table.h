#ifndef DSA_HASH_TABLE_H
#define DSA_HASH_TABLE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	char *key;
	char *value;
} dsa_ht_entry;

typedef struct {
	dsa_ht_entry **buckets;
	size_t size;
	size_t count;
} dsa_hash_table;

dsa_ht_entry *dsa_ht_entry_create(char *key, char *value);
void dsa_ht_entry_destroy(dsa_ht_entry *entry);
dsa_ht_entry *dsa_hash_table_next(dsa_hash_table *hash_table, size_t *index);

dsa_hash_table *dsa_hash_table_create(size_t initial_capacity);
void dsa_hash_table_destroy(dsa_hash_table *hash_table);

void dsa_hash_table_insert(dsa_hash_table *hash_table, char *key, char *value);
char *dsa_hash_table_get(dsa_hash_table *hash_table, char *key);
void dsa_hash_table_remove(dsa_hash_table *hash_table, char *key);

bool dsa_hash_table_is_full(dsa_hash_table *hash_table);
bool dsa_hash_table_is_empty(dsa_hash_table *hash_table);
bool dsa_hash_table_probe(dsa_hash_table *hash_table, char *key, size_t *out_index); 

void dsa_hash_table_print(dsa_hash_table *hash_table); 
double dsa_hash_table_load_factor(dsa_hash_table *hash_table);

#endif // !DSA_HASH_TABLE_H
