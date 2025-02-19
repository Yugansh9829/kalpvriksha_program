#include<stdio.h>
#include<stdlib.h>

void transpose(int row, int col, int arr[row][col]){
    for(int i=0;i<row;i++){
        for(int j=0;j<i;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    return;
}

void print(int row, int col, int arr[row][col]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void rotate(int row, int col, int arr[row][col]){
    transpose(row, col, arr);

    for(int i=0;i<row;i++){
        for(int j=0;j<(col/2);j++){
            int temp = arr[i][j];
            arr[i][j] = arr[i][col-j-1];
            arr[i][col-j-1] = temp;
        }
    }

    print(row, col, arr);
}

int main(){
    int row,col;
    scanf("%d%d", &row, &col);
    int arr[row][col];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    rotate(row, col, arr);

    return 0;
}