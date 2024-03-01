/*Write a menu based C program to perform operations (+, - and *) on matrices.*/

#include<stdio.h>
int main(){
        int row,col,o;
        int mat1[100][100],mat2[100][100],result[100][100];
        printf("enter the number of rows in a matrice :\n");
        scanf("%d",&row);
        printf("enter the number of columns in a matrice :\n");
        scanf("%d",&col);

        //taking the elements from the user
        printf("enter the elements of the mtrix 1:\n");
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                scanf("%d",&mat1[i][j]);
            }
        }

        printf("enter the elements of the mtrix 2:\n");
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                scanf("%d",&mat2[i][j]);
            }
        }

        printf("enter the options\n1.ADD\n2.SUB\n3.MUL\n");
        scanf("%d",&o);
        switch (o)
        {
        case 1:
                    for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    result[i][j]=mat1[i][j]+mat2[i][j];
                }
            }

                printf("add of two matrix:\n");
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                printf("%d\t", result[i][j]);
            }
            printf("\n");
            }
            break;

        case 2:
                    for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    result[i][j]=mat1[i][j]-mat2[i][j];
                }
            }


            printf("sub of two matrix:\n");
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                printf("%d\t", result[i][j]);
            }
            printf("\n");
            }
            break;
        
        case 3:
                for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    result[i][j]=mat1[i][j] * mat2[i][j];
                }
            }

            printf("mul of two matrix:\n");
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                printf("%d\t", result[i][j]);
            }
            printf("\n");
            }
            break;
        
        default:
                printf("enter the valid option\n");
            break;
        }
}