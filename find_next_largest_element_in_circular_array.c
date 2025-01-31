#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int arr[1000001];
    int top;
}stack;

int pop(stack*obj){
    return obj->arr[obj->top--];
}

void push(stack*obj, int data){
    obj->arr[++obj->top] = data;
}


void find_next_greater(int arr[], int ans[], int n){
    stack s;
    s.top = -1;
    ans[n-1] = 1e9;

    push(&s, n-1);

    for(int i=n-2;i>=0;i--){

        while(s.top!=-1 && arr[i] >= arr[s.arr[s.top]]) pop(&s);

        if(s.top==-1) ans[i] = 1e9;
        else ans[i] = arr[s.arr[s.top]];
        push(&s, i);
    }
    for(int i=0;i<n;i++){
        if(ans[i]==1e9){
            int found = 0;
            for(int j=0;j<i;j++){
                if(arr[j]>arr[i]){
                    ans[i]  = arr[j];
                    found = 1;
                    break;
                }
            }
            if(found==0)  ans[i] = -1; 
        }
    }
    for(int i=0;i<n;i++) printf("%d", ans[i]);
    return;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);

    int ans[n];

    find_next_greater(arr, ans, n);
}