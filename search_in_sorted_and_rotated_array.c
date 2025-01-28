#include<stdio.h>

void find_(int arr[], int size, int target){
    int start = 0;
    int end  = size-1;


    while(start<=end){
        int mid = (start+end)/2;

        if(arr[mid] == target){
            printf("founded at index : %d", mid);
            return;
        }

        else if(arr[mid]>arr[start]){
            if(target>=arr[start] && target<arr[mid])end = mid-1;
            else start = mid+1;
        }else{
            if(target<=arr[end] && target>arr[mid])start = mid+1;
            else end = mid-1;
        }
    }

    printf("not found");
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

    int target;

    scanf("%d", &target);
    find_(arr, size, target);
}