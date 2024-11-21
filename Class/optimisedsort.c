#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int n = 250000;
    int *a = (int *)malloc(n * sizeof(int));

    if (!a) {
        printf("Memory allocation failed\n");
        return -1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100000;
    }

    // Uncomment the sorting algorithm you want to use
    // selectionSort(a, n);   // Very slow for large n
    // insertionSort(a, n);   // Very slow for large n
    bubbleSort(a, n);         // Still slow, but slightly better

    // Print only the first few elements for verification
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}