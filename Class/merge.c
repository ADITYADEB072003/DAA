// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
void merge(int *left,int left_size,int *right,int right_size,int *result){
    int i=0;
    int j=0;
    int k=0;
    while(i<left_size&&j<right_size){
        if(left[i]<right[j]){
            result[k++]=left[i++];
        }
        else{
            result[k++]=right[j++];
        }
    }
     while(i<left_size){
     result[k++]=left[i++];
         
     }
    while(j<right_size){
     result[k++]=left[j++];
         
     }
    
}
void merge_sort(int *arr,int size){
    if(size<=1){
        return ;
    }
    int mid=size/2;
    
    int*left=(int*)malloc(mid*sizeof(int));
    int *right=(int*)malloc((size-mid)*sizeof(int));
    for(int i=0;i<mid;i++){
        left[i]=arr[i];
    }
     for(int i=mid;i<size;i++){
        right[i-mid]=arr[i];
    }
    merge_sort(left,mid);
    merge_sort(right,mid-size);
    
    merge(left,mid,right,mid-size,arr); 
}
int main() {
 
   int n=500000;
int *arr = (int *)malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Random numbers between 0 and 999999
    }
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array
    merge_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
   
