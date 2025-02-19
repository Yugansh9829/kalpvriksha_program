#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void sort_arr(char *arr[], int size){
    for(int i=0;i<size;i++){
        for(int j=i;j<(size-i-1);j++){
            if(strcmp(arr[j], arr[j+1])>0){
                char *temp = arr[j];
                arr[j]  = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}

void sort(int row, int col, char * arr[row][col]){
    for(int i=0;i<row;i++) sort_arr(arr[i], col);
}


int main(){

    int row, col;
    scanf("%d%d", &row, &col);
    
    char *arr[row][col];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            char *str = (char *)malloc(100*sizeof(char));
            scanf("%s", str);
            arr[i][j] = str;
        }
    }

    printf("before sorting : \n");
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%s ", arr[i][j]);
        }
        printf("\n");
    }

    sort(row, col, arr);

    printf("after sorting : \n");

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%s ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}