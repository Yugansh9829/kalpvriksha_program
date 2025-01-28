#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
}Node;

Node* create_node(int data){
    Node *node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node* insert_at_end(Node *head, int data){
    if(!head){
        head = create_node(data);
        return head;
    }
    Node *ptr = head;
    while(ptr->next) ptr = ptr->next;
    ptr->next = create_node(data);
    ptr->next->prev = ptr;
    return head;
}

void display_linked_list(Node *head){
    Node*itr = head;
    while(itr){
        printf("%d -->  ", itr->data);
        itr = itr->next;
    }
    return;
}

void insertion_sort(Node *head, int size){
    if(!head->next)return;

    Node *itr = head->next;

    for(int i=1;i<size;i++){
        itr = head->next;
        int count =i;
        while(--count) itr = itr->next;
        // Node *itr = ptr;
        int curr_data = itr->data;
        while(itr->prev && itr->prev->data > curr_data){
            itr->data = itr->prev->data;
            itr = itr->prev;
        }
        itr->data = curr_data;
    }
    
    return;
}


int main(){
    Node *head = (Node*)malloc(sizeof(Node));
    head = NULL;
    int size = 0;

    printf("enter nodes in linked list (-1 for temination ) :");
    while(1){
        int data;
        scanf("%d", &data);
        if(data==-1) break;
        size++;
        head = insert_at_end(head, data);
    }
    
    printf("linked list before sorting is : ");
    display_linked_list(head);
    insertion_sort(head, size);
    printf("\nlinked list after sorting is : ");
    display_linked_list(head);

    return 0;
}