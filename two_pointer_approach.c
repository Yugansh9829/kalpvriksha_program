#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *create_node(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;
}

Node *insert_at_end(Node *head, int data){
    if(head==NULL){
        head = create_node(data);
        return head;
    }

    Node *ptr = head;
    while(ptr->next)ptr = ptr->next;
    ptr->next = create_node(data);
    return head;
}

void display(Node *head){
    Node *ptr = head;

    while(ptr){
        printf("%d ==> ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return;
}

void find_target(Node *head1, Node *head2, int target){
    Node*pointer_1  = head1;
    Node*pointer_2 = head2;

    while(pointer_1 && pointer_2){
        if(pointer_1->data == target){
            printf("founded in list 1");
            return;
        }
        else if(pointer_2->data == target){
            printf("founded in list 2");
            return;
        }

        if(pointer_1->data <pointer_2->data)pointer_1= pointer_1->next;
        else pointer_2 = pointer_2->next;
    }

    if(pointer_1){
        while(pointer_1){
            if(pointer_1->data==target){
                printf("founded in list 1");
                return;
            }
            pointer_1 = pointer_1->next;
        }
    }
    if(pointer_2){
        while(pointer_2){
            if(pointer_2->data==target){
                printf("founded in list 1");
                return;
            }
            pointer_2 = pointer_2->next;
        }
    }

    printf("Not found");
    return;
}

int main(){
    Node *head_1 = (Node *)malloc(sizeof(Node));
    head_1 = NULL;

    Node *head_2 = (Node *)malloc(sizeof(Node));
    head_2 = NULL;
    
    for(int i=1;i<10;i+=2) head_1 = insert_at_end(head_1, i);
    for(int i=2;i<10;i+=2) head_2 = insert_at_end(head_2, i);

    printf("linked list  1 : ");
    display(head_1);
    printf("linked list 2 : ");
    display(head_2);
    printf("\n enter target to be searched in linked list : ");

    int target;
    scanf("%d", &target);

    find_target(head_1, head_2, target);

    return 0;
}