#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"
#include "queue.h"
#include "deque.h"
#include "singlyLinkedList.h"

int main() {
    Stack *s = stack();
    Queue *q = queue();
    Deque *d = deque();
    SinglyLinkedList *sll = singlyLinkedList(); // Create a new singly linked list

    bool active = true;
    int choice, subChoice, value, position;

    while (active) {
        printf("\n=== Main Menu ===\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Deque Operations\n");
        printf("4. Singly Linked List Operations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // Stack Operations
                bool stackActive = true;
                while (stackActive) {
                    printf("\n=== Stack Menu ===\n");
                    printf("1. Print Stack\n");
                    printf("2. Peek Stack\n");
                    printf("3. Push to Stack\n");
                    printf("4. Pop from Stack\n");
                    printf("5. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            printStack(s);
                            break;
                        case 2:
                            if (isStackEmpty(s)) {
                                printf("Stack is empty.\n");
                            } else {
                                printf("Top element: %d\n", peek(s));
                            }
                            break;
                        case 3:
                            printf("Enter value to push: ");
                            scanf("%d", &value);
                            push(s, value);
                            printf("%d pushed to stack.\n", value);
                            break;
                        case 4:
                            if (isStackEmpty(s)) {
                                printf("Stack is empty. Cannot pop.\n");
                            } else {
                                value = pop(s);
                                printf("Popped value: %d\n", value);
                            }
                            break;
                        case 5:
                            stackActive = false;
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
                break;
            }

            case 2: { // Queue Operations
                bool queueActive = true;
                while (queueActive) {
                    printf("\n=== Queue Menu ===\n");
                    printf("1. Print Queue\n");
                    printf("2. Enqueue\n");
                    printf("3. Dequeue\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            printQueue(q);
                            break;
                        case 2:
                            printf("Enter value to enqueue: ");
                            scanf("%d", &value);
                            enqueue(q, value);
                            printf("%d enqueued to queue.\n", value);
                            break;
                        case 3:
                            if (isQueueEmpty(q)) {
                                printf("Queue is empty. Cannot dequeue.\n");
                            } else {
                                value = dequeue(q);
                                printf("Dequeued value: %d\n", value);
                            }
                            break;
                        case 4:
                            queueActive = false;
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
                break;
            }

            case 3: { // Deque Operations
                bool dequeActive = true;
                while (dequeActive) {
                    printf("\n=== Deque Menu ===\n");
                    printf("1. Print Deque\n");
                    printf("2. Push Front\n");
                    printf("3. Push Back\n");
                    printf("4. Pop Front\n");
                    printf("5. Pop Back\n");
                    printf("6. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            printDeque(d);
                            break;
                        case 2:
                            printf("Enter value to push front: ");
                            scanf("%d", &value);
                            pushFront(d, value);
                            printf("%d pushed to front of deque.\n", value);
                            break;
                        case 3:
                            printf("Enter value to push back: ");
                            scanf("%d", &value);
                            pushBack(d, value);
                            printf("%d pushed to back of deque.\n", value);
                            break;
                        case 4:
                            value = popFront(d);
                            if (value == -1) {
                                printf("Deque is empty. Cannot pop front.\n");
                            } else {
                                printf("Popped front value: %d\n", value);
                            }
                            break;
                        case 5:
                            value = popBack(d);
                            if (value == -1) {
                                printf("Deque is empty. Cannot pop back.\n");
                            } else {
                                printf("Popped back value: %d\n", value);
                            }
                            break;
                        case 6:
                            dequeActive = false;
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
                break;
            }
            case 4: { // Singly Linked List Operations
                bool sllActive = true;
                while (sllActive) {
                    printf("\n=== Singly Linked List Menu ===\n");
                    printf("1. Print Singly Linked List\n");
                    printf("2. Push Head\n");
                    printf("3. Push Tail\n");
                    printf("4. Push at Position\n");
                    printf("5. Pop Head\n");
                    printf("6. Pop Tail\n");
                    printf("7. Pop at Position\n");
					printf("8. Peak Head\n");
					printf("9. Peak Tail\n");
                    printf("10. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1: // Print List
                            printSinglyLinkedList(sll);
                            break;
                        case 2: // Push Head
                            printf("Enter value to push at head: ");
                            scanf("%d", &value);
                            pushHeadSinglyLinkedList(sll, value);
                            printf("%d added at the head.\n", value);
                            break;
                        case 3: // Push Tail
                            printf("Enter value to push at tail: ");
                            scanf("%d", &value);
                            pushTailSinglyLinkedList(sll, value);
                            printf("%d added at the tail.\n", value);
                            break;
                        case 4: // Push at Position
                            printf("Enter position to insert at: ");
                            scanf("%d", &position);
                            printf("Enter value to insert: ");
                            scanf("%d", &value);
                            pushPositionSinglyLinkedList(sll, position, value);
                            printf("%d added at position %d.\n", value, position);
                            break;
                        case 5: // Pop Head
                            if (sll->head == NULL) {
                                printf("List is empty. Cannot pop.\n");
                            } else {
                                value = popHeadSinglyLinkedList(sll);
                                printf("Popped value from head: %d\n", value);
                            }
                            break;
                        case 6: // Pop Tail
                            if (sll->head == NULL) {
                                printf("List is empty. Cannot pop.\n");
                            } else {
                                value = popTailSinglyLinkedList(sll);
                                printf("Popped value from tail: %d\n", value);
                            }
                            break;
                        case 7: // Pop at Position
                            if (sll->head == NULL) {
                                printf("List is empty. Cannot pop.\n");
                            } else {
                                printf("Enter position to pop from: ");
                                scanf("%d", &position);
                                value = popPositionSinglyLinkedList(sll, position);
                                printf("Popped value from position %d: %d\n", position, value);
                            }
                            break;
						case 8:
							if (sll->head == NULL) {
								printf("List is empty. Cannot peak.\n");
							} else {
								value = peakHeadSinglyLinkedList(sll);
								printf("Peaked value from head: %d\n", value);
							}
							break;
						case 9:
							if (sll->tail == NULL) {
								printf("Tail does not exist. Cannot peak.\n");
							} else {
								value = peakTailSinglyLinkedList(sll);
								printf("Peaked value from tail: %d\n", value);
							}
							break;
                        case 10: // Back to Main Menu
                            sllActive = false;
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
                break;
            }

            case 5: // Exit Program
                active = false;
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}
