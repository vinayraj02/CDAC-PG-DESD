/*
Write a program to perform operations on complex numbers
*/

#include<stdio.h>
int main(){
        struct complex
        {
            int a;
            int b;
        }c1,c2;

        c1.a=2;
        c1.b=3;

        c2.a=4;
        c2.b=6;

        printf("complex number add: %d+i%d\n",(c1.a+c2.a),(c1.b+c2.b));
        printf("complex number sub: %d+i(%d)\n",(c1.a-c2.a),(c1.b-c2.b));
        printf("complex number mul: %d+i%d\n",(c1.a*c2.a),(c1.b*c2.b));
        printf("complex number div: %d+i%d\n",(c1.a/c2.a),(c1.b/c2.b));

        
}