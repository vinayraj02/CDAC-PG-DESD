/*Write a function to get the transpose of a matrix.*/

#include<stdio.h>

void trans(int mat[3][3])
{
    int re[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            re[j][i]=mat[i][j];
        }
    }
    printf("matrix after transpose is:\n");
   
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",re[i][j]);
        }
        printf("\n");
    }

}
int main(){
    int mat[3][3];
    printf("enter the values of 3X3 matrix:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&mat[i][j]);
        }
        printf("\n");
    }

    printf("matrix is:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    trans(mat);


}