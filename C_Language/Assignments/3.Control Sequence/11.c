/*Write a program to search for an element in a given list of elements. Use break statement.*/

#include<stdio.h>
int main(){
        int n,ar[10]={1,2,3,4,5,6,7,8,9,10};
        printf("enter any number\n");
        scanf("%d",&n);
        int found =0;
        for(int i=0;i<10;i++){
            if(n==ar[i]){
                printf("element found\n");
                found =1;
               break; 
            }              
        }
        if(found ==0){
            printf("element not found\n");
        }
        
}