#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum complexity{
    one,
    logn,
    n,
    nlogn,
    nsquare,
    ncube,
    factorial
}complexity;


typedef struct Node{
    complexity tc;
    complexity sc;
    struct Node* next;
}Node;

complexity map_str_enum(char *str){
    if(strcmp(str, "one")==0) return one;
    if(strcmp(str, "nlogn")==0) return nlogn;
    if(strcmp(str, "nsquare")==0) return nsquare;
    if(strcmp(str, "ncube")==0) return ncube;
    if(strcmp(str, "factorial")==0) return factorial;
    if(strcmp(str, "logn")==0) return logn;
    return n;
}

Node* create_node(char *tc, char *sc){
    Node *node = (Node *)malloc(sizeof(Node));
    node->tc = map_str_enum(tc);
    node->sc = map_str_enum(sc);
    node->next = NULL;
    return node;
}

void insert_at_end(Node **head, char *tc, char *sc){
    Node *ptr = *head;
    if(!ptr){
        *head = create_node(tc, sc);
        return;
    }

    while(ptr->next) ptr = ptr->next;

    ptr->next = create_node(tc, sc);
    return;
}

void insert(Node **head){
    int n;
    scanf("%d", &n);
    while(n--){
        char *tc = (char *)malloc(20*sizeof(char));
        char *sc = (char *)malloc(20*sizeof(char));

        scanf("%s", tc);
        scanf("%s", sc);

        insert_at_end(head, tc, sc);
    }

    return;
}

Node * find_mid(Node *head){
    Node *slow = head;
    Node *fast = head->next;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *merge_parts(Node *head1, Node *head2){
    Node *final;
    if(head1->tc <= head2->tc){
        final = head1;
        head1 = head1->next;
    }else{
        final = head2;
        head2 = head2->next;
    }
    Node *ptr = final;
    while(head1 && head2){
        if(head1->tc <= head2->tc){
            ptr->next = head1;
            head1 = head1->next;
        }else{
            ptr->next = head2;
            head2 = head2->next;
        }
        ptr = ptr->next;
    }

    if(head1)ptr->next = head1;
    if(head2)ptr->next = head2;

    return final;
}

Node* sort_(Node *head){
    if(!head || !head->next) return head;

    Node *mid = find_mid(head);
    Node *head2 = mid->next;
    mid->next = NULL;

    Node *first_part = sort_(head);
    Node *second_part = sort_(head2);

    Node *final_head = merge_parts(first_part, second_part);

    return final_head;
}

void sort(Node **head){
    *head = sort_(*head);
    return;
}

void display(Node *head){
    Node *ptr = head;
    while(ptr){
        printf("%d  %d \n", ptr->tc, ptr->sc);
        ptr = ptr->next;
    }
    return;
}
int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    insert(&head);
    sort(&head); 
    display(head);
}