#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Step 1: Find the minimum element in the unsorted part of the array
        int minIndex = i;
        printf("Step %d: Find the minimum element in the unsorted part.\n", i + 1);
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Step 2: Swap the minimum element with the element at position i
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        // Print the array after each pass
        printf("Array after step %d: ", i + 1);
        for (int k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    // Sample array
    int array[] = {64, 25, 12, 22, 11};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    // Call the selection sort function
    selectionSort(array, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
