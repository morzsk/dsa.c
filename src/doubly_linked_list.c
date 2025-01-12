#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doubly_linked_list.h"

dsa_dll_node *dsa_dll_node_create(const void *value, dsa_dll_node *next, dsa_dll_node *prev) {
    dsa_dll_node *node = (dsa_dll_node *)malloc(sizeof(dsa_dll_node));
    if (!node) {
        fprintf(stderr, "Failed to allocate memory for a new node\n");
        return NULL;
    }

    node->value = (void *)value;
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
    dsa_doubly_linked_list *doubly_linked_list = (dsa_doubly_linked_list *)malloc(sizeof(dsa_doubly_linked_list));
    if (!doubly_linked_list) {
        fprintf(stderr, "Failed to allocate memory for a doubly linked list\n");
        return NULL;
    }

    doubly_linked_list->head = NULL;
    doubly_linked_list->tail = NULL;
    return doubly_linked_list;
}

void dsa_doubly_linked_list_destroy(dsa_doubly_linked_list *doubly_linked_list) {
    if (!doubly_linked_list) {
        fprintf(stderr, "Attempted to destroy a NULL doubly linked list\n");
        return;
    }

    dsa_dll_node *current = doubly_linked_list->head;
    while (current) {
        dsa_dll_node *next = current->next;
        dsa_dll_node_destroy(current);
        current = next;
    }

    free(doubly_linked_list);
}

void dsa_doubly_linked_list_insert_head(dsa_doubly_linked_list *doubly_linked_list, const void *value) {
    dsa_dll_node *new_node = dsa_dll_node_create(value, doubly_linked_list->head, NULL);
    if (!new_node) {
        fprintf(stderr, "Failed to create a new node\n");
        return;
    }

    if (doubly_linked_list->head) {
        doubly_linked_list->head->prev = new_node;
    }
    doubly_linked_list->head = new_node;

    if (!doubly_linked_list->tail) {
        doubly_linked_list->tail = new_node;
    }
}

void *dsa_doubly_linked_list_remove_head(dsa_doubly_linked_list *doubly_linked_list) {
    if (!doubly_linked_list->head) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    dsa_dll_node *old_head = doubly_linked_list->head;
    void *value = old_head->value;

    doubly_linked_list->head = old_head->next;
    if (doubly_linked_list->head) {
        doubly_linked_list->head->prev = NULL;
    } else {
        doubly_linked_list->tail = NULL;
    }

    dsa_dll_node_destroy(old_head);
    return value;
}

void dsa_doubly_linked_list_insert_tail(dsa_doubly_linked_list *doubly_linked_list, const void *value) {
    dsa_dll_node *new_node = dsa_dll_node_create(&value, NULL, doubly_linked_list->tail);
    if (!new_node) {
        fprintf(stderr, "Failed to create a new node\n");
        return;
    }

    if (doubly_linked_list->tail) {
        doubly_linked_list->tail->next = new_node;
    }
    doubly_linked_list->tail = new_node;

    if (!doubly_linked_list->head) {
        doubly_linked_list->head = new_node;
    }
}

void *dsa_doubly_linked_list_remove_tail(dsa_doubly_linked_list *doubly_linked_list) {
    if (!doubly_linked_list->tail) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    dsa_dll_node *old_tail = doubly_linked_list->tail;
    void *value = old_tail->value;

    doubly_linked_list->tail = old_tail->prev;
    if (doubly_linked_list->tail) {
        doubly_linked_list->tail->next = NULL;
    } else {
        doubly_linked_list->head = NULL;
    }

    dsa_dll_node_destroy(old_tail);
    return value;
}


void dsa_doubly_linked_list_print_forward(dsa_doubly_linked_list *doubly_linked_list, const char *type) {
    dsa_dll_node *current = doubly_linked_list->head;

    printf("Doubly Linked List (Forward): ");
    while (current) {
        void *value = current->value;

        if (strcmp(type, "int") == 0) {
            printf("%d", *(int *)value);
        } else if (strcmp(type, "float") == 0) {
            printf("%f", *(float *)value);
        } else if (strcmp(type, "double") == 0) {
            printf("%lf", *(double *)value);
        } else if (strcmp(type, "char") == 0) {
            printf("'%c'", *(char *)value);
        } else if (strcmp(type, "string") == 0) {
            printf("\"%s\"", *(char **)value);
        } else if (strcmp(type, "short") == 0) {
            printf("%d", *(short *)value);
        } else if (strcmp(type, "long") == 0) {
            printf("%ld", *(long *)value);
        } else if (strcmp(type, "long long") == 0) {
            printf("%lld", *(long long *)value);
        } else if (strcmp(type, "unsigned int") == 0) {
            printf("%u", *(unsigned int *)value);
        } else if (strcmp(type, "bool") == 0) {
            printf("%s", *(int *)value ? "true" : "false");
        } else if (strcmp(type, "size_t") == 0) {
            printf("%zu", *(size_t *)value);
        } else {
            printf("?");
        }

        current = current->next;

        if (current) {
            printf(" <-> ");
        }
    }
    printf(" <-> NULL\n");
}

void dsa_doubly_linked_list_print_backward(dsa_doubly_linked_list *doubly_linked_list, const char *type) {
    dsa_dll_node *current = doubly_linked_list->tail;

    printf("Doubly Linked List (Backward): ");
    while (current) {
        void *value = current->value;

        if (strcmp(type, "int") == 0) {
            printf("%d", *(int *)value);
        } else if (strcmp(type, "float") == 0) {
            printf("%f", *(float *)value);
        } else if (strcmp(type, "double") == 0) {
            printf("%lf", *(double *)value);
        } else if (strcmp(type, "char") == 0) {
            printf("'%c'", *(char *)value);
        } else if (strcmp(type, "string") == 0) {
            printf("\"%s\"", (char *)value);
        } else if (strcmp(type, "short") == 0) {
            printf("%d", *(short *)value);
        } else if (strcmp(type, "long") == 0) {
            printf("%ld", *(long *)value);
        } else if (strcmp(type, "long long") == 0) {
            printf("%lld", *(long long *)value);
        } else if (strcmp(type, "unsigned int") == 0) {
            printf("%u", *(unsigned int *)value);
        } else if (strcmp(type, "bool") == 0) {
            printf("%s", *(int *)value ? "true" : "false");
        } else if (strcmp(type, "size_t") == 0) {
            printf("%zu", *(size_t *)value);
        } else {
            printf("?");
        }

        current = current->prev;

        if (current) {
            printf(" <-> ");
        }
    }
    printf(" <-> NULL\n");
}

void *dsa_doubly_linked_list_peek_head(dsa_doubly_linked_list *doubly_linked_list) {
    if (!doubly_linked_list->head) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    return doubly_linked_list->head->value;
}

void *dsa_doubly_linked_list_peek_tail(dsa_doubly_linked_list *doubly_linked_list) {
    if (!doubly_linked_list->tail) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    return doubly_linked_list->tail->value;
}
