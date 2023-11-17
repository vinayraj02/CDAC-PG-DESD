#include <stdio.h>
int main ()
{
   FILE *fp; 
   char str[60];
   fp = fopen("file.txt", "w+"); 
   fputs("This is c programming.\n", fp);
   fputs("This is a system programming language.", fp); 
//after this fp points to the end of th file
   rewind(fp); //fp points to the beginning of the file
   //Reading contents from file.txt
   while(1)
{
        if( (fgets(str, 60, fp)) == NULL)
        {
        //      printf("Error in reading\n");
                break;
        }
        else
                //printf("%s\n", str);
                //for priting on the console
     		fputs(str, stdout);
}
   fclose(fp);

   return(0);
}
