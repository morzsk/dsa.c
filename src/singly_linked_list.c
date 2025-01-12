#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "singly_linked_list.h"

dsa_sll_node *dsa_sll_node_create(const void *value, dsa_sll_node *next) {
    dsa_sll_node *node = (dsa_sll_node *) malloc(sizeof(dsa_sll_node));
    if (!node) {
        fprintf(stderr, "Failed to allocate memory for a new node\n");
        return NULL;
    }

    node->value = (void *) value;
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

void dsa_singly_linked_list_insert_head(dsa_singly_linked_list *singly_linked_list, const void *value) {
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

void *dsa_singly_linked_list_remove_head(dsa_singly_linked_list *singly_linked_list) {
    if (singly_linked_list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    dsa_sll_node *old_head = singly_linked_list->head;
    void *value = old_head->value;

    singly_linked_list->head = old_head->next;
    if (singly_linked_list->head == NULL) {
        singly_linked_list->tail = NULL;
    }

    free(old_head);
    return value;
}

void dsa_singly_linked_list_insert_tail(dsa_singly_linked_list *singly_linked_list, const void *value) {
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

void *dsa_singly_linked_list_remove_tail(dsa_singly_linked_list *singly_linked_list) {
    if (singly_linked_list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    dsa_sll_node *current = singly_linked_list->head;
    dsa_sll_node *previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    void *value = current->value;

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

void dsa_singly_linked_list_insert(dsa_singly_linked_list *singly_linked_list, size_t index, const void *value) {
    if (index < 0) {
        fprintf(stderr, "Invalid index: %d\n", (int) index);
        return;
    }

    if (index == 0) {
        dsa_singly_linked_list_insert_head(singly_linked_list, value);
        return;
    }

    dsa_sll_node *current = singly_linked_list->head;
    size_t current_index = 0;
    while (current && current_index < index - 1) {
        current = current->next;
        current_index++;
    }

    if (!current) {
        fprintf(stderr, "Index %d is out of bounds\n", (int) index);
        return;
    }

    dsa_sll_node *new_node = dsa_sll_node_create(value, current->next);
    if (!new_node) {
        fprintf(stderr, "Failed to allocate memory for a new node\n");
        return;
    }

    current->next = new_node;
    if (!new_node->next) {
        singly_linked_list->tail = new_node;
    }
}

void *dsa_singly_linked_list_remove(dsa_singly_linked_list *singly_linked_list, size_t index) {
    if (index < 0) {
        fprintf(stderr, "Invalid index: %d\n", (int) index);
    	exit(EXIT_FAILURE);
	}

    if (index == 0) {
        return dsa_singly_linked_list_remove_head(singly_linked_list);
    }

    dsa_sll_node *current = singly_linked_list->head;
	size_t current_index = 0;
    while (current && current_index < index - 1) {
        current = current->next;
        current_index++;
    }

    if (!current || !current->next) {
        fprintf(stderr, "Index %d is out of bounds\n", (int) index);
    	exit(EXIT_FAILURE);
	}

    dsa_sll_node *node_to_remove = current->next;
    void *value = node_to_remove->value;
    current->next = node_to_remove->next;

    if (!current->next) {
        singly_linked_list->tail = current;
    }

    free(node_to_remove);
    return value;
}

void dsa_singly_linked_list_print(dsa_singly_linked_list *singly_linked_list, const char *type) {
    dsa_sll_node *current = singly_linked_list->head;

    printf("Singly Linked List: ");
    while (current) {
        void *element = current->value;

        if (strcmp(type, "int") == 0) {
            printf("%d", *(int *)element);
        } else if (strcmp(type, "float") == 0) {
            printf("%f", *(float *)element);
        } else if (strcmp(type, "double") == 0) {
            printf("%lf", *(double *)element);
        } else if (strcmp(type, "char") == 0) {
            printf("'%c'", *(char *)element);
        } else if (strcmp(type, "string") == 0) {
            printf("\"%s\"", (char *) element);
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

        current = current->next;

        if (current) {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}

void *dsa_singly_linked_list_peek_head(dsa_singly_linked_list *singly_linked_list) {
    if (singly_linked_list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    return singly_linked_list->head->value;
}

void *dsa_singly_linked_list_peek_tail(dsa_singly_linked_list *singly_linked_list) {
    if (singly_linked_list->tail == NULL) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    return singly_linked_list->tail->value;
}
