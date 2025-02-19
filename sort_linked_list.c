#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* create_node(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_at_end(Node **head, int data){
    Node *ptr = *head;
    if(!ptr){
        *head = create_node(data);
        return;
    }

    while(ptr->next) ptr = ptr->next;

    ptr->next = create_node(data);
    return;
}

void display(Node *head){
    Node *ptr = head;

    while(ptr){
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    }

    return;
}

Node *find_mid(Node *head){
    Node *slow = head;
    Node *fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge_both_parts(Node *head, Node *head2){
    Node *first;
    if(head->data < head2->data){
        first = head;
        head = head->next;
    }
    else{
        first = head2;
        head2 = head2->next;
    }

    Node *ptr = first;

    while(head && head2){
        if(head->data <= head2->data){
            ptr->next = head;
            head = head->next;
        }else{
            ptr->next = head2;
            head2 = head2->next;
        }
        ptr = ptr->next;
    }
    if(head) ptr->next = head;
    if(head2) ptr->next = head2;

    // display(first);
    // printf("\n");
    return first;
}

Node* sort(Node *head){
    if(!head || !head->next)return head;


    Node *mid = find_mid(head);
    Node *head2 = mid->next;
    mid->next = NULL;

    Node *first = sort(head);
    Node *second = sort(head2);

    Node *final = merge_both_parts(first, second);

    return final;
}

void merge_sort(Node **head){
    *head = sort(*head);
}

int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;

    for(int i=10;i>=0;i--)insert_at_end(&head, i);

    // bubble_sort(&head);
    merge_sort(&head);

    display(head);
}