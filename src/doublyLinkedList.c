#include "doublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DoublyLinkedList *doublyLinkedList() {
	DoublyLinkedList *doublyLinkedList = (DoublyLinkedList *) malloc(sizeof(DoublyLinkedList));
	doublyLinkedList->head = NULL;
	doublyLinkedList->tail = NULL;
	return doublyLinkedList;
}

Node *node(int value, Node *prev, Node *next) {
	Node *node = (Node *) malloc(sizeof(Node));
	node->value = value;
	node->prev = prev;
	node->next = next;
	return node;
}

void pushHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value) {
	if (doublyLinkedList->head == NULL) {
		Node *n = node(value, NULL, NULL);
		doublyLinkedList->head = n;
		doublyLinkedList->tail = n;
		return;
	}

	Node *n = node(value, NULL, doublyLinkedList->head);
	doublyLinkedList->head->prev = n;
	doublyLinkedList->head = n;
}

void pushTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value) {
	if (doublyLinkedList->head == NULL) {
		Node *n = node(value, NULL, NULL);
		doublyLinkedList->head = n;
		doublyLinkedList->tail = n;
		return;
	}

	Node *n = node(value, doublyLinkedList->tail, NULL);
	doublyLinkedList->tail->next = n;
	doublyLinkedList->tail = n;
}

void pushPositionDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int position, int value) {
	if (doublyLinkedList->head == NULL) {
		Node *n = node(value, NULL, NULL);
		doublyLinkedList->head = n;
		doublyLinkedList->tail = n;
		return;
	}

	if (position == 0) {
		Node *n = node(value, NULL, doublyLinkedList->head);
		doublyLinkedList->head->prev = n;
		doublyLinkedList->head = n;
	}

	Node *current = doublyLinkedList->head;
	int index = 0;
	while (current != NULL && index < position - 1) {
		current = current->next;
		index++;
	}

	if (current->next == NULL) {
		Node *n = node(value, current, NULL);
		doublyLinkedList->tail->next = n;
		doublyLinkedList->tail = n;
	}

	Node *n = node(value, current, current->next);
	current->next->prev = n;
	current->next = n;

	if (n->next == NULL) {
		doublyLinkedList->tail = n;
	}
}

int popHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList) {
	if (doublyLinkedList->head == NULL) return -1;

	if (doublyLinkedList->head->next == NULL) {
		int value = doublyLinkedList->head->value;
		free(doublyLinkedList->head);
		doublyLinkedList->head = NULL;
		doublyLinkedList->tail = NULL;
		return value;
	}

	Node *n = doublyLinkedList->head;
	int value = n->value;
	doublyLinkedList->head = n->next;
	free(n);

	return value;
}

int popTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList) {
	if (doublyLinkedList->head == NULL) return -1;

	if (doublyLinkedList->head->next == NULL) {
		int value = doublyLinkedList->head->value;
		free(doublyLinkedList->head);
		doublyLinkedList->head = NULL;
		doublyLinkedList->tail = NULL;
		return value;
	}

	Node *n = doublyLinkedList->tail;
	int value = n->value;
	doublyLinkedList->tail = n->prev;
	free(n);
	doublyLinkedList->tail->next = NULL;
	
	return value;
}

int popPositionDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int position) {
	if (doublyLinkedList->head == NULL) return -1;

	if (position == 0) {
		Node *n = doublyLinkedList->head;
		int value = n->value;
		doublyLinkedList->head = n->next;
		free(n);
		return value;
	}

	Node *current = doublyLinkedList->head;
	int index = 0;
	while (current != NULL && index < position) {
		current = current->next;
		index++;
	}

	if (current->next == NULL) {
		int value = current->next->value;
		doublyLinkedList->tail = current;
		free(current->next);
		return value;
	}

	int value = current->next->value;
	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);

	return value;
}

int peakHeadDoublyLinkList(DoublyLinkedList *doublyLinkedList) {
	return doublyLinkedList->head->value;
}

int peakTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList) {
	return doublyLinkedList->tail->value;
}

void printDoublyLinkedList(DoublyLinkedList *doublyLinkedList) {
	if (doublyLinkedList->head == NULL) {
		printf("{ }");
		return;
	}
	printf("{ ");
	Node *current = doublyLinkedList->head;
	while (current->next != NULL) {
		printf("%d, ", current->value);
		current = (Node *) current->next; 
	}
	printf("%d", current->value);
	printf(" }\n");

}

