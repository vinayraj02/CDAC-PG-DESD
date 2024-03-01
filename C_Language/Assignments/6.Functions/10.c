/*Write a C program with two functions itob (n, s) and itoh (n, s). itob converts integer into
binary character representation in s. Similarly itoh converts integer into hexadecimal
character representation in s.*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int length = strlen(s);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[]) {
    int i = 0;

    do {
        s[i++] = n % 2 + '0';
    } while ((n /= 2) > 0);

    s[i] = '\0';

    reverse(s);
}

void itoh(int n, char s[]) {
    int i = 0;
    char hexDigits[] = "0123456789ABCDEF";

    do {
        s[i++] = hexDigits[n % 16];
    } while ((n /= 16) > 0);

    s[i] = '\0';

    reverse(s);
}

int main() {
    int number; 
    printf("enter any number:\n");
    scanf("%d",&number);
    char binary[100], hex[100];

    itob(number, binary);
    itoh(number, hex);

    printf("Binary: %s\n", binary);
    printf("Hexadecimal: %s\n", hex);

    return 0;
}
