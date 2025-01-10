#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doubly_linked_list.h"

dsa_dll_node *dsa_dll_node_create(int value, dsa_dll_node *next, dsa_dll_node *prev) {
    dsa_dll_node *node = (dsa_dll_node *) malloc(sizeof(dsa_dll_node));
    if (!node) {
        fprintf(stderr, "Failed to allocate memory for a new node\n");
        return NULL;
    }

    node->value = value;
    node->next = next;
    node->prev = prev;
    return node;
}

void dsa_dll_node_destroy(dsa_dll_node *node) {
    if (!node) {
        fprintf(stderr, "Attempted to destroy a NULL node\n");
        return;
    }

    free(node);
}

dsa_doubly_linked_list *dsa_doubly_linked_list_create() {
    dsa_doubly_linked_list *list = (dsa_doubly_linked_list *) malloc(sizeof(dsa_doubly_linked_list));
    if (!list) {
        fprintf(stderr, "Failed to allocate memory for a doubly linked list\n");
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    return list;
}

void dsa_doubly_linked_list_destroy(dsa_doubly_linked_list *list) {
    if (!list) {
        fprintf(stderr, "Attempted to destroy a NULL doubly linked list\n");
        return;
    }

    dsa_dll_node *current = list->head;
    while (current) {
        dsa_dll_node *next = current->next;
        dsa_dll_node_destroy(current);
        current = next;
    }

    free(list);
}

void dsa_doubly_linked_list_insert_head(dsa_doubly_linked_list *list, int value) {
    dsa_dll_node *new_node = dsa_dll_node_create(value, list->head, NULL);
    if (!new_node) {
        fprintf(stderr, "Failed to create a new node\n");
        return;
    }

    if (list->head) {
        list->head->prev = new_node;
    }
    list->head = new_node;

    if (!list->tail) {
        list->tail = new_node;
    }
}

int dsa_doubly_linked_list_remove_head(dsa_doubly_linked_list *list) {
    if (!list->head) {
        fprintf(stderr, "List is empty\n");
        return -1;
    }

    dsa_dll_node *old_head = list->head;
    int value = old_head->value;

    list->head = old_head->next;
    if (list->head) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    dsa_dll_node_destroy(old_head);
    return value;
}

void dsa_doubly_linked_list_insert_tail(dsa_doubly_linked_list *list, int value) {
    dsa_dll_node *new_node = dsa_dll_node_create(value, NULL, list->tail);
    if (!new_node) {
        fprintf(stderr, "Failed to create a new node\n");
        return;
    }

    if (list->tail) {
        list->tail->next = new_node;
    }
    list->tail = new_node;

    if (!list->head) {
        list->head = new_node;
    }
}

int dsa_doubly_linked_list_remove_tail(dsa_doubly_linked_list *list) {
    if (!list->tail) {
        fprintf(stderr, "List is empty\n");
        return -1;
    }

    dsa_dll_node *old_tail = list->tail;
    int value = old_tail->value;

    list->tail = old_tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    dsa_dll_node_destroy(old_tail);
    return value;
}

void dsa_doubly_linked_list_insert(dsa_doubly_linked_list *list, int index, int value) {
    if (index < 0) {
        fprintf(stderr, "Invalid index: %d\n", index);
        return;
    }

    if (index == 0) {
        dsa_doubly_linked_list_insert_head(list, value);
        return;
    }

    dsa_dll_node *current = list->head;
    int current_index = 0;

    while (current && current_index < index - 1) {
        current = current->next;
        current_index++;
    }

    if (!current) {
        fprintf(stderr, "Index %d is out of bounds\n", index);
        return;
    }

    dsa_dll_node *new_node = dsa_dll_node_create(value, current->next, current);
    if (!new_node) {
        fprintf(stderr, "Failed to create a new node\n");
        return;
    }

    if (current->next) {
        current->next->prev = new_node;
    }
    current->next = new_node;

    if (!new_node->next) {
        list->tail = new_node;
    }
}

int dsa_doubly_linked_list_remove(dsa_doubly_linked_list *list, int index) {
    if (index < 0) {
        fprintf(stderr, "Invalid index: %d\n", index);
        return -1;
    }

    if (index == 0) {
        return dsa_doubly_linked_list_remove_head(list);
    }

    dsa_dll_node *current = list->head;
    int current_index = 0;

    while (current && current_index < index) {
        current = current->next;
        current_index++;
    }

    if (!current) {
        fprintf(stderr, "Index %d is out of bounds\n", index);
        return -1;
    }

    int value = current->value;

    if (current->prev) {
        current->prev->next = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }

    if (current == list->head) {
        list->head = current->next;
    }

    if (current == list->tail) {
        list->tail = current->prev;
    }

    dsa_dll_node_destroy(current);
    return value;
}

void dsa_doubly_linked_list_print_forward(dsa_doubly_linked_list *list) {
    dsa_dll_node *current = list->head;

    printf("Doubly Linked List (Forward): ");
    while (current) {
        printf("%d <-> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void dsa_doubly_linked_list_print_backward(dsa_doubly_linked_list *list) {
    dsa_dll_node *current = list->tail;

    printf("Doubly Linked List (Backward): ");
    while (current) {
        printf("%d <-> ", current->value);
        current = current->prev;
    }
    printf("NULL\n");
}

int dsa_doubly_linked_list_peek_head(dsa_doubly_linked_list *list) {
    if (!list->head) {
        fprintf(stderr, "List is empty\n");
        return -1;
    }
    return list->head->value;
}

int dsa_doubly_linked_list_peek_tail(dsa_doubly_linked_list *list) {
    if (!list->tail) {
        fprintf(stderr, "List is empty\n");
        return -1;
    }
    return list->tail->value;
}
