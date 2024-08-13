#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int n = 50000;
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    srand(time(0)); // Seed the random number generator

    // Generate 50,000 random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Random numbers between 0 and 999999
    }

    // Sort the array using selection sort
    insertionSort(arr, n);

    // Print the first 10 elements to verify
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free the allocated memory
    return 0;
}