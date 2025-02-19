#include<stdio.h>
#include<stdlib.h>


void solve(int n, int arr[n], int k){
    int s =  0;
    int e = k-1;
    int hash_map[100000];
    int ans = 0;
    for(int i=0;i<100000;i++) hash_map[i]= 0;

    for(s=0;s<k;s++){
        if(hash_map[arr[s]]==0) ans++;
        hash_map[arr[s]]+=1;
    }

    s = 0;
    e = k;
    printf("%d ", ans);
    while(e<n){
        hash_map[arr[s]]--;

        if(hash_map[arr[s++]]==0)ans-=1;
        if(hash_map[arr[e]]==0)ans+=1;

        hash_map[arr[e]]+=1;

        printf("%d ", ans);
        e++;
    }

}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);

    int k;
    scanf("%d", &k);
    solve(n, arr, k);

    return 0;
}