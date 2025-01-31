#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct stack{
    Node *head;
}stack;

Node* create_node(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}

void push(stack *obj, int data){
    if(!obj->head){
        obj->head = create_node(data);
        return;
    }
    Node *temp = create_node(data);
    temp->next = obj->head;
    obj->head = temp;
}

int pop(stack *obj){
    if(!obj->head){
        printf("stack is empty\n");
        return 1e9;
    }
    int data = obj->head->data;
    obj->head = obj->head->next;

    return data;
}

int peek(stack *obj){
    if(!obj->head){
        printf("stack is empty\n");
        return 1e9;
    }

    return obj->head->data;
}

int isEmpty(stack *obj){
    if(!obj->head) return 1;
    return 0;
}

int size(stack *obj){
    int size = 0;
    Node *ptr = obj->head;
    while(ptr){
        ptr = ptr->next;
        size++;
    }
    return size;
}


int main(){
    stack *s = (stack*)malloc(sizeof(s));
    s->head = NULL;

    int while_true = 1;

    while(while_true){
        int operation=0;
        printf("Enter operation you want to perform : \n 1 for push \n 2 for pop \n 3 for peek \n 4 for isEmpty \n 5 for size \n 6 to exit \n");
        scanf("%d", &operation);
        int val;
        switch(operation){
            case 1 : 
                printf("Enter value to add in stack : ");
                scanf("%d", &val);
                push(s, val);
                break;
            case 2 :
                val = pop(s);
                if(val==1e9) continue;
                printf("Value at top of stack is : %d\n", val);
                break;
            case 3 :
                val = peek(s);
                if(val==1e9) continue;
                printf("value at top of stack is : %d\n", val);
                break;
            case 4 :
                int is_empty = isEmpty(s);
                is_empty==1? printf("stack is empty\n") : printf("stack is not empty\n");
                break;
            case 5 : 
                int size_of_stack = size(s);
                printf("stack size is : %d\n", size_of_stack);
                break;
            case 6 : 
                while_true = 0;
                break;

            default : printf("Enter valid operation\n");
                break;

        }
    }

    return 0;
}