#include <stdio.h>
#include <stdbool.h>

// Function to sort the array using selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the element at index i
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Binary search function
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Key found
        }

        if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1; // Key not found
}

int main() {
    char choice;
    int array[20];
    int i = 0, key, index;

    printf("Enter values to be stored in the array (up to 20 values):\n");

    while (1) {
        if (i < 20) {
            printf("Enter New Value: ");
            scanf("%d", &array[i]);
            i++;
        } else {
            printf("Array is full. Exiting the loop.\n");
            break;
        }

        printf("Do you want to stop the loop? (y/n): ");
        scanf(" %c", &choice);  // Read user input (note the space before %c to handle newline)

        if (choice == 'y' || choice == 'Y') {
            printf("Exiting the loop.\n");
            break;  // Exit the loop
        } 
        else if (choice == 'n' || choice == 'N') {
            printf("Continuing the loop...\n");
        }
        else {
            printf("Invalid input! Please enter 'y' or 'n'.\n");
        }
    }

    // Sort the array using selection sort
    selectionSort(array, i);
    printf("Array has been sorted.\n");

    // Optional: Print the sorted array
    printf("Sorted values in the array are:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", array[j]);
    }
    printf("\n");

    // Search for a key using binary search
    printf("Do you want to search for a value in the array? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Enter the value to search: ");
        scanf("%d", &key);

        index = binarySearch(array, i, key);

        if (index != -1) {
            printf("Value %d found at index %d.\n", key, index);
        } else {
            printf("Value %d not found in the array.\n", key);
        }
    } else {
        printf("Skipping search.\n");
    }

    return 0;
}
