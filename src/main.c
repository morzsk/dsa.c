
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"
#include "queue.h"

int main() {
    Stack *s = stack();
    Queue *q = queue();

    bool active = true;
    int choice, subChoice, value;

    while (active) {
        printf("\n=== Main Menu ===\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Deque Operations\n");
        printf("4. Exit\n");
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
                                //printf("Top element: %d\n", peek(s));
                            }
                            break;
                        case 3:
                            printf("Enter value to push: ");
                            scanf("%d", &value);
                            if (isStackFull(s)) {
                                printf("Stack is increasing capacity.\n");
                            }
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
                            if (isQueueFull(q)) {
                                printf("Queue is increasing capacity.\n");
                            }
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

            case 4:
                active = false;
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}
