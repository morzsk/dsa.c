#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "singly_linked_list.h"

dsa_sll_node *dsa_sll_node_create(int value, dsa_sll_node *next) {
    dsa_sll_node *node = (dsa_sll_node *) malloc(sizeof(dsa_sll_node));
    if (!node) {
        fprintf(stderr, "Failed to allocate memory for a new node\n");
        return NULL;
    }

    node->value = value;
    node->next = next;
    return node;
}

void dsa_sll_node_destroy(dsa_sll_node *node) {
    if (!node) {
        fprintf(stderr, "Attempted to destroy a NULL node\n");
        return;
    }

    if (node->next) {
        free(node->next); 
        node->next = NULL;
    }
    free(node);
    node = NULL;
}

dsa_singly_linked_list *dsa_singly_linked_list_create() {
    dsa_singly_linked_list *singly_linked_list = (dsa_singly_linked_list *) malloc(sizeof(dsa_singly_linked_list));
    if (!singly_linked_list) {
        fprintf(stderr, "Failed to allocate memory for a singly linked list\n");
        return NULL;
    }

    singly_linked_list->head = NULL;
    singly_linked_list->tail = NULL;
    return singly_linked_list;
}

void dsa_singly_linked_list_destroy(dsa_singly_linked_list *singly_linked_list) {
    if (!singly_linked_list) {
        fprintf(stderr, "Attempted to destroy a NULL singly linked list\n");
        return;
    }

    dsa_sll_node *current = singly_linked_list->head;
    while (current) {
        dsa_sll_node *next = current->next;
        free(current);
        current = next;
    }

    free(singly_linked_list);
    singly_linked_list = NULL;
}
void dsa_singly_linked_list_insert_head(dsa_singly_linked_list *singly_linked_list, int value) {
    dsa_sll_node *new_node = dsa_sll_node_create(value, singly_linked_list->head);
    if (!new_node) {
        fprintf(stderr, "Failed to create a new node\n");
        return;
    }
    singly_linked_list->head = new_node;

    if (singly_linked_list->tail == NULL) {
        singly_linked_list->tail = new_node;
    }
}

int dsa_singly_linked_list_remove_head(dsa_singly_linked_list *singly_linked_list) {
    if (singly_linked_list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        return -1; // Indicate failure
    }

    dsa_sll_node *old_head = singly_linked_list->head;
    int value = old_head->value;

    singly_linked_list->head = old_head->next;
    if (singly_linked_list->head == NULL) {
        singly_linked_list->tail = NULL;
    }

    free(old_head);
    return value;
}

void dsa_singly_linked_list_insert_tail(dsa_singly_linked_list *singly_linked_list, int value) {
    dsa_sll_node *new_node = dsa_sll_node_create(value, NULL);
    if (!new_node) {
        fprintf(stderr, "Failed to create a new node\n");
        return;
    }

    if (singly_linked_list->tail) {
        singly_linked_list->tail->next = new_node;
    }
    singly_linked_list->tail = new_node;

    if (singly_linked_list->head == NULL) {
        singly_linked_list->head = new_node;
    }
}

int dsa_singly_linked_list_remove_tail(dsa_singly_linked_list *singly_linked_list) {
    if (singly_linked_list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        return -1; // Indicate failure
    }

    dsa_sll_node *current = singly_linked_list->head;
    dsa_sll_node *previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    int value = current->value;

    if (previous) {
        previous->next = NULL;
        singly_linked_list->tail = previous;
    } else {
        singly_linked_list->head = NULL;
        singly_linked_list->tail = NULL;
    }

    free(current);
    return value;
}

void dsa_singly_linked_list_insert(dsa_singly_linked_list *singly_linked_list, int index, int value) {
    if (index < 0) {
        fprintf(stderr, "Invalid index: %d\n", index);
        return;
    }

    // Inserting at the head
    if (index == 0) {
        dsa_singly_linked_list_insert_head(singly_linked_list, value);
        return;
    }

    dsa_sll_node *current = singly_linked_list->head;
    int current_index = 0;

    // Traverse to the node before the target index
    while (current && current_index < index - 1) {
        current = current->next;
        current_index++;
    }

    if (!current) {
        fprintf(stderr, "Index %d is out of bounds\n", index);
        return;
    }

    // Create a new node and insert it
    dsa_sll_node *new_node = dsa_sll_node_create(value, current->next);
    if (!new_node) {
        fprintf(stderr, "Failed to allocate memory for a new node\n");
        return;
    }

    current->next = new_node;

    // Update tail if inserted at the end
    if (!new_node->next) {
        singly_linked_list->tail = new_node;
    }
}

int dsa_singly_linked_list_remove(dsa_singly_linked_list *singly_linked_list, int index) {
    if (index < 0) {
        fprintf(stderr, "Invalid index: %d\n", index);
        return -1; // Indicate failure
    }

    // Removing from the head
    if (index == 0) {
        return dsa_singly_linked_list_remove_head(singly_linked_list);
    }

    dsa_sll_node *current = singly_linked_list->head;
    int current_index = 0;

    // Traverse to the node before the target index
    while (current && current_index < index - 1) {
        current = current->next;
        current_index++;
    }

    if (!current || !current->next) {
        fprintf(stderr, "Index %d is out of bounds\n", index);
        return -1; // Indicate failure
    }

    // Remove the node
    dsa_sll_node *node_to_remove = current->next;
    int value = node_to_remove->value;
    current->next = node_to_remove->next;

    // Update tail if removed the last node
    if (!current->next) {
        singly_linked_list->tail = current;
    }

    free(node_to_remove);
    return value;
}

void dsa_singly_linked_list_print(dsa_singly_linked_list *singly_linked_list) {
    dsa_sll_node *current = singly_linked_list->head;

    printf("Singly Linked List: ");
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int dsa_singly_linked_list_peek_head(dsa_singly_linked_list *singly_linked_list) {
    if (singly_linked_list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        return -1; // Indicate failure
    }
    return singly_linked_list->head->value;
}

int dsa_singly_linked_list_peek_tail(dsa_singly_linked_list *singly_linked_list) {
    if (singly_linked_list->tail == NULL) {
        fprintf(stderr, "List is empty\n");
        return -1; // Indicate failure
    }
    return singly_linked_list->tail->value;
}
