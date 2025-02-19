#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int arr[1000];
    int top;
}stack;

void push(stack *s, int bookmarked_page){
    s->arr[++s->top] = bookmarked_page;
    return;
}

int pop(stack *s){
    if(s->top==-1) return 1e9;
    return s->arr[s->top--];
}

int size(stack *s){
    return s->top+1;
}

int is_empty(stack *s){
    return (s->top == -1);
}

int top(stack *s){
    return s->arr[s->top];
}

int arr[1000];
void sort_stack_and_display(stack *s){
    if(is_empty(s)) return;

    arr[s->top] = top(s);

    int a = pop(s);
    sort_stack_and_display(s);
    push(s, a);
    return;
}

void sort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=(n-i-1);j++){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    return;
}

void display(stack *s){
    int n = s->top;
    sort(arr, n+1);
    for(int i=0;i<=n;i++){
        printf("%d ", arr[i]);
    }
}

int main(){

    int count;
    stack s;
    s.top = -1;

    scanf("%d", &count);

    while(count--){
        printf("Enter operation to perform \n ");

        int operation;
        scanf("%d", &operation);
        
        if(operation==1){
            int page;
            printf("enter value of page to be bookmarked : ");
            scanf("%d", &page);
            push(&s, page);

        }else if(operation==2){
            int ans = pop(&s);
            if(ans==1e9){
                printf("no page bookmarked right now \n");
            }
            else printf("poped value is : %d \n", ans);

        }else if(operation==3){
            sort_stack_and_display(&s); 
            display(&s);

        }else{
            printf("enter valid operation\n");
        }
    }



    return 0;
}