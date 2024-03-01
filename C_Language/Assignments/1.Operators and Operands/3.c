/*
Write a C program to find the maximum of 2 numbers using Conditional operator.
*/

#include<stdio.h>
int main(){
    int a,b,c;
    printf("enter the two numbers:\n");
    scanf("%d%d",&a,&b);
    c = (a>b)?a:b; //conditional operator 
    printf("maximum of two numbers is:%d\n",c);
    return 0;
}