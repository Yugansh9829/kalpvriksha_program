#include<stdio.h>
#include<stdlib.h>

int sort_from_mid(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start-1;
    
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;

    return i;
}


void quick_sort(int arr[], int start, int end){
    if(start>end) return;

    int mid = sort_from_mid(arr, start, end);

    quick_sort(arr, start, mid-1);
    quick_sort(arr, mid+1, end);
}


int main(){

    char *s = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", s);

    int arr[10000];
    int count = 0;

    while(*s !='\0'){
        if(*s==' '){
            s++;
            continue;
        }
        if(*s-'0'>=0 && *s-'0'<=9){
            int number = 0;
            int negative = 0;
            if(*(s-1)=='-')negative = 1;
            while(*s-'0'>=0 && *s-'0'<=9){
                number = (number * 10) + (*s-'0');
                s++;
            }
            if(negative) number = -number;
            arr[count++] = number;
            continue;
        }
        arr[count++] = *s;
        s++;
    }


    quick_sort(arr, 0, count-1);

    for(int i=0;i<count;i++){
        printf("%c ", arr[i]);
    }


}