/*Generate the following pyramid of numbers using nested loops
            1
           212
          32123
         4321234
        543212345
*/

#include <stdio.h>
int main()
{
    int n = 5, i, j, k, l;
    for (i = 1; i <= n; i++)  //for the number of lines in the pyramid
    {
        for (j = i; j <= n - 1; j++) // loop for spaces 
        {
            printf(" ");
        }
        int p = i;
        for (k = 1; k <= i; k++)  //loop for 2nd part as to print the numbers for left side as given in the qus
        {
            printf("%d", p--);
        }
        p = p + 2;
        for (l = 1; l <= i - 1; l++)  //loop for 3rd part as to print the numbers for right side as given in the qus
        {
            printf("%d", p++);
        }
        printf("\n");
    }
}