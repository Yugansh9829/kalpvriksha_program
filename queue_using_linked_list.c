#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct queue{
    Node *head;
}queue;

Node * create_node(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void enqueue(queue *obj, int data){
    if(!obj->head){
        obj->head = create_node(data);
        return;
    }

    Node *ptr = obj->head;

    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = create_node(data);
    return;
}

int dequeue(queue*obj){
    if(!obj->head){
        printf("queue is empty\n");
        return 1e9;
    }

    int data = obj->head->data;
    obj->head = obj->head->next;

    return data;
}

int peek(queue*obj){
    if(!obj->head){
        printf("queue is empty\n");
        return 1e9;
    }
    
    return obj->head->data;
}

int isEmpty(queue*obj){
    if(!obj->head)return 1;

    return 0;
}

int size(queue*obj){
    Node*ptr = obj->head;
    int size=0;
    while(ptr){
        ptr = ptr->next;
        size++;
    }
    return size;
}


int main(){
    queue * q = (queue*)malloc(sizeof(queue));
    q->head = NULL;

    int while_true = 1;

    while(while_true){
        int operation=0;
        printf("Enter operation you want to perform : \n 1 for enqueue \n 2 for dequeue \n 3 for peek \n 4 for isEmpty \n 5 for size \n 6 to exit \n");
        scanf("%d", &operation);
        int val;
        switch(operation){
            case 1 : 
                printf("Enter value to add in queue : ");
                scanf("%d", &val);
                enqueue(q, val);
                break;
            case 2 :
                val = dequeue(q);
                if(val==1e9) continue;
                printf("Value poped from front of queue is : %d\n", val);
                break;
            case 3 :
                val = peek(q);
                if(val==1e9) continue;
                printf("value at front of queue is : %d\n", val);
                break;
            case 4 :
                int is_empty = isEmpty(q);
                is_empty==1? printf("queue is empty\n") : printf("queue is not empty\n");
                break;
            case 5 : 
                int size_of_queue = size(q);
                printf("size of queue is : %d\n", size_of_queue);
                break;
            case 6 : 
                while_true = 0;
                break;

            default : printf("Enter valid operation\n");

        }
    }

}