#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct NodeSLL {
	int value;
	struct NodeSLL *next;
} NodeSLL;

typedef struct {
	NodeSLL *head;
	NodeSLL *tail;
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
