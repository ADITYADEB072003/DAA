#include <stdio.h>
int main(){
    int a[]={6,3,2,5,4,1};
    int s=sizeof(a)/sizeof(a[0]);
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
    for(int k=0;k<s;k++){
        printf("\n A[%d]=%d\n",k,a[k]);
    }

}