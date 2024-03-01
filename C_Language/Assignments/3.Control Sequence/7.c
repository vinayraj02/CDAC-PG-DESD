/*
Write a Program to find if a given number is Armstrong number.
Hint: (153 = 1^3 + 5^3 + 3^3)
*/

#include <stdio.h>
#include<math.h>


int main()
{
    int a, n, sum = 0,count=0;
    printf("enter any number:\n");
    scanf("%d", &a);
    
    for(int i=a;i>0;i/=10){
        count++;
    }
    for (int j=a ; j > 0;j=j/10 )
    {
        n = j % 10;
        
        sum = sum + pow(n,count) ;

        
    }
    if(a==sum){
         printf("%d\n", sum);
    }
    else{
        printf("entered number is not a amstrong number\n");
    }
   
}