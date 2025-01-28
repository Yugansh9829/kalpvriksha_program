#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node *create_node(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
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

void display(Node *head){
    Node *ptr = head;
    while(ptr){
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    }

    return;
}

void add(Node *head_1, Node *head_2){
    Node *ans = (Node*)malloc(sizeof(Node));

    ans = NULL;

    int carry = 0;

    while(head_1 && head_2){
        int sum = head_1->data + head_2->data + carry;
        if(sum>9){
            carry = 1;
            sum = sum%10;
        }else carry = 0;
        ans = insert_at_end(ans, sum);

        head_1 = head_1->next;
        head_2 = head_2->next;
    }

    if(carry!=0){
        ans = insert_at_end(ans, 1);
    }

    display(ans);

}

void take_input(){
    Node *head_1 = (Node*)malloc(sizeof(Node));
    head_1 = NULL;

    printf("enter data in first linked list (-1) for terminating : ");
    while(1){
        int data;
        scanf("%d", &data);
        if(data==-1) break;
        head_1 = insert_at_end(head_1, data);
    }

    Node *head_2 = (Node*)malloc(sizeof(Node));
    head_2 = NULL;
    printf("\n enter data in second linked list (-1) for terminating :");
    while(1){
        int data;
        scanf("%d", &data);
        if(data==-1) break;
        head_2 = insert_at_end(head_2, data);
    }

    add(head_1, head_2);
}

int main(){
    take_input();
    
    return 0;

}