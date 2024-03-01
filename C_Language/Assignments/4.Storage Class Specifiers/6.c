/*Write a program to demonstrate difference between global variables vs local variables and
in which section they are stored.*/


#include <stdio.h>

// Global variable
int globalVariable = 10;

void functionWithLocalVariable() {
    // Local variable
    int localVariable = 5;

    // Accessing global and local variables
    printf("Global variable inside function: %d\n", globalVariable);
    printf("Local variable inside function: %d\n", localVariable);
}

int main() {
    // Accessing global variable
    printf("Global variable in main function: %d\n", globalVariable);

    // Calling a function with local variable
    functionWithLocalVariable();

    // Attempting to access the local variable from the main function will result in an error
    // Uncommenting the line below will cause a compilation error
    // printf("Trying to access local variable from main: %d\n", localVariable);

    return 0;
}
