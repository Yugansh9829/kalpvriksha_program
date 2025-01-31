#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int arr[50];
    int front;
    int rear;
}queue;

void enqueue(queue *obj, int data){
    if(obj->rear==50){
        printf("overflow\n");
        return;
    }
    if(obj->front==-1 && obj->rear==-1){
        obj->front+=1;
    }
    obj->arr[++obj->rear] = data;
    return;
}

int dequeue(queue*obj){
    if(obj->rear==-1 && obj->front==-1){
        printf("queue is empty\n");
        return 1e9;
    }
    if(obj->front==obj->rear){
        int data = obj->arr[obj->front];
        obj->rear = -1;
        obj->front = -1;
        return data;
    }
    int data = obj->arr[obj->front++];
    return data;
}

int peek(queue*obj){
    if(obj->rear==-1 &&obj->front==-1){
        printf("queue is empty\n");
        return 1e9;
    }
    return obj->arr[obj->front];
}

int isEmpty(queue*obj){
    if(obj->rear==-1 && obj->front==-1) return 1;
    return 0;
}

int size(queue*obj){
    if(obj->front==-1 && obj->rear==-1)return 0;

    return (obj->rear - obj->front)+1;
}

void print_queue(queue*obj){
    if(obj->front==-1 && obj->rear==-1){
        printf("queue is empty\n");
    }
    for(int i=obj->front;i<=obj->rear;i++){
        printf("%d --> ", obj->arr[i]);
    }
}

int main(){
    queue q;
    q.front=-1;
    q.rear=-1;
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
                enqueue(&q, val);
                break;
            case 2 :
                val = dequeue(&q);
                if(val==1e9) continue;
                printf("Value poped from front of queue is : %d\n", val);
                break;
            case 3 :
                val = peek(&q);
                if(val==1e9) continue;
                printf("value at front of queue is : %d\n", val);
                break;
            case 4 :
                int is_empty = isEmpty(&q);
                is_empty==1? printf("queue is empty\n") : printf("queue is not empty\n");
                break;
            case 5 : 
                int size_of_queue = size(&q);
                printf("size of queue is : %d\n", size_of_queue);
                break;
            case 6 : 
                while_true = 0;
                break;
            default :
                printf("Enter valid operation\n");
                break;

        }
    }


    return 0;
}