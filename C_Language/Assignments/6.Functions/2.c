/*Write a recursive function to find the factorial of a number.*/
#include<stdio.h>
int fact(int a){
    if(a==0){
        return 1;
    }
    else{
        return (a*fact(a-1));
    }
}
int main(){
    int n;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    printf("The factorial of given number is:%d\n",fact(n));
}