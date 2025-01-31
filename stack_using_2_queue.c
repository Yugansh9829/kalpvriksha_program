#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int arr[100];
    int front;
    int rear;
} queue;

void enqueue(queue *obj, int data)
{
    if (obj->rear == 100)
    {
        printf("overflow\n");
        return;
    }
    if (obj->front == -1 && obj->rear == -1)
    {
        obj->front += 1;
    }
    obj->arr[++obj->rear] = data;
    return;
}

int dequeue(queue *obj)
{
    if (obj->rear == -1 && obj->front == -1)
    {
        printf("queue is empty\n");
        return 1e9;
    }
    if (obj->front == obj->rear)
    {
        int data = obj->arr[obj->front];
        obj->rear = -1;
        obj->front = -1;
        return data;
    }
    int data = obj->arr[obj->front++];
    return data;
}

int peek(queue *obj)
{
    if (obj->rear == -1 && obj->front == -1)
    {
        printf("queue is empty\n");
        return 1e9;
    }
    return obj->arr[obj->front];
}

int isEmpty(queue *obj)
{
    if (obj->rear == -1 && obj->front == -1)
        return 1;
    return 0;
}

int size(queue *obj)
{
    if (obj->front == -1 && obj->rear == -1)
        return 0;
    return (obj->rear - obj->front) + 1;
}

void print_queue(queue *obj)
{
    if (obj->front == -1 && obj->rear == -1)
    {
        printf("queue is empty\n");
    }
    for (int i = obj->front; i <= obj->rear; i++)
    {
        printf("%d --> ", obj->arr[i]);
    }
}

//--------------------------------------------------------------//

int peek_for_stack(queue *obj, queue *obj2)
{
    while (size(obj) != 1)  enqueue(obj2, dequeue(obj));
    
    int data = peek(obj);
    enqueue(obj2, dequeue(obj));

    return data;
}

int pop_from_stack(queue *q, queue *q2)
{
    if (isEmpty(q) && isEmpty(q2))
    {
        printf("stack is empty\n");
        return 1e9;
    }
    while (size(q) != 1)
    {
        enqueue(q2, dequeue(q));
    }

    return dequeue(q);
}

int main()
{
    queue q;
    q.front = -1;
    q.rear = -1;

    queue q2;
    q2.front = -1;
    q2.rear = -1;

    int while_true = 1;

    while (while_true)
    {
        int operation = 0;
        printf("Enter operation you want to perform : \n 1 for push \n 2 for pop \n 3 for peek \n 4 for isEmpty \n 5 for size \n 6 to exit \n");
        scanf("%d", &operation);
        int val;
        switch (operation)
        {
        case 1:
            printf("Enter value to push in stack : ");
            scanf("%d", &val);
            if (isEmpty(&q))
                enqueue(&q2, val);
            else
                enqueue(&q, val);

            break;
        case 2:
            if (isEmpty(&q2))
                val = pop_from_stack(&q, &q2);
            else
                val = pop_from_stack(&q2, &q);

            if (val == 1e9)
                break;
            printf("poped value from top of stack is : %d\n", val);

            break;
        case 3:
            if (isEmpty(&q2))
                val = peek_for_stack(&q, &q2);
            else
                val = peek_for_stack(&q2, &q);

            if (val == 1e9)
                break;
            printf("value at top of stack is : %d\n", val);

            break;

        case 4:
            int is_empty = isEmpty(&q);
            is_empty == 1 ? printf("stack is empty\n") : printf("stack is not empty\n");
            break;

        case 5:
            int size_of_queue = size(&q);
            printf("stack size is : %d\n", size_of_queue);
            break;

        case 6:
            while_true = 0;
            break;
        case 7:
            if (isEmpty(&q))
                print_queue(&q2);
            else
                print_queue(&q);

        default:
            printf("Enter valid operation\n");
            break;
        }
    }

    return 0;
}