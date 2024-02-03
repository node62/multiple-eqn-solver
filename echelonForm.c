#include<stdio.h>

void show(int row, int col, float arr[][col]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%02.1f ", arr[i][j]==-0?0:arr[i][j]);
        }
        printf("\n");
    }   
}

void rowswap(int row, int col, float arr[][col], int row1, int row2){
    int temp;
    for(int i=0;i<col;i++){
        temp=arr[row1][i];
        arr[row1][i]=arr[row2][i];
        arr[row2][i]=temp;
    }
}

void rowdef(int row, int col, float arr[][col], float scalar, int row1, int row2){
    for(int i=0;i<col;i++){
        arr[row2][i]=(arr[row1][i]*scalar)-arr[row2][i];
    }
}

void line(int row, int col, float arr[][col], int lead){
    if(arr[lead][lead]==0){
        int key=0;
        for(int i=row-1;i>lead;i--){
            if(arr[i][lead]==0.0) continue;
            else{
                rowswap(row, col, arr, lead, i);
                key=1;
            }
        }
        if(key==0) lead++;
    }
    else{
        for(int i=lead+1;i<row;i++){
            float b=arr[i][lead]/arr[lead][lead];
            rowdef(row, col, arr, b, lead, i);
        }
    }
}

int main(){
    int row, col;
    printf("Enter row and columns: "); scanf("%d %d", &row, &col);
    float arr[row][col];
    printf("Enter the matrix: ");

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%f", &arr[i][j]);
        }
    }
    printf("\n");
    
    for(int i=0;i<row-1;i++){
        line(row, col, arr, i);
    }

    show(row, col , arr);
return 0;
}
