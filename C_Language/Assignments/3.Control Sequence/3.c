/*
Develop a C program which adds all numbers from 1 to N, except those which are divisible
by 5. Implement this using for loop and continue statement.
*/

#include<stdio.h>

int main(){
    int n,c=0;
    printf("enter the n number:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%5==0){
            continue;
        }
        c+=i;
    }
    printf("%d\n",c);
}


