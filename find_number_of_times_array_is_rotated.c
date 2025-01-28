#include<stdio.h>

void find_(int arr[], int size){
    int start = 0;
    int end = size-1;

    while(start<end){
        int mid = (start+end)/2;

        if(arr[mid]>start)start =mid;
        else end = mid-1;
    }

    printf("it is rotated %d times ", start+1);
    return;
}

int main(){
    
    int size = 0;
    int arr[1000];
    while(1){
        int data;
        scanf("%d", &data);
        if(data==-1)break;
        arr[size++] = data;
    }

    find_(arr, size);
}