/*Write a program to calculate n!/(n-r)! using functions.*/

#include<stdio.h>
int fact(int a){
    if(a==0){
        return 1;
    }
    else{
        return (a*fact(a-1)); //using recurrsion
    }
}
int main(){
    int n,r;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    printf("enter the value of r:\n");
    scanf("%d",&r);
    int c=fact(n)/fact(n-r);
    printf("The value of n!/(n-r)! is:%d\n",c);
}