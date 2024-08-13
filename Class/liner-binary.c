#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int linear(int a[], int n) {
    int j;
    printf("Linear Search\n");
    printf("Enter the number to search\n");
    scanf("%d", &j);
    for (int i = 0; i < n; i++) {
        if (a[i] == j) {
            return 1;
        }
    }
    return -1;
}

void insertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int binary(int a[], int left, int right) {
    int j;
    printf("Binary Search\n");
    printf("Enter the number to search\n");
    scanf("%d", &j);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == j) {
            return mid;
        }
        if (a[mid] < j) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = rand();
    }
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d \n", a[i]);
    }

    insertion(a, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d \n", a[i]);
    }

    int k = binary(a, 0, n - 1);
    if (k == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", k);
    }
    printf("Linear");
    int k1 = linear(a, n - 1);
    if (k1 == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", k);
    }
    free(a); // Free allocated memory
    return 0;
}
