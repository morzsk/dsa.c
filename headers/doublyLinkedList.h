#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
	int value;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct {
	Node *head;
	Node *tail;
} DoublyLinkedList;

DoublyLinkedList *doublyLinkedList();
void pushHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
void pushTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
void pushPositionDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int position, int value);
int popHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
int popTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
int popPositionDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int position);
int peakHeadDoublyLinkList(DoublyLinkedList *doublyLinkedList);
int peakTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void printDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

#endif // DOUBLY_LINKED_LIST_H
