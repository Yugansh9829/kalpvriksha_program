#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char *string;
    struct Node *next;
}Node;

Node* create_node(char *str){
    Node *node = (Node *)malloc(sizeof(Node));
    node->string = str;
    node->next = NULL;
    return node;
}

void insert_at_end(Node **head, char *str){
    Node *ptr = *head;

    if(!ptr){
        *head = create_node(str);
        return;
    }
    
    while(ptr->next) ptr = ptr->next;

    ptr->next = create_node(str);
    return;
}

int count_str(Node **head){
    Node *ptr = *head;
    int size = 0;
    while(ptr){
        ptr = ptr->next;
        size++;
    }

    return size;
}

int str_cmp(char *first , char *second){
    while(*first != '\0' && *second != '\0'){
        if(*second < *first)return 1;
        second++;first++;
    }

    if(*first != '\0') return 0;    
    if(*second != '\0') return 1;

    return 0;
}

void print(Node *head){
    Node *ptr = head;
    while(ptr){
        printf("%s  -> ", ptr->string);
        ptr = ptr->next;
    }

    return;
}

void sort_ll_lexiographically(Node **head){
    int size = count_str(head);
    Node *ptr = *head;

    for(int i=0;i<size;i++){
        ptr = *head;
        int count = size-i-1;
        while(count-- && ptr && ptr->next){
            // printf("comparing %s with %s \n", ptr->string, ptr->next->string);
            if(str_cmp(ptr->string, ptr->next->string)){
                char *temp = ptr->string;
                ptr->string = ptr->next->string;
                ptr->next->string = temp;
            }
            ptr = ptr->next;
        }
    }

    print(*head);
}


int main(){

    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;

    int n;
    scanf("%d", &n);

    while(n--){
        char *str = (char *)malloc(50*sizeof(char));
        scanf("%s", str);
        insert_at_end(&head, str);
    }

    sort_ll_lexiographically(&head);


    return 0;
}