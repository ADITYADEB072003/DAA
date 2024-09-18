#include <stdio.h>

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
printf(" pivot:-%d \n",pivot_index);
        // Recursively sort elements before and after the partition
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main() {
    int arr[] =  {65, 70, 75, 80, 85, 60, 55, 50, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using quick sort
    quick_sort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}