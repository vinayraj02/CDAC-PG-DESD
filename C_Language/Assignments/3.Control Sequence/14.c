/*
Write a C program to generate two Relatively Prime numbers. Two integers are relatively
prime (or coprime) if there is no integer greater than one that divides them both (that is,
their greatest common divisor is one). For example, 12 and 13 are relatively prime, but 12
and 14 are not.
*/

#include <stdio.h>
int main()
{
    int n1, n2, i, gcd;

    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    for(i=1; i <= n1 && i <= n2; ++i)
    {
        // Checks if i is factor of both integers
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }

    printf("G.C.D of %d and %d is %d\n", n1, n2, gcd);
    if(gcd==1){
        printf("given numbers are relatively prime\n");
    }
    else{
        printf("given numbers are not relatively prime\n");
    }

    return 0;
}