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
		return;
	}

	Node *n = node(value, singlyLinkedList->head);
	singlyLinkedList->head = n;
}

void pushTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value) {
	if (singlyLinkedList->head == NULL) {
		Node *n = node(value, NULL);
		singlyLinkedList->head = n;
		return;
	}

	Node *current = singlyLinkedList->head;
	while (current->next != NULL) {
		current = current->next;
	}

	Node *n = node(value, NULL);
	current->next = n;
}

void pushPositionSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int position, int value) {
	if (singlyLinkedList->head == NULL) {
		Node *n = node(value, NULL);
		singlyLinkedList->head = n;
		return;
	}
	
	Node *current = singlyLinkedList->head;
	for (int i = 0; i >= position; i++) {
		current = current->next;
	}

	if (current == NULL) {
		printf("Error out of bounds");
		return;
	}

	Node *n = node(value, current->next);
	current->next = n;
}

int popHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList) {
	if (singlyLinkedList->head == NULL) return -1;

	if (singlyLinkedList->head->next == NULL) {
		int value = singlyLinkedList->head->value;
		free(singlyLinkedList->head);
		singlyLinkedList->head = NULL;
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
		return value;
	}

	Node *current = singlyLinkedList->head;
	while (current->next->next != NULL) {
		current = current->next;	
	}
	
	int value = current->next->value;
	free(current->next);
	current->next = NULL;

	return value;
}

int popPositionSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int position) {
	return -1;
}

/*void appendSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value) { */
/*	if (singlyLinkedList->head == NULL) {*/
/*		addHeadSinglyLinkedList(singlyLinkedList, value);*/
/*		return;*/
/*	}*/
/**/
/*	Node *current = singlyLinkedList->head;*/
/*	while (current->next != NULL) {*/
/*		current = (Node *) current->next;*/
/*	}*/
/**/
/*	Node *node = (Node *) malloc(sizeof(Node));*/
/*	node->next =  NULL;*/
/*	node->value = value;*/
/*	current->next = (struct Node *) node;*/
/*}*/
/**/
/*void addHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value) {*/
/*	Node *node = (Node *) malloc(sizeof(Node));*/
/*	node->value = value;*/
/*	node->next = NULL;*/
/*	singlyLinkedList->head = node;*/
/*}*/
/**/
/*int popSinglyLinkedList(SinglyLinkedList *singlyLinkedList) {*/
/*	if (singlyLinkedList->head == NULL) return -1;*/
/**/
/*	if (singlyLinkedList->head->next == NULL) {*/
/*		int value = singlyLinkedList->head->value;*/
/*	    free(singlyLinkedList->head);*/
/*		singlyLinkedList->head = NULL;*/
/*		return value;	*/
/*	}*/
/**/
/*	Node *current = singlyLinkedList->head;*/
/*	while (current->next->next != NULL) {*/
/*		current = (Node *) current->next;*/
/*	}*/
/**/
/*    int value = current->next->value;*/
/*    free(current->next);*/
/*    current->next = NULL;*/
/**/
/*    return value;*/
/*}*/

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
