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
void addHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
void appendDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
void appendDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
void addHeadDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
void appendDoublyLinkedList(DoublyLinkedList *doublyLinkedList, int value);
int popDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void printDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

#endif // DOUBLY_LINKED_LIST_H
