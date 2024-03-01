/*Write a program that reads a number that says how many ​integer numbers are to be stored
in an array, creates an array to fit the exact size of the data and then reads in that many
numbers into the array.*/

#include<stdio.h>
int main(){
    int a;
    printf("enter how many integer number to be stored:\n");
    scanf("%d",&a);
    int arr[a];
    printf("enter the %d values in the array\n",a);

    for(int j=0; j<a; j++)
	{
		scanf("%d", &arr[j]);
	}
    printf("entered values are:\n");
    for(int j=0; j<a; j++)
	{
		printf("%d",arr[j]);
	}


}