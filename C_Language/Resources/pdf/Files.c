#include <stdio.h>
#include <stdlib.h>

int main()
{
        FILE * fp;
        int k;
        char ch;
        char ch1;
        //writing A to Z into sample.txt file
        fp=fopen("sample.txt", "w");
        for(k=65; k<=90;k++)
        {
         fprintf(fp, "%c", k); // writing to sample.txt
         }
         fclose(fp); //closing sample.txt
         //Again opening the sample.txt for reading the contents present in the file
         /*fp = fopen("sample.txt", "r");
         printf("Content read from sample.txt is");
         while(!feof(fp))
         {
         ch1=fgetc(fp);
         printf("%c", ch1);
         }
         //using fseek function printing 5 th character of the sample.txt file
         fseek(fp, 4, SEEK_SET);
         fscanf(fp, "%c", &ch);         
         printf("\nUisng fseek function printing the 5th character from sample.txt file: %c", ch);
         //printing the position of fp
         printf("\nprinting the position of fp:%ld", ftell(fp));
         //Uisng fseek function printing the last character from sample.txt file
         fseek(fp, -1, SEEK_END);
         fscanf(fp, "%c", &ch); 
         printf("\nUisng fseek function printing the last character from sample.txt file: %c", ch);
         */
         
        return 0;
        }
