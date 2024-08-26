#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
void merge(int* left, int left_size, int* right, int right_size, int* result) {
    int i = 0, j = 0, k = 0;

    // Merge the two arrays while both have elements left
    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }

    // Copy any remaining elements from the left array
    while (i < left_size) {
        result[k++] = left[i++];
    }

    // Copy any remaining elements from the right array
    while (j < right_size) {
        result[k++] = right[j++];
    }
}

// Function to perform merge sort on an array
void merge_sort(int* arr, int size) {
    if (size <= 1) {
        return;  // Base case: array is already sorted
    }

    int mid = size / 2;

    // Allocate memory for the left and right halves
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((size - mid) * sizeof(int));

    // Split the array into two halves
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Recursively sort the left and right halves
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // Merge the two sorted halves back into the original array
    merge(left, mid, right, size - mid, arr);

    // Free the temporary memory used for left and right halves
    free(left);
    free(right);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array
    merge_sort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
