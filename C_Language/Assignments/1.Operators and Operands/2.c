/*
Develop a C program to add two operands and store the result in one of the operands using
addition assignment operator.
*/

#include<stdio.h>
int main(){
    int a,b;
    printf("enter the two numbers:\n");
    scanf("%d%d",&a,&b);
    a+=b;
    printf("add of two numbers:%d\n",a);
}