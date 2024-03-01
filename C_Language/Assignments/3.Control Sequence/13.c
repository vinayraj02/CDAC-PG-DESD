/*Write a program to find the sum of digits of a given number.*/

#include<stdio.h>
int main(){
    int a,sum=0;
    printf("enter any number:\n");
    scanf("%d",&a);
    for(int i=a;i>0;i/=10){
        int n=i%10;
        sum=sum+n;
    }
    printf("sum of digits of a given number is:%d\n",sum);
}