#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct NodeDLL {
	int value;
	struct NodeDLL *next;
	struct NodeDLL *prev;
} NodeDLL;

typedef struct {
	NodeDLL *head;
	NodeDLL *tail;
} DoublyLinkedList;

DoublyLinkedList *doublyLinkedList();
void pushHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
void pushTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
void pushPositionDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int position, int value);
int popHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
int popTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
int popPositionDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int position);
int peakHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
int peakTailDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void printDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

#endif // DOUBLY_LINKED_LIST_H
