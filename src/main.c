#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "dynamic_array.h"

int main() {
    dsa_dynamic_array *da = dsa_dynamic_array_create(10);

    bool active = true;
    int choice, index, value;

    while (active) {
        printf("\n=== Dynamic Array Menu ===\n");
        printf("1. Print Dynamic Array\n");
        printf("2. Insert Value\n");
        printf("3. Remove Value\n");
        printf("4. Get Value\n");
        printf("5. Set Value\n");
        printf("6. Check if Full\n");
        printf("7. Check if Empty\n");
        printf("8. Exit\n");
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
                active = false;
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    dsa_dynamic_array_destroy(da);
    return EXIT_SUCCESS;
}
