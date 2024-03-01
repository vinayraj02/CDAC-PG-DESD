/*Write a C program with a function ​tolower​, which converts upper case letters to lower case.
Use conditional expression.*/

#include<stdio.h>

int lower(char a)
{
    return ((a>=65 && a<=90)?(a+32):0);  //using conditional operator
}

int main(){
    char n;
    printf("enter any upper case letter:\n");
    scanf("%c",&n);
    printf("lower case of %c is:%c\n",n,lower(n));   
}