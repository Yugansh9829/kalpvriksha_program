#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    int value;
    struct Node *next;
}Node;

Node *create_Node(int key, int value){
    Node *node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->key = key;
    node->value = value;
}

Node *insert_at_end(Node *head, int key, int value){
    if(!head){
        head = create_Node(key, value);
        return head;
    }

    Node *ptr = head;
    while(ptr->next)ptr = ptr->next;

    ptr->next = create_Node(key, value);
    return head;
}
Node *hash_map[10] = {NULL};

int hash_function(int key){
    return key%10;
}

int exists(int idx, int key, int value){
    Node *ptr = hash_map[idx];

    while(ptr){
        if(ptr->key == key){
            ptr->value = value;
            return 1;
        }
        ptr = ptr->next;
    }

    return 0;
}

void insert_in_hashmap(int key, int value){
    int idx = hash_function(key);
    if(exists(idx, key, value)){
        return ;
    }
    hash_map[idx] = insert_at_end(hash_map[idx], key, value);
    return;
}

int search(int key){
    int idx = hash_function(key);

    Node *ptr = hash_map[idx];
    while(ptr){
        if(ptr->key == key){
            return ptr->value;
        }
        ptr = ptr->next;
    }

    return -1;
}

void display(){
    for(int i=0;i<10;i++){
        printf("%d : ", i);
        Node *ptr = hash_map[i];
        while(ptr){
            printf("(%d, %d) --> ", ptr->key, ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return;
}

void delete_from_hash_map(int key){
    int idx = hash_function(key);

    if(!hash_map[idx]) return;

    Node *ptr = hash_map[idx];
    if(hash_map[idx]->key == key){
        if(hash_map[idx]->next) hash_map[idx] = hash_map[idx]->next;
        else hash_map[idx] = NULL;
        return;
    }

    ptr = hash_map[idx];
    while(ptr && ptr->next){
        if(ptr->next->key == key){
            ptr->next = ptr->next->next;
            return;
        }
        ptr = ptr->next;
    }
    return;
}

int main(){

    int count;
    printf("Enter number of operations to perform : ");
    scanf("%d", &count);


    while(count--){
        int oper;
        printf("Enter operation to perform : ");
        scanf("%d", &oper);
        if(oper==1){
            int key;
            int value;
            printf("Enter key and value to take add in hash map : ");
            scanf("%d%d", &key, &value);
            insert_in_hashmap(key, value);
        }else if(oper==2){
            int key;
            printf("Enter key to search : ");
            scanf("%d", &key);
            int value = search(key);
            printf("value is : %d", value);
        }else if(oper==3){
            int key;
            printf("ENter key to delete : ");
            scanf("%d", &key);
            delete_from_hash_map(key);
        }
        else if(oper==4){
            display();
        }
    }
}
