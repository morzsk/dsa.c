#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	Node *tail;
} SinglyLinkedList;

SinglyLinkedList *singlyLinkedList();
void pushHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value);
void pushTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int value);
void pushPositionSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int position, int value);
int popHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
int popTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
int popPositionSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int position);
int peakHeadSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
int peakTailSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void printSinglyLinkedList(SinglyLinkedList *singlyLinkedList);

#endif // SINGLY_LINKED_LIST_H
