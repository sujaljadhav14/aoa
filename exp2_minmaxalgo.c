#include<stdio.h>

void main(){

    int arr[] = {40,20,30,80,50,60,50};
    int n = (sizeof(arr)/sizeof(arr[0]));
    int max = arr[0];
    int min = arr[0];

    for (int i =0;i<n;i++){

        if(max<arr[i]){
            max = arr[i];
        }
        if(min>arr[i]){
            min = arr[i];
        }

    }

    printf("Max = %d" , max);    
    printf("\nMin = %d" , min);

    getch();

}
