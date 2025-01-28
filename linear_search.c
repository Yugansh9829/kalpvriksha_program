#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *create_node(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node *insert_at_end(Node *head, int data){
    if(head == NULL){
        head = create_node(data);
        return head;
    }

    Node *ptr = head;
    while(ptr->next) ptr = ptr->next;
    ptr->next = create_node(data);
    return head;
}

void linear_search(Node *head, int target){
    Node *ptr = head;
    int position = 1;
    while(ptr){
        if(ptr->data == target)break;
        ptr = ptr->next;
        position++;
    }

    if(!ptr) printf("Element does not exists in linked list\n");
    else printf("element is present in linked list at position(1-based indexing) : %d ", position);

    return;
}

void display_list(Node *head){
    Node *ptr = head;
    while(ptr){
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    }
    return;
}

int main(){
    Node *head = (Node *)malloc(sizeof(head));

    head = NULL;

    while(1){
        int data;
        scanf("%d", &data);
        if(data==-1) break;
        head = insert_at_end(head, data);
    }

    int target = 0;
    printf("\nEnter target to search in linked list : ");
    scanf("%d", &target);
    linear_search(head, target);
    
}