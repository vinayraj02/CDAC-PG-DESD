/*Write a program to read your name into a character array. Print the name along with the
length of your name and sizeof the array in which name is stored.*/

#include<stdio.h>
#include<string.h>
int main(){
    char a[30];
    printf("enter your name:\n");
    scanf("%s",a);

    int b=sizeof(a);
    int c=strlen(a);
    printf("name:%s\n",a);
    printf("length of name:%d\n",c);
    printf("size of array:%d\n",b);

}