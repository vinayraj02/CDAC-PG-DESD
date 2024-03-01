/*
Develop a C program to find the sum of all odd numbers upto N using a while loop.
*/

#include<stdio.h>
int main(){
    int i=1,a,n=0;
    printf("enter the number:\n");
    scanf("%d",&a);
    while (i<=a)
    {
        if(i%2!=0){
            n+=i;
        }
        
        i++;
        
    }
    printf("sum of all odd numbers upto N:%d\n",n);
}