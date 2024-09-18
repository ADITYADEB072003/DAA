#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selection(int arr[], int n) {
  int i, j, min_index, temp;
  for (i = 0; i < n; i++) {
    min_index = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
      if (min_index != 1) {
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
      }
    }
  }
}
int main() {

  int n = 50000;
  int a[500000];
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 100000;
  }
  selection(a, n);
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
  }
  printf("\n");
}
