#ifndef DSA_SINGLY_LINKED_LIST_H
#define DSA_SINGLY_LINKED_LIST_H

typedef struct dsa_sll_node {
	int value;
	struct dsa_sll_node *next;
} dsa_sll_node;

typedef struct {
	dsa_sll_node *head;
	dsa_sll_node *tail;
} dsa_singly_linked_list;

dsa_singly_linked_list *dsa_singly_linked_list_create();
void dsa_singly_linked_list_destroy(dsa_singly_linked_list *singly_linked_list);

dsa_sll_node *dsa_sll_node_create(int value, dsa_sll_node *next);
void dsa_sll_node_destroy(dsa_sll_node *node);

void dsa_singly_linked_list_insert_head(dsa_singly_linked_list *singly_linked_list, int value);
int dsa_singly_linked_list_remove_head(dsa_singly_linked_list *singly_linked_list);

void dsa_singly_linked_list_insert_tail(dsa_singly_linked_list *singly_linked_list, int value);
int dsa_singly_linked_list_remove_tail(dsa_singly_linked_list *singly_linked_list);

void dsa_singly_linked_list_insert(dsa_singly_linked_list *singly_linked_list, int index, int value);
int dsa_singly_linked_list_remove(dsa_singly_linked_list *singly_linked_list, int index);

void dsa_singly_linked_list_print(dsa_singly_linked_list *singly_linked_list);
int dsa_singly_linked_list_peek_head(dsa_singly_linked_list *singly_linked_list);
int dsa_singly_linked_list_peek_tail(dsa_singly_linked_list *singly_linked_list);

#endif // !DSA_SINGLY_LINKED_LIST_H 
