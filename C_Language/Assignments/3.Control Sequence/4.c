/*
Develop a C program to find factorial of a number N using for loop.
*/

#include<stdio.h>
int main(){
        int n;double x=1;
        printf("enter any number:\n");
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            x*=i;
        }
        printf("factorial of the given number is:%.1lf\n",x);
}