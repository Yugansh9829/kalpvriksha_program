#include<stdio.h>
#include<stdlib.h>


void solution(int arr[], int n){
    int first_occ[100000];
    int last_occ[100000];
    int freq[100000];

    for(int i=0;i<100000;i++){
        first_occ[i] = -1;
        last_occ[i] = 0;
        freq[i] = 0;
    }
    int most_freq_element = arr[0];
    for(int i=0;i<n;i++){
        if(first_occ[arr[i]]==-1){
            first_occ[arr[i]]=i;
            last_occ[arr[i]]=i;
        }
        else last_occ[arr[i]] = i;

        freq[arr[i]]+=1;
        if(freq[most_freq_element]<freq[arr[i]])most_freq_element = arr[i];
    }

    printf("%d and %d \n", first_occ[most_freq_element], last_occ[most_freq_element]);

    return;
}

int main(){

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);

    solution(arr, n);

    return 0;
}