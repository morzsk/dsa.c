#ifndef DSA_DOUBLY_LINKED_LIST_H
#define DSA_DOUBLY_LINKED_LIST_H

typedef struct dsa_dll_node {
    int value;
    struct dsa_dll_node *next;
    struct dsa_dll_node *prev;
} dsa_dll_node;

typedef struct {
    dsa_dll_node *head;
    dsa_dll_node *tail;
} dsa_doubly_linked_list;

dsa_doubly_linked_list *dsa_doubly_linked_list_create();
void dsa_doubly_linked_list_destroy(dsa_doubly_linked_list *doubly_linked_list);

dsa_dll_node *dsa_dll_node_create(int value, dsa_dll_node *next, dsa_dll_node *prev);
void dsa_dll_node_destroy(dsa_dll_node *node);

void dsa_doubly_linked_list_insert_head(dsa_doubly_linked_list *doubly_linked_list, int value);
int dsa_doubly_linked_list_remove_head(dsa_doubly_linked_list *doubly_linked_list);

void dsa_doubly_linked_list_insert_tail(dsa_doubly_linked_list *doubly_linked_list, int value);
int dsa_doubly_linked_list_remove_tail(dsa_doubly_linked_list *doubly_linked_list);

void dsa_doubly_linked_list_insert(dsa_doubly_linked_list *doubly_linked_list, int index, int value);
int dsa_doubly_linked_list_remove(dsa_doubly_linked_list *doubly_linked_list, int index);

void dsa_doubly_linked_list_print_forward(dsa_doubly_linked_list *doubly_linked_list);
void dsa_doubly_linked_list_print_backward(dsa_doubly_linked_list *doubly_linked_list);
int dsa_doubly_linked_list_peek_head(dsa_doubly_linked_list *doubly_linked_list);
int dsa_doubly_linked_list_peek_tail(dsa_doubly_linked_list *doubly_linked_list);

#endif // !DSA_DOUBLY_LINKED_LIST_H
