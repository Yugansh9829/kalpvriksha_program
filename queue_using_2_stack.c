#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int arr[100];
    int top;
}stack;

void push(stack *obj, int data){
    obj->arr[++obj->top] = data;
    return;
}

int pop(stack *obj){
    if(obj->top==-1){
        printf("queue is empty\n");
        return 1e9;
    }
    return obj->arr[obj->top--];
}

int peek(stack *obj){
    if(obj->top==-1){
        printf("queue is empty\n");
        return 1e9;
    }
    return obj->arr[obj->top];
}

int is_Empty(stack *obj){
    if(obj->top==-1) return 1;
    return 0;
}

int size(stack *obj){
    return obj->top+1;
}

//------------------------------------------------------------------//

void push_by_reversing_stack(stack*s,stack*s2, int data){
    while(!is_Empty(s)){
        push(s2, pop(s));
    }

    push(s, data);

    while(!is_Empty(s2)){
        push(s, pop(s2));
    }

    return;
}

int main(){

    stack s;
    stack s2;
    s.top = -1;
    s2.top = -1;

    int while_true  = 1;
    while(while_true){
        int operation = 0;
        printf("Enter operation you want to perform : \n 1 for enqueue \n 2 for dequeue \n 3 for peek \n 4 for isEmpty \n 5 for size \n 6 to exit \n");
        scanf("%d", &operation);
        int val;
        switch(operation){
            case 1 : 
                printf("Enter value to add in queue : ");
                scanf("%d", &val);
                push_by_reversing_stack(&s,&s2, val);
                break;
            case 2 :
                val = pop(&s);
                if(val==1e9) continue;
                printf("poped value from front of queue is : %d\n", val);
                break;
            case 3 :
                val = peek(&s);
                if(val==1e9) continue;
                printf("value at front of queue is : %d\n", val);
                break;
            case 4 :
                int is_empty = is_Empty(&s);
                is_empty==1? printf("queue is empty\n") : printf("queue is not empty\n");
                break;
            case 5 : 
                int size_of_stack = size(&s);
                printf("size of queue is : %d\n", size_of_stack);
                break;
            case 6 : 
                while_true = 0;
                break;

            default : printf("Enter valid operation\n");
                break;
        }
    }
}