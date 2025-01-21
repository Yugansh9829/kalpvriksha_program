#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node*next;
}Node;

typedef struct Linked_list{
    Node* head;
}Linked_list;

Node* create_node(int data){
    Node *first = (Node*)malloc(sizeof(Node));
    first->next = NULL;
    first->data = data;
    return first;

}

void insert_at_end(Linked_list*ll, int data){
    if(ll->head==NULL){
        ll->head = create_node(data);
        return;
    }

    Node *itr = ll->head;
    while(itr->next){
        itr = itr->next;
    }

    itr->next = create_node(data);
    return;
}

void display(Linked_list*ll){
    Node *ptr = ll->head;

    while(ptr){
        printf("%d -->", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
    return ;
}

void rotate_linked_list(Linked_list*ll, int k, int n){
    Node*ptr = ll->head;
    k = k%n;
    if(k==0){
        display(ll);
        return;
    }
    int till = n-k;
    while(--till){
        ptr = ptr->next;
    }

    Node *temp = ptr->next;
    ptr->next = NULL;
    
    Node *head = ll->head;

    ll->head = temp;
    while(temp->next)temp = temp->next;
    temp->next = head;

    display(ll);
}

int main(){

    int k;
    scanf("%d" , &k);
    int count = 0;
    
    Linked_list*ll = (Linked_list*)malloc(sizeof(Linked_list));
    ll->head = NULL;

    while(1){
        int n;
        scanf("%d", &n);
        if(n==-1)break;
        count++;
        insert_at_end(ll, n);
    }

    rotate_linked_list(ll, k, count);
    return 0;
}