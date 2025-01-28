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

Node* find_mid(Node *head){
    if(!head || !head->next)return head;

    Node *fast = head->next;
    Node *slow  = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *head_1, Node *head_2){
    if(!head_1)return head_2;
    if(!head_2) return head_1;

    Node *final = (Node *)malloc(sizeof(Node));
    final = NULL;
    while(head_1 && head_2){
        if(head_1->data <= head_2->data){
            final = insert_at_end(final, head_1->data);
            head_1 = head_1->next;
        }else{
            final = insert_at_end(final, head_2->data);
            head_2 = head_2->next;
        }
    }
    Node *ptr = final;
    while(ptr->next) ptr = ptr->next;
    if(head_1)ptr->next = head_1;
    if(head_2)ptr->next = head_2;

    return final;
}

Node* merge_sort(Node *head){
    if(!head || !head->next) return head;
    
    Node *mid = find_mid(head);
    Node *head2 = mid->next;
    mid->next = NULL;

    Node *first = merge_sort(head);
    Node *second = merge_sort(head2);

    Node *final = merge(first, second);

    return final;
} 


int main(){
    Node *head = (Node*)malloc(sizeof(Node));
    head = NULL;
    int size = 0;

    printf("Enter node data of linked list (-1 for termination ) : ");
    while(1){
        int data;
        scanf("%d", &data);
        if(data==-1) break;
        size++;
        head = insert_at_end(head, data);
    }

    printf("\nLinked list befor sorting is : ");
    display_linked_list(head);
    head = merge_sort(head);

    printf("\n Linked list after sorting is : ");
    display_linked_list(head);

    return 0;
}