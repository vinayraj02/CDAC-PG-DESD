/*
Write a menu based C program to perform operations (+, - and *) on matrices.
*/

#include<stdio.h>
int main(){
        int row,col;
        int mat1[100][100],mat2[100][100],result[100][100];
        printf("enter the number of rows in a matrice :\n");
        scanf("%d",&row);
        printf("enter the number of columns in a matrice :\n");
        scanf("%d",&col);

        // printf("enter the number of rows in a matrice 2:\n");
        // scanf("%d",&rowb);
        // printf("enter the number of columns in a matrice 2:\n");
        // scanf("%d",&colb);

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

        //matrix addition
        
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

        //matrix sub
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

        //mul of two matrix 
        
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



}
    

