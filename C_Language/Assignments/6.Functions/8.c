/*Develop a program to calculate nPr and nCr given n and r.*/

#include<stdio.h>

int pfact(int a){
    if(a==0){
        return 1;
    }
    else{
        return (a*pfact(a-1));
    }
}

int main(){
    int n,r,c;
    printf("enter the values of 'n' and 'r':\n");
    scanf("%d",&n);
    scanf("%d",&r);
    printf("enter your choice: \n1.permutation\n2.combinations\n");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        int x=pfact(n)/pfact(n-r);
        printf("permutations of given data is:%d\n",x);
        break;
    case 2:
        int y=pfact(n)/pfact(r)*pfact(n-r);
        printf("combinations of given data is:%d\n",y);
        break;
    
    default:
        printf("enter either 1 or 2\n");
        break;
    }
    
}