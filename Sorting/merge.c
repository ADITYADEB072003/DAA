#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
void merge(int* list1, int size1, int* list2, int size2, int* merged_list) {
    int i = 0, j = 0, k = 0;

    // Merge the arrays while both have elements left
    while (i < size1 && j < size2) {
        if (list1[i] < list2[j]) {
            merged_list[k++] = list1[i++];
        } else {
            merged_list[k++] = list2[j++];
        }
    }

    // If elements are left in list1
    while (i < size1) {
        merged_list[k++] = list1[i++];
    }

    // If elements are left in list2
    while (j < size2) {
        merged_list[k++] = list2[j++];
    }
}

// Function to perform merge sort on a single array
void merge_sort(int* lst, int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((size - mid) * sizeof(int));

    // Split the array into two halves
    for (int i = 0; i < mid; i++) {
        left[i] = lst[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = lst[i];
    }

    // Recursively sort the two halves
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // Merge the sorted halves
    merge(left, mid, right, size - mid, lst);

    free(left);
    free(right);
}

int main() {
    int arr1[] = {1, 4, 6, 2, 0};
    int arr2[] = {3, 5, 7, 8, 9};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Sort arr1 and arr2
    merge_sort(arr1, size1);
    merge_sort(arr2, size2);

    printf("Sorted arr1: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Sorted arr2: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Merge sorted arr1 and arr2
    int* merged_arr = (int*)malloc((size1 + size2) * sizeof(int));
    merge(arr1, size1, arr2, size2, merged_arr);

    printf("Merged: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged_arr[i]);
    }
    printf("\n");

    free(merged_arr);
    return 0;
}