/*Write a program to compute factorial and GCD using recursion.*/

#include<stdio.h>
int fact(int a){
    if(a==0){
        return 1;
    }
    else{
        return (a*fact(a-1));
    }
}

int gcd(int a,int b){
    int min=(a>b)?b:a;
    int x;
    while (1)
    {
        if(((a%min) == 0) && ((b%min) == 0)){
            x=min;
            break;
        }
        min--;
    }
    return x;
    
}

int main(){
    int n,a,b;
    printf("enter the values of 'n','a' and 'b':\n");
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);
    printf("factorial of 'n':%d is:%d\n",n,fact(n));
    printf("GCD of 'a':%d and 'b':%d is:%d\n",a,b,gcd(a,b));
}