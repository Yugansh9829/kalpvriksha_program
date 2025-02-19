#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int contains_k_distinct_integer(char *arr, int start, int end, int k){
    int hash_map[26]= {0};
    int count = 0;
    for(int i=start;i<=end;i++){
        if(hash_map[arr[i]-'a']==0)count++;
        hash_map[arr[i]-'a']+=1;
    }

    if(count==k)return 1;
    return 0;
}

void longest_substring_with_k_distinct_integers(char *arr, int size, int k){
    int ans = -1;

    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(ans< (j-i+1) && contains_k_distinct_integer(arr, i, j ,k)){
                ans = (j-i+1);
            }
        }
    }

    printf("ans : %d \n", ans);
}


int main(){

    char *input = (char *)malloc(50*sizeof(char));
    scanf("%s", input);
    int size = strlen(input);   

    int k;
    scanf("%d", &k);

    longest_substring_with_k_distinct_integers(input, size, k);


    return 0;
}