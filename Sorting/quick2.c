#include <stdio.h>
#include <stdlib.h>
// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that takes the first element as the pivot,
// places the pivot element at its correct position, and places
// all smaller elements to the left of the pivot and all larger
// elements to the right.
int partition(int* arr, int low, int high) {
    int pivot = arr[low];      // Pivot is the first element
    int i = low + 1;       // Index of larger element

    for (int j = low ; j <= high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    // Swap the pivot element with the element at i - 1
    swap(&arr[low], &arr[i - 1]);
    return (i - 1);  // Return the pivot index
}

// The main quick sort function
void quick_sort(int* arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivot_index = partition(arr, low, high);

        // Recursively sort elements before and after the partition
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main() {
    
     int n=500000;
int *arr1 = (int *)malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 1000000; // Random numbers between 0 and 999999
    }
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Sort the array
    quick_sort(arr1,0,n-1);

    printf("Sorted array: ");
    for (int i = 0; i < 30; i++) {
        printf("%d ", arr1[i]);
    }
}