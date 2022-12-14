#include<stdio.h>
/*BUBBLE SORT*/
int main(){
    int arr[10]={1,3,2,4,5,7,8,6,9,10};
    int temp;
    for(int i=0;i<8;i++){
     for(int j=0;j<8-i;j++){
          if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
    /*Printing Array*/
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    /*TIME COMPLEXITY O(n^2)*/
}
