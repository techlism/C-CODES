#include<stdio.h>
int main(){
    int arr[10]={1,3,2,4,5,7,8,6,9,10};
    int n=10;
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
     /*Printing Array*/
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}