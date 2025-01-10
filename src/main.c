#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "dynamic_array.h"
#include "dynamic_deque.h"
#include "singly_linked_list.h"
#include "doubly_linked_list.h"

int main() {
	dsa_dynamic_array *da = dsa_dynamic_array_create(10);
	dsa_dynamic_deque *dd = dsa_dynamic_deque_create(10);
	dsa_singly_linked_list *sll = dsa_singly_linked_list_create();
	dsa_doubly_linked_list *dll = dsa_doubly_linked_list_create();

	bool active = true;
	int choice, index, value;

	while (active) {
		printf("\n=== Main Menu ===\n");
		printf("1. Dynamic Array Operations\n");
		printf("2. Dynamic Deque Operations\n");
		printf("3. Singly Linked List Operations\n");
		printf("4. Doubly Linked List Operations\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1: {
				bool arrayActive = true;
				while (arrayActive) {
					printf("\n=== Dynamic Array Menu ===\n");
					printf("1. Print Dynamic Array\n");
					printf("2. Insert Value\n");
					printf("3. Remove Value\n");
					printf("4. Get Value\n");
					printf("5. Set Value\n");
					printf("6. Check if Full\n");
					printf("7. Check if Empty\n");
					printf("8. Back to Main Menu\n");
					printf("Enter your choice: ");
					scanf("%d", &choice);

					switch (choice) {
						case 1:
							dsa_dynamic_array_print(da);
							break;

						case 2:
							printf("Enter index to insert at: ");
							scanf("%d", &index);
							printf("Enter value to insert: ");
							scanf("%d", &value);
							dsa_dynamic_array_insert(da, index, value);
							printf("Value %d inserted at index %d.\n", value, index);
							break;

						case 3:
							printf("Enter index to remove from: ");
							scanf("%d", &index);
							int removed_value = dsa_dynamic_array_remove(da, index);
							if (removed_value) {
								printf("Removed value: %d\n", removed_value);
							} else {
								printf("Invalid index or array is empty.\n");
							}
							break;

						case 4:
							printf("Enter index to get value from: ");
							scanf("%d", &index);
							value = dsa_dynamic_array_get(da, index);
							printf("Value at index %d: %d\n", index, value);
							break;

						case 5:
							printf("Enter index to set value at: ");
							scanf("%d", &index);
							printf("Enter value to set: ");
							scanf("%d", &value);
							dsa_dynamic_array_set(da, index, value);
							printf("Value at index %d set to %d.\n", index, value);
							break;

						case 6:
							if (dsa_dynamic_array_is_full(da)) {
								printf("Dynamic array is full.\n");
							} else {
								printf("Dynamic array is not full.\n");
							}
							break;

						case 7:
							if (dsa_dynamic_array_is_empty(da)) {
								printf("Dynamic array is empty.\n");
							} else {
								printf("Dynamic array is not empty.\n");
							}
							break;

						case 8:
							arrayActive = false;
							break;

						default:
							printf("Invalid choice. Please try again.\n");
					}
				}
				break;
			}

			case 2: {
				bool dequeActive = true;
				while (dequeActive) {
					printf("\n=== Dynamic Deque Menu ===\n");
					printf("1. Print Dynamic Deque\n");
					printf("2. Insert Front\n");
					printf("3. Remove Front\n");
					printf("4. Insert Back\n");
					printf("5. Remove Back\n");
					printf("6. Peek Front\n");
					printf("7. Peek Back\n");
					printf("8. Check if Full\n");
					printf("9. Check if Empty\n");
					printf("10. Back to Main Menu\n");
					printf("Enter your choice: ");
					scanf("%d", &choice);

					switch (choice) {
						case 1:
							dsa_dynamic_deque_print(dd);
							break;

						case 2:
							printf("Enter value to insert at front: ");
							scanf("%d", &value);
							dsa_dynamic_deque_insert_front(dd, value);
							printf("Value %d inserted at the front.\n", value);
							break;

						case 3:
							value = dsa_dynamic_deque_remove_front(dd);
							printf("Removed value from front: %d\n", value);
							break;

						case 4:
							printf("Enter value to insert at back: ");
							scanf("%d", &value);
							dsa_dynamic_deque_insert_back(dd, value);
							printf("Value %d inserted at the back.\n", value);
							break;

						case 5:
							value = dsa_dynamic_deque_remove_back(dd);
							printf("Removed value from back: %d\n", value);
							break;

						case 6:
							value = dsa_dynamic_deque_peek_front(dd);
							printf("Front value: %d\n", value);
							break;

						case 7:
							value = dsa_dynamic_deque_peek_back(dd);
							printf("Back value: %d\n", value);
							break;

						case 8:
							if (dsa_dynamic_deque_is_full(dd)) {
								printf("Dynamic deque is full.\n");
							} else {
								printf("Dynamic deque is not full.\n");
							}
							break;

						case 9:
							if (dsa_dynamic_deque_is_empty(dd)) {
								printf("Dynamic deque is empty.\n");
							} else {
								printf("Dynamic deque is not empty.\n");
							}
							break;

						case 10:
							dequeActive = false;
							break;

						default:
							printf("Invalid choice. Please try again.\n");
					}
				}
				break;
			}

			case 3: {
				bool listActive = true;
				while (listActive) {
					printf("\n=== Singly Linked List Menu ===\n");
					printf("1. Print Singly Linked List\n");
					printf("2. Insert at Head\n");
					printf("3. Remove from Head\n");
					printf("4. Insert at Tail\n");
					printf("5. Remove from Tail\n");
					printf("6. Insert at Position\n");
					printf("7. Remove from Position\n");
					printf("8. Peek Head\n");
					printf("9. Peek Tail\n");
					printf("10. Back to Main Menu\n");
					printf("Enter your choice: ");
					scanf("%d", &choice);

					switch (choice) {
						case 1:
							dsa_singly_linked_list_print(sll);
							break;

						case 2:
							printf("Enter value to insert at head: ");
							scanf("%d", &value);
							dsa_singly_linked_list_insert_head(sll, value);
							printf("Value %d inserted at head.\n", value);
							break;

						case 3:
							value = dsa_singly_linked_list_remove_head(sll);
							printf("Removed value from head: %d\n", value);
							break;

						case 4:
							printf("Enter value to insert at tail: "); 
							scanf("%d", &value);
							dsa_singly_linked_list_insert_tail(sll, value);
							printf("Value %d inserted at tail.\n", value);
							break;

						case 5:
							value = dsa_singly_linked_list_remove_tail(sll);
							printf("Removed value from tail: %d\n", value);
							break;

						case 6:
							printf("Enter position to insert at: ");
							scanf("%d", &index);
							printf("Enter value to insert: ");
							scanf("%d", &value);
							dsa_singly_linked_list_insert(sll, index, value);
							printf("Value %d inserted at position %d.\n", value, index);
							break;

						case 7:
							printf("Enter position to remove from: ");
							scanf("%d", &index);
							value = dsa_singly_linked_list_remove(sll, index);
							printf("Removed value from position %d: %d\n", index, value);
							break;

						case 8:
							value = dsa_singly_linked_list_peek_head(sll);
							printf("Head value: %d\n", value);
							break;

						case 9:
							value = dsa_singly_linked_list_peek_tail(sll);
							printf("Tail value: %d\n", value);
							break;

						case 10:
							listActive = false;
							break;

						default:
							printf("Invalid choice. Please try again.\n");
					}
				}
				break;
			}

			case 4: {
				bool dllActive = true;
				while (dllActive) {
					printf("\n=== Doubly Linked List Menu ===\n");
					printf("1. Print List Forward\n");
					printf("2. Print List Backward\n");
					printf("3. Insert at Head\n");
					printf("4. Remove from Head\n");
					printf("5. Insert at Tail\n");
					printf("6. Remove from Tail\n");
					printf("7. Insert at Position\n");
					printf("8. Remove from Position\n");
					printf("9. Peek Head\n");
					printf("10. Peek Tail\n");
					printf("11. Back to Main Menu\n");
					printf("Enter your choice: ");
					scanf("%d", &choice);

					switch (choice) {
						case 1:
							dsa_doubly_linked_list_print_forward(dll);
							break;

						case 2:
							dsa_doubly_linked_list_print_backward(dll);
							break;

						case 3:
							printf("Enter value to insert at head: ");
							scanf("%d", &value);
							dsa_doubly_linked_list_insert_head(dll, value);
							printf("Value %d inserted at head.\n", value);
							break;

						case 4:
							value = dsa_doubly_linked_list_remove_head(dll);
							printf("Removed value from head: %d\n", value);
							break;

						case 5:
							printf("Enter value to insert at tail: ");
							scanf("%d", &value);
							dsa_doubly_linked_list_insert_tail(dll, value);
							printf("Value %d inserted at tail.\n", value);
							break;

						case 6:
							value = dsa_doubly_linked_list_remove_tail(dll);
							printf("Removed value from tail: %d\n", value);
							break;

						case 7:
							printf("Enter position to insert at: ");
							scanf("%d", &index);
							printf("Enter value to insert: ");
							scanf("%d", &value);
							dsa_doubly_linked_list_insert(dll, index, value);
							printf("Value %d inserted at position %d.\n", value, index);
							break;

						case 8:
							printf("Enter position to remove from: ");
							scanf("%d", &index);
							value = dsa_doubly_linked_list_remove(dll, index);
							printf("Removed value from position %d: %d\n", index, value);
							break;

						case 9:
							value = dsa_doubly_linked_list_peek_head(dll);
							printf("Head value: %d\n", value);
							break;

						case 10:
							value = dsa_doubly_linked_list_peek_tail(dll);
							printf("Tail value: %d\n", value);
							break;

						case 11:
							dllActive = false;
							break;

						default:
							printf("Invalid choice. Please try again.\n");
					}
				}
				break;
			}
			case 5:
				active = false;
				printf("Exiting program.\n");
				break;

			default:
				printf("Invalid choice. Please try again.\n");
		}
	}

	dsa_dynamic_array_destroy(da);
	dsa_dynamic_deque_destroy(dd);
	dsa_singly_linked_list_destroy(sll);
	return EXIT_SUCCESS;
}
