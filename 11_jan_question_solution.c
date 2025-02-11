#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *str_arr[100];

int not_same(char *first, char *second){
    int s1 = strlen(first);
    int s2 = strlen(second);

    for(int i=0;i<s1;i++){
        for(int j=0;j<s2;j++){
            if(first[i]==second[j]) return 0;
        }
    }
    return 1;
}

void solution(int idx){
    int ans = 0;
    for(int i=0;i<idx-1;i++){
        for(int j=i+1;j<idx;j++){
            if(not_same(str_arr[i], str_arr[j])){
                int temp_ans = (strlen(str_arr[i]) * strlen(str_arr[j]));
                if(temp_ans > ans) ans = temp_ans;
            }
        }
    }
    printf("%d \n", ans);

    return;
}
int main(){
    int n;
    scanf("%d", &n);
    int idx = 0;
    while(n--){
        char *str = (char *)malloc(100*sizeof(char));
        scanf("%s", str);
        str_arr[idx++]  = str;
    }

    solution(idx);
}