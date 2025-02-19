#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hash_map[26];

void decrement_count(char c, int *count){
    if(hash_map[c-'a']==1)(*count)--;
    hash_map[c-'a']-=1;
}

void increment_count(char c, int *count){
    if(hash_map[c-'a']==0)(*count)++;
    hash_map[c-'a']+=1;
    // printf("for %c value of count is : %d\n", c, *count);
    return;
}
int find_solution(char *str, int size, int k){
    int start = 0;
    int end = 0;

    int count = 0;
    int f_length = -1;

    while(end<size){
        
        increment_count(str[end], &count);

        if(f_length<(end-start) && count == k){
            f_length = (end-start);
        }
        if(end>=size-1)break;

        while(count>k){
            decrement_count(str[start], &count);
            start++;
        }
        end++;
    }
    if(count==k)f_length++;

    return  f_length;


}

int main(){

    char *str = (char *)malloc(100*sizeof(char));
    scanf("%s", str);
    int size = strlen(str);
    int k;
    printf("ENTER VALUE OF K : ");
    scanf("%d", &k);
    printf("%d", find_solution(str, size, k));


    return 0;
}