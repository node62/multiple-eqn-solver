#include<stdio.h>

void show(int row, int col, float arr[][col]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%02.1f ", arr[i][j]==-0?0:arr[i][j]);
        }
        printf("\n");
    }   
}


void rowmul(int row, int col, float arr[][col], float scalar, int rowx){
    for(int i=0;i<col;i++){
        arr[rowx][i]*=(1/scalar);
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
                line(row, col, arr, lead);
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

int rank(int row, int col, float arr[][col]){
    int rank=0;
    for(int i=row-1;i>=0;i--){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                rank++;
                break;
            }
    }}
    return rank;
}

void solve(int row, int col, float arr[][col], float var[]){
    int num=row;
    rowmul(row, col, arr, arr[row-1][row-1], row-1);
    var[--num]=arr[row-1][row];
    for(int i=row-2;i>=0;i--){
        rowmul(row, col, arr, arr[i][i], i);
        float temp=arr[i][row];
        for(int j=i+1;j<row;j++){
            temp=temp-arr[i][j]*var[j];
        }
        var[--num]=temp;
    }
}

int main(){
    int row, col;
    printf("Enter no of variables: "); scanf("%d", &row);
    col=row+1;
    float arr[row][col];
    printf("Enter the coefficients: \n");

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%c%d= ",j+97,i+1);
            scanf("%f", &arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    for(int i=0;i<row-1;i++){
        line(row, col, arr, i);
    }

    show(row, col , arr);
    printf("\n");
    //multiple equation solver
    float tempArray[row][row];
    for(int i=0; i<row;i++){
        for(int j=0;j<row;j++){
            tempArray[i][j]=arr[i][j];
        }
    }

    int rankArr=rank(row, col, arr);
    int rankTempArr=rank(row, row, tempArray);
    float var[row];
    
    if(rankArr!=rankTempArr){
        printf("Inconsistent equations");
        return 0;
    }
    else if(rankTempArr!=row){
        printf("Infinitely many solutions");
        return 0;
    }
    else{
        printf("Unique soln exists and it is,\n");
        solve(row, col, arr, var);
        for(int i=0;i<row;i++){
            printf("x%d= %.2f\n", i+1, var[i]);
        }
    }
return 0;
}

