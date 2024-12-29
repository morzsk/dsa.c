#include "singlyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SinglyLinkedList *singlyLinkedList() {
	SinglyLinkedList *singlyLinkedList = (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
	singlyLinkedList->head = NULL;
	singlyLinkedList->tail = NULL;
	return singlyLinkedList;
}

Node *node(int value, Node *next) {
	Node *node = (Node *) malloc(sizeof(Node));
	node->value = value;
	node->next = next;
	return node;
}

void pushHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value) {
	if (singlyLinkedList->head == NULL) {
		Node *n = node(value, NULL);
		singlyLinkedList->head = n;
		singlyLinkedList->tail = n;
		return;
	}

	Node *n = node(value, singlyLinkedList->head);
	singlyLinkedList->head = n;
}

void pushTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value) {
	if (singlyLinkedList->head == NULL) {
		Node *n = node(value, NULL);
		singlyLinkedList->head = n;
		singlyLinkedList->tail = n;
		return;
	}

	Node *n = node(value, NULL);
	singlyLinkedList->tail->next = n; 
	singlyLinkedList->tail = n;
}

void pushPositionSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int position, int value) {
	if (singlyLinkedList->head == NULL) {
		Node *n = node(value, NULL);
		singlyLinkedList->head = n;
		singlyLinkedList->tail = n;
		return;
	}

	if (position == 0) {
		Node *n = node(value, singlyLinkedList->head);
		singlyLinkedList->head = n;
		return;
	}
	
	Node *current = singlyLinkedList->head;
	int index = 0;
	while (current != NULL && index < position - 1) {
		current = current->next;
		index++;
	}

	if (current->next == NULL) {
		Node *n = node(value, NULL);
		current->next = n;
		singlyLinkedList->tail = n;
		return;
	}

	Node *n = node(value, current->next);
	current->next = n;

	// New node becomes tail
    if (n->next == NULL) {
        singlyLinkedList->tail = n;
    }
}

int popHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList) {
	if (singlyLinkedList->head == NULL) return -1;

	if (singlyLinkedList->head->next == NULL) {
		int value = singlyLinkedList->head->value;
		free(singlyLinkedList->head);
		singlyLinkedList->head = NULL;
		singlyLinkedList->tail = NULL;
		return value;
	}
	
	Node *current = singlyLinkedList->head;
	int value = current->value;
	singlyLinkedList->head = current->next;
	free(current);
	
	return value;
}

int popTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList) {
	if (singlyLinkedList->head == NULL) return -1;

	if (singlyLinkedList->head->next == NULL) {
		int value = singlyLinkedList->head->value;
		free(singlyLinkedList->head);
		singlyLinkedList->head = NULL;
		singlyLinkedList->tail = NULL;
		return value;
	}

	Node *current = singlyLinkedList->head;
	while (current->next->next != NULL) {
		current = current->next;	
	}
	
	int value = current->next->value;
	singlyLinkedList->tail = current;
	free(current->next);
	current->next = NULL;

	return value;
}

int popPositionSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int position) {
	if (singlyLinkedList->head == NULL) return -1;

	if (position == 0) {	
		Node *n = singlyLinkedList->head;
		int value = n->value;
		singlyLinkedList->head = n->next;
		free(n);
		return value;
	}
	
	Node *current = singlyLinkedList->head;
	int index = 0;
	while (current != NULL && index < position - 1) {
		current = current->next;
		index++;
	}

	if (current->next == NULL) {	
		int value = current->next->value;
		singlyLinkedList->tail = current;
		free(current->next);
		return value;
	}
	
	int value = current->next->value;
	current->next = current->next->next;
	// todo: free popped val
	//free(current->next);
	
	return value;
}

int peakHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList) {
	return singlyLinkedList->head->value;
}

int peakTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList) {
	return singlyLinkedList->tail->value;
}

void printSinglyLinkedList(SinglyLinkedList *singlyLinkedList) {
	if (singlyLinkedList->head == NULL) {
		printf("{ }");
		return;
	}
	printf("{ ");
	Node *current = singlyLinkedList->head;
	while (current->next != NULL) {
		printf("%d, ", current->value);
		current = (Node *) current->next; 
	}
	printf("%d", current->value);
	printf(" }\n");
}
