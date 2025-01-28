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

Node* sort_across_pivot(Node *head){
    Node *ptr = head;

    Node*mid = create_node(-1);
    mid->next = head;

    int pivot = -1;
    while(ptr->next)ptr = ptr->next;
    pivot = ptr->data;
    ptr = head;

    while(ptr->next){
        if(ptr->data < pivot){
            mid= mid->next;
            int temp = mid->data;
            mid->data = ptr->data;
            ptr->data = temp;
        }
        ptr = ptr->next;
    }

    int temp = mid->next->data;
    mid->next->data = ptr->data;
    ptr->data = temp;

    return mid;
}

void quick_sort(Node *head){
    if(head==NULL || head->next==NULL)return;

    Node* mid = sort_across_pivot(head);
   
    // printf("\n");
    Node *temp = mid->next;
    mid->next = NULL;

    quick_sort(head);
    quick_sort(temp->next);

    mid->next = temp;
    return;
}


int main(){
    Node *head = (Node*)malloc(sizeof(Node));
    head = NULL;
    int size = 0;

    while(1){
        int data;
        scanf("%d", &data);
        if(data==-1) break;
        size++;
        head = insert_at_end(head, data);
    }

    quick_sort(head);
    display_linked_list(head);

    return 0;
}