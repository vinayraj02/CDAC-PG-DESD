/*Write a program to print all the prime numbers in the first N numbers.*/

#include <stdio.h>

int main()
{
    int num, i, j;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 2; i <= num; i++)
    {
        int count = 0;
        for (j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }

        if (count == 2)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}