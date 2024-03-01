/*
Develop a C program which accepts character type data items from users. In case if user
typed
‘A’ or ‘a’, it should display ​A for Apple
‘B’ or ‘b’, it should display ​B for Bat
‘D’ or ‘d’, it should display ​D for Dog
‘F’ or ‘f’, it should display ​F for Fan
Instead of the above 4 characters, if a user types any other character, it should display
“​Character ​is not in the range”. ​Implement this using if-else statement ​and switch
statement.
*/

#include<stdio.h>
int main(){
    //using if-else
    char x;
    printf("enter the alphabet 'a' or 'b' or 'd' or 'f'\n");
    scanf("%c",&x);


    if(x== 'A' || x=='a'){
        printf("A for Apple\n");
    }
    else if(x=='B' || x== 'b')
    {
        printf("B for BAt\n");
    }
    else if (x== 'D'|| x=='d')
    {
        printf("D for Dog\n");
    }
    else if(x=='F'|| x=='f'){
        printf("F for Fan\n");
    }
    else{
        printf("Character is not in the range\n");
    }


    //using switch case

    switch(x){
        case 'a':
                printf("A for Apple\n");
                break;
        case 'A':
            printf("A for Apple\n");
                break;
        case 'b':
            printf("B for BAt\n");
                break;
        case 'B':
            printf("B for BAt\n");
                break;
       case 'd':
            printf("D for Dog\n");
            break;
        case 'D':
            printf("D for Dog\n");
            break;
        case 'f':
            printf("F for Fan\n");
            break;
        case 'F':
            printf("F for Fan\n");
            break;

        default:
             printf("Character is not in the range\n");
            break;
    }
    

    
    
}