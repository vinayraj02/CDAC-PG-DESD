/*
Develop a C program to perform operations (+,*,-, / and %) on two whole numbers. Identify
suitable data types to represent the numbers and resultant values
*/




#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter the first whole number: ");
    scanf("%d", &num1);
    printf("Enter the second whole number: ");
    scanf("%d", &num2);
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    
    // Check for division by zero before performing the division
    if (num2 != 0) {
        int quotient = num1 / num2;
        int remainder = num1 % num2;

        printf("Sum: %d\n", sum);
        printf("Difference: %d\n", difference);
        printf("Product: %d\n", product);
        printf("Quotient: %d\n", quotient);
        printf("Remainder: %d\n", remainder);
    } else {
        printf("Cannot perform division and modulus operations as the second number is zero.\n");
    }

    return 0;
}





/*


#include<stdio.h>
int main(){
        printf("enter the case:\n1.ADD\n2.SUB\n3.MUL\n4.DIV\n");
        int n,a,b;
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("enter two numbers to be added\n");
                scanf("%d%d",&a,&b);
                printf("add:%d",a+b);
                break;
            case 2:
                printf("enter two numbers to be sub\n");
                scanf("%d%d",&a,&b);
                printf("sub:%d",a-b);
                break;
            case 3:
                printf("enter two numbers to be mul\n");
                scanf("%d%d",&a,&b);
                printf("mul:%d",a*b);
                break;
            case 4:
                printf("enter two numbers to be div\n");
                scanf("%d%d",&a,&b);
                printf("div:%d",a/b);
                break;
        }
    return 0;
}


*/