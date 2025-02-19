#include<stdio.h>
#include<stdlib.h>

typedef struct class{
    char *task;
    int freq;
}class;

class* arr[1000];
int counter = 0;

void take_task_input(char *input, char *task){
    while(*input!=' ')input++;
    input+=1;

    int idx = 0;

    while(*input!='"'){
        task[idx++] = *input;
        input++;
    }

    task[idx] = '\0';

    return;
}

void take_input(){
    while(1){
        char *oper = (char *)malloc(100*sizeof(char));
        if(*(oper+1)=='A'){
            char *task = (char *)malloc(100*sizeof(char));
            take_task_input(oper, task);
            add_task(task);
        }else if(*(oper+1)=='C'){
            char *task = (char *)malloc(100*sizeof(char));
            mark_completed(task);
        }else if(*(oper+1)=='P'){
            display_all_pending_tasks();
        }else if(*(oper)=='e'){
            break;
        }
        else{
            printf("enter valid operation\n");
        }
    }
}

int main(){

    take_input();



    return 0;
}