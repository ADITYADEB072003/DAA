#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    bool swapped = true;

    for (i = 0; i < n - 1 && swapped; i++) {
        swapped = false;
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                swapped = true;
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
    bool swapped = true;

    for (i = 1; i < n && swapped; i++) {
        swapped = false;
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            swapped = true;
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

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100000;
    }

    // Choose the sorting algorithm here
    // selectionSort(a, n);
    // insertionSort(a, n);
    bubbleSort(a, n);

    // Print only the first few elements for verification
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}

