#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble_sort(int a[],int s){
     
    int i,j ,temp=0;
    for(i=1;i<=s;i++){
        for(j=0;j<s-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
        }
    }
   
}
int main(){
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
    bubble_sort(arr, n);

    // Print the first 10 elements to verify
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free the allocated memory
    return 0;
   

}