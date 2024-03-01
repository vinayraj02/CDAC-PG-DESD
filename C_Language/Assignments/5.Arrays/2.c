/*Use scanf function to read a string of characters (into character type array called text)
including alphabets, digits, blanks, tabs etc except new line character. Write a loop that will
examine each character in a character-type array and determine how many of the
characters are letters, how many are digits, how many are blanks and how many are tabs.
Assume that text contains 80 characters.*/

#include<stdio.h>
#include<string.h>
int main(){
    char buf[81];
    int l=0,d=0,s=0,t=0;
    printf("enter anything:\n");
    scanf("%s",buf);
    for(int i=0;i<80 && buf[i]!='\0';i++){
        if((buf[i]>=65 && buf[i]<=90) || (buf[i]>=97 && buf[i]<=122)) //for alphabets
        {
             l++;
        }

        if(buf[i]>=48 && buf[i]<=57)    // for digits
        {
            d++;
        }

        if(buf[i]==' ')  //for blank spaces
        {
            s++;

        }

        if(buf[i]=='    ')    //for tab spaces
        {
            t++;
        }

    }
    printf("number of letters:%d\n",l);
    printf("number of digits:%d\n",d);
    printf("number of blank spaces:%d\n",s);
    printf("number of tabs:%d\n",t);
}