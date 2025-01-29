#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node{
    char *str;
    struct Node* next;
}Node;

Node* create_node(char *str){
    Node *node = (Node*)malloc(sizeof(Node));
    node->str = (char *)malloc(15*sizeof(char));
    node->str = str;
    node->next = NULL;

    return node;
}

Node * insert_at_end(Node *head, char *str){
    if(!head){
        head = create_node(str);
        return head;
    }

    Node *ptr = head;
    while(ptr->next) ptr = ptr->next;

    ptr->next = create_node(str);

    return head;
}

void display(Node *head){
    Node *ptr= head;

    while(ptr){
        printf("%s --> ", ptr->str);
        ptr = ptr->next;
    }

    return;
}

int str_cmp(char *first, char *second){
    char *ptr = first;
    char *ptr2 = second;

    while(*ptr!='\0' && *ptr2!='\0' ){
        if(*ptr < *ptr2) return 0;
        else if(*ptr>*ptr2) return 1;

        ptr+=1;
        ptr2+=1;
    }
    if(*ptr=='\0') return 0;
    if(*ptr2=='\0') return 1;

    return 0;
}

void sort_linked_list(Node *head, int size){
    if(!head) return;

    Node *ptr = head;
    for(int i=0;i<size;i++){
        int count = size-i-1;
        ptr = head;

        while(count--){
            if(str_cmp(ptr->str, ptr->next->str)){
                char *temp = ptr->str;
                ptr->str = ptr->next->str;
                ptr->next->str = temp;
            }
            ptr = ptr->next;
        }

    }
}

void take_input(){
    Node *head = (Node*)malloc(sizeof(Node));
    head = NULL;

    char *input = (char *)malloc(1000*sizeof(char));

    scanf("%[^\n]s", input);
    char *sp = input;
    int size = strlen(input);
    char *end_pointer = input + (size-1);
    int s=0;
    printf("Enter strings separated by spaces as input to linked list nodes (Enter for temination) : ");
    while(input <= end_pointer ){
        while(*input==' ' && input<=end_pointer)input++;

        if(input>end_pointer)break;

        sp = input;

        while(*input != ' ' && *input != '\0')input++;
        *input='\0';

        head = insert_at_end(head, sp);
        s++;
        input++;
    }


    printf("\nlinked list before sorting is : ");
    display(head);

    sort_linked_list(head, s);
    printf("\nlinked list after sorting is : ");
    display(head);

    return;

}

int main(){

    take_input();
    return 0;

}
