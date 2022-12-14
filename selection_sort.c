#include<stdio.h>

int  main(){
    int arr[10]={1,3,2,4,5,7,8,6,9,10};
    int temp;
    for(int i=0;i<8;i++){
       for(int j=i+1;j<9;j++){
        if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
       }
    }
    //Printing 
    for(int i=0;i<10;i++){
     printf("%d ",arr[i]);
    }
}