/*Program to print array in reverse order*/

#include<stdio.h>
#include<string.h>
int main(){
    int ar[]={1,2,3,4,5};
    int l=sizeof(ar)/sizeof(ar[0]); //sizeof gives the total size of int so, if we divide with int the it will be correct
    printf("len:%d\n",l);
    printf("reverse array is:\n");
    for(int i=l-1;i>=0;i--){
        printf("%d ",ar[i]);
    }

}