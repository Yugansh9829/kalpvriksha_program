#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node *create_node(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
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
    ptr->next->prev = ptr;
    return head;
}

void binary_search(Node *head, int target){
    if(!head){
        printf("No node exists in list \n");
        return;
    }

    int start = 0;
    int end = 0;
    Node *ptr = head;
    while(ptr->next){
        ptr = ptr->next;
        end +=1;
    }
    Node*itr = head;
    while(start<=end){
        int mid = (start+end)/2;
        itr = head;
        int idx = mid;

        while(itr && mid--)itr = itr->next;

        if(itr->data == target){
            printf("founded target at index : %d\n", idx);
            return;
        }

        if(itr->data >target)end = idx-1;
        else start = idx+1;
    }

    printf("Not found\n");
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
    printf("enter node of linked list (-1 ) to terminate : ");
    while(1){
        int data;
        scanf("%d", &data);
        if(data==-1) break;
        head = insert_at_end(head, data);
    }

    int target = 0;
    printf("\nEnter target to search in linked list : ");
    scanf("%d", &target);
    binary_search(head, target);
    

    return 0;
}