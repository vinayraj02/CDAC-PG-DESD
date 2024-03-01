/*Write a C program with a function rotoate_right (n, b). This function rotates integer n
towards right by b positions.*/

//ans:
/*Here rotation of an integer is similar to the shift operation but here the bits that fall off at one end will put back 
at other end*/

#include<stdio.h>
int rr(int a,int b) //function for right rotation 
{
   /*here for r_r we need to shift the number to the right first and then do left shift next and then result of two shifting
   should be done with the bitwise or (|) operator*/
    return ((a>>b)|(a<<(32-b))); //here we are sub b from 32 cuz we need to shift the remaining bits after doing right shift
}
int rl(int a, int b)  //function for left rotation
{
    /*here for r_l we need to shift the number to the left first and then do right shift next and then result of two shifting
   should be done with the bitwise or (|) operator*/
    return ((a<<b) | (a>>(32-b))); //here we are sub b from 32 cuz we need to shift the remaining bits after doing left shift
}

int main(){
    int n,b;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    printf("enter how many postions to be rotated:\n");
    scanf("%d",&b);
    printf("rotate right is:%d\n",rr(n,b));
    printf("rotate left is:%d\n",rl(n,b));
}