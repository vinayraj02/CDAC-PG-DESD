/*
Develop a C program to calculate simple interest using the formula I=PTR/100. Display
Interest with two digit precision after decimal point
*/

#include<stdio.h>
int main(){
        float i,r;
        int p,t;
        printf("enter the principle\n1.amount\n2.tenure\n3.rate\n");
        scanf("%d%d%f",&p,&t,&r);
        i=(p*t*r)/100;
        printf("simple intrest:%.2f\n",i);
}