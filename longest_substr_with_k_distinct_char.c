#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_contained(char *input, int start, int end, int size, int k){
    int hash_map[26] = {0};
    int count = 0;
    for(int i=start;i<=end;i++){
        if(hash_map[input[i]-'a']==0) count ++;
        hash_map[input[i]-'a']+=1;
    }
    if(count == k)return 1;
    return 0;
}

void solve(char *input, int size, int k){
    int ans = -1;
    for(int i=0;i<size;i++){ 
        for(int j=i;j<size;j++){
            if(ans < (j-i+1) && is_contained(input, i, j, size, k)){
                printf("from %d to %d \n", i, j);
                ans = (j-i+1);
            }
        }
    }
    printf("%d\n", ans);
}


int main(){

    char *input = (char *)malloc(100*sizeof(char));
    scanf("%s", input);

    int size = strlen(input);

    int k ;
    scanf("%d", &k);

    solve(input, size, k);

    return 0;   
}