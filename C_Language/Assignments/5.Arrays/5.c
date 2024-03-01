/*Program to Calculate Sum and Average of an array*/

#include<stdio.h>
int main(){
    float sum=0,avg=0;
    int ar[]={1,2,3,4,5};
     int l=sizeof(ar)/sizeof(ar[0]);
    for(int i=0;i<l;i++){

        sum=sum+ar[i];
        
    }
    avg=sum/l;
    printf("sum is:%.2f\n",sum);
    printf("average is:%.2f\n",avg);
}