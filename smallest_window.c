#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void solve(char *first, int n, char *second, int m){
    int s = 0;
    int e = 0;
    int hash_map[26] = {0};
    int ans = 100000;
    for(int i=0;i<m;i++)hash_map[second[i]-'a']+=1;
    int count = 0;
    int si = 0;
    while(e<n){
        while(count != m){
            if(hash_map[first[e]-'a']>0)count++;
            hash_map[first[e]]--;
            e++;
        }


        while(count==m){
            if(e-s+1 < ans){
                ans = (e-s+1);
                si =  s;
            }
            if(hash_map[first[s]]>0) count--;
        }


        e+=1;
    }

    printf("%d\n", ans);

}

int main(){
    char *input = (char *)malloc(100*sizeof(char));
    scanf("%s", input);
    int size = strlen(input);
    char *another_input = (char *)malloc(100*sizeof(char));
    scanf("%s", another_input);
    int size2 = strlen(another_input);
    solve(input, size, another_input, size2);
}