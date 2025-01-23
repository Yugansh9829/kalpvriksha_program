#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;
}Node;

Node* create_node(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

Node * insert_at_end(Node *head, int data){
    if(head==NULL){
        head = create_node(data);
        return head;
    }

    Node *ptr = head;
    while(ptr->next) ptr = ptr->next;

    ptr->next = create_node(data);
    return head;
}

void k_node_from_end_of_linked_list(Node *head, int size, int k){
    if(k>size){
        printf("enter valid value for k");
        return;
    }
    if(k==size){
        printf("%d", head->data);
        return;
    }

    int iterate = size-k;
    
    while(--iterate>0){
        head = head->next;
    }

    printf("%d", head->next->data);
    return;
}

int main(){
    Node *head = (Node*)malloc(sizeof(Node));
    head = NULL;

    int count=0;
    printf("enter nodes of linked list and -1 to complete : ");
    // scanf("%d", &count);

    while(1){
        int data;
        scanf("%d", &data);
        if(data==-1)break;
        count++;
        head = insert_at_end(head, data);
    }

    int k;
    printf("Enter value of k : ");
    scanf("%d", &k);

    k_node_from_end_of_linked_list(head, count, k);
}