#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct class{
    char *item;
    int quantity;
}class;

class *arr[1000];
int counter=0;

void fetch_item_quantity(char *input_string, char *item, int *quantity){
    while(*input_string!=' ')input_string++;
    input_string++;
    int idx = 0;
    int number = 0;
    while(*input_string != ' '){
        item[idx++] = *input_string;
        input_string++;
    }
    item[idx]='\0';
    input_string++;
    while(*input_string != '\0' && *input_string != '"'){
        number = ((number*10) + (*input_string-'0'));
        input_string++;
    }

    *quantity = number;

    return;
}

void fetch_item(char *input_string, char* item){
    while(*input_string!=' ')input_string++;
    input_string++;
    int idx = 0;

    while(*input_string != '\0' && *input_string!='"'){
        item[idx++] = *input_string;
        input_string++;
    }
    item[idx]='\0';
    return;
}

int exists(char *item){
    for(int i=0;i<counter;i++){
        if(strcmp(item, arr[i]->item)==0){
            return i;
        }
    }
    return -1;
}


void add_item(char *item, int quantity){
    int idx = exists(item);
    if(idx!=-1){
        arr[idx]->quantity += quantity;
    }else{
        class *obj = (class *)malloc(sizeof(class));
        obj->item = (char *)malloc(50*sizeof(char));
        obj->item = item;
        obj->quantity = quantity;
        arr[counter++] = obj;
    }
    
    return;
}

void update_item(char *item, int quantity){
    int idx = exists(item);
    if(idx==-1){
        printf("NO SUCH ITEM FOUND IN INVENTORY \n");
        return;
    }
    arr[idx]->quantity = quantity;
    return;
}

int query_item(char *item){
    int idx = exists(item);
    if(idx==-1) return 1e9;
    return arr[idx]->quantity;
}

void display(){
    for(int i=0;i<counter;i++){
        printf("item : %s , quantity : %d\n", arr[i]->item, arr[i]->quantity);
    }
}

void take_input(){
    int operations;

    scanf("%d", &operations);

    while(operations--){

        char *oper = (char *)malloc(50*sizeof(char));
        scanf("%[^\n]s", oper);
        getchar();
        if((*(oper+1))=='A'){
            char *item = (char *)malloc(10*sizeof(char ));
            int quantity = 0;
            fetch_item_quantity(oper, item, &quantity);
            add_item(item , quantity);

        }
        else if((*(oper+1))=='U'){

            char *item = (char *)malloc(10*sizeof(char ));
            int quantity = 0;
            fetch_item_quantity(oper, item, &quantity);
            update_item(item , quantity);

        }else if((*(oper+1))=='Q'){

            char *item = (char *)malloc(10*sizeof(char ));
            fetch_item(oper, item);
            int quantity = query_item(item);
            if(quantity==1e9){
                printf("Item not found\n");
            }else printf("quantity of item queried is : %d \n", quantity);

        }
        else{
            display();
        }
    }
}

int main(){

    take_input();

    return 0;
}