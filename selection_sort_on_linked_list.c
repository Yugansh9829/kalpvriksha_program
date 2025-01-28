#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node*next;
}Node;

Node* create_node(int data){
    Node *node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;

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

    return head;
}

void display_linked_list(Node *head){
    Node*itr = head;
    while(itr){
        printf("%d-->", itr->data);
        itr = itr->next;
    }
    return;
}

void selection_sort(Node *head, int size){
    Node *ptr = head;

    for(int i=0;i<size;i++){
        ptr = head;
        int count =i;
        while(count--) ptr = ptr->next;
        Node *smallest = ptr;
        Node* itr = ptr;
        while(itr){
            if(itr->data < smallest->data){
                smallest = itr;
            }
            itr = itr->next;
        }
        int temp = ptr->data;
        ptr->data = smallest->data;
        smallest->data  = temp;
    }
    
    return;
}


int main(){
    Node *head = (Node*)malloc(sizeof(Node));
    head = NULL;

    for(int i=10;i>=1;i--) head = insert_at_end(head, i);

    selection_sort(head, 10);
    display_linked_list(head);

    return 0;
}