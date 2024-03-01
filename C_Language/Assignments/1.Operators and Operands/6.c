/*Write a program to find whether the given processor is little endian or big endian.*/

#include <stdio.h>

int main() {
    unsigned int x = 1;
    char *c = (char*)&x;
    
    if (*c) 
    {
        printf("The processor is little endian.\n");
    } 
    else 
    {
        printf("The processor is big endian.\n");
    }
    
    return 0;
}
