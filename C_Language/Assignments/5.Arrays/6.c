/*Program to find the largest, smallest, second largest and second smallest element of an array*/

#include<stdio.h>
int main(){
    int ar[]={5,3,45,563,12,7},temp=0;
    int l=sizeof(ar)/sizeof(ar[0]);
    printf("no.of elements:%d\n",l);
    for(int i=0; i<l; i++)
	{
		for(int j=0; j<l; j++){
			if(ar[i]<=ar[j])
			{
			temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
			}
		}
	}
    // printf("elements after sorting:\n");
    // for(int i=0; i<l; i++){
	// printf("%d ", ar[i]);
	// }
    printf("smallest element is:%d\n",ar[0]);
    printf("second smallest element is:%d\n",ar[1]);
    printf("largest element is:%d\n",ar[l-1]);
    printf("second largest element is:%d\n",ar[l-2]);
}