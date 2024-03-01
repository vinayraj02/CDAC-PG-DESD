/*
Write a program to find whether the given number is palindrome or not.Palindrome is a
number that remains the same when its digits are reversed. Example 16461
*/

#include<stdio.h>
int main(){
    int a,rev=0;
    printf("enter any number:\n");
    scanf("%d",&a);
    for(int i=a;i>0;i/=10){
        int n=i%10;
        rev = rev*10+n;
    }
    if(a==rev){
        printf("given number is a palindrome\n");
    }
    else{
        printf("given number is not a palindrome\n");
    }
}