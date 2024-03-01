/*Write a function to swap contents of two variables using functions and pointer variables.*/

#include<stdio.h>
//this can be done by using call by reference
/*the below function won't return any values to the main function but it performs operations on the variable addresses that 
we are passed to the function */
void swap(char *a,char *b)  //here we are passing pointer variables 
{
    char temp;
    temp=*a;    //here we are telling to go into the location and perform the operation
    *a=*b;
    *b=temp;
}

int main(){
    char x,y;
    printf("enter the two characters:\n");
    scanf("%c%c",&x,&y);
    printf("before swap x is:%c and y is:%c\n",x,y);
    swap(&x,&y);  //we are passing addresses of the variables
    printf("after swaping x is:%c and y is:%c",x,y);
}