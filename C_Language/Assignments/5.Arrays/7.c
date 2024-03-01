/*Program to copy an array to another array in same order & in reverse order*/

#include<stdio.h>
int main(){
    int l,ar[]={54,56,74,14,765,34};
    l=sizeof(ar)/sizeof(ar[0]);
    int br[l];
    for(int i=0;i<l;i++){
        br[i]=ar[i];
    }
    printf("copied elements are:\n");
    for(int i=0;i<l;i++){
    printf("%d ",br[i]);
    }

    printf("\nreverse array is:\n");
    for(int i=l-1;i>=0;i--){
        printf("%d ",br[i]);
    }
}