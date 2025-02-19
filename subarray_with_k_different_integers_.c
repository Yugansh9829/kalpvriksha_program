#include<stdio.h>
#include<stdlib.h>

int solve(int arr[], int size, int k){
    int hash_map[size+1];
    for(int i=0;i<size+1;i++) hash_map[i]=0;
    int ans = 0;
    int count = 0;

    for(int i=0;i<=size-k;i++){
        for(int j=(i);j<size;j++){
            if(hash_map[arr[j]]==0) count++;
            hash_map[arr[j]]+=1;
            if(count==k)ans+=1;   
        }
        for(int j=i;j<size;j++) hash_map[arr[j]]-=1;
        count = 0;
    }
    return ans;
}


int main(){

    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array : ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter value of k : ");
    scanf("%d", &k);

    printf("ans is : %d\n", solve(arr, n, k));


    return 0;

}