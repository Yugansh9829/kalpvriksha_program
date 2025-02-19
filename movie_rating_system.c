#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct class{
    char *movie;
    int ratings;
}class;

typedef struct Node{
    char *movie;
    int ratings;
    struct Node *next;
}Node;

Node * create_node(char * movie, int rating){
    Node *node = (Node *)malloc(sizeof(Node));
    node->ratings = rating;
    node->movie = movie;
    node->next = NULL;
    return node;
}

Node* insert_at_end(Node *head, char *movie, int rating){
    if(!head){
        head = create_node(movie, rating);
        return head;
    }

    Node *ptr = head;
    while(ptr->next) ptr = ptr->next;
    ptr->next = create_node(movie, rating);

    return head;
}

void fetch_movie_ratings(char *input, char *movie, int *ratings){
    while(*input!=' ')input++;
    input+=1;

    int idx = 0;
    while(*input!=' '){
        movie[idx++] = *input;
        input++;
    }

    movie[idx]= '\0';
    input+=1;
    int number = 0;

    while(*input!='"'){
        number = ((number*10) + (*input - '0'));
        input++;
    }

    *ratings = number;

    return;
}

void fetch_movie(char *input, char *movie){
    while(*input != ' ')input++;
    input+=1;
    int idx = 0;
    while(*input!='"'){
        movie[idx++] = *input;
        input++;
    }

    movie[idx] = '\0';
    return;
}

Node* remove_movie(Node *head, char *movie){
    if(!head){
        printf("No movies in system\n");
        return head;
    }

    Node *ptr = head;
    if(strcmp(ptr->movie, movie)==0){
        head = head->next;
        return head;
    }

    while(ptr->next){
        if(strcmp(ptr->next->movie, movie)==0){
            printf("Founded %s \n", ptr->next->movie);
            ptr->next = ptr->next->next;
            return head;
        }
        ptr = ptr->next;
    }

    return head;
}

void print(Node *head){
    Node *ptr = head;
    while(ptr){
        printf("movie : %s and rating : %d \n", ptr->movie, ptr->ratings);
        ptr = ptr->next;
    }
    return;
}

int cal_size(Node *head){
    Node *ptr = head;
    int size = 0;
    while(ptr){
        ptr = ptr->next;
        size++;
    }

    return size;
}

void swap(Node *first, Node *second){
    int temp_ratings = first->ratings;
    first->ratings = second->ratings;
    second->ratings = temp_ratings;

    char * temp_movie = first->movie;
    first->movie = second->movie;
    second->movie = temp_movie;

    return;
}

Node* bubble_sort(Node *head){
    int size = cal_size(head);

    for(int i=0;i<size;i++){
        Node *ptr = head;

        int count = size-i-1;
        while(count-- && ptr &&  ptr->next){
            if(ptr->ratings < ptr->next->ratings){
                swap(ptr, ptr->next);
            }
            ptr = ptr->next;
        }
    }

    return head;
}

void take_input(){
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    while(1){
        char *oper = (char *)malloc(100*sizeof(char));
        scanf("%[^\n]s", oper);
        getchar();
        if(*(oper+2)=='A'){
            char *movie = (char *)malloc(100*sizeof(char));
            int ratings = 0;

            fetch_movie_ratings(oper, movie, &ratings);
            head = insert_at_end(head, movie, ratings);
            printf("inserted %s and %d \n", head->movie, head->ratings);

        }else if(*(oper+2)=='E'){
            char *movie = (char *)malloc(100*sizeof(char));
            fetch_movie(oper, movie);
            head = remove_movie(head, movie);
        }else if(*(oper+1)=='T'){
            head = bubble_sort(head);
            printf("movie is : %s and rating is : %d \n", head->movie, head->ratings);
        }else{
            print(head);
        }
    }
}

int main(){
    take_input();
}