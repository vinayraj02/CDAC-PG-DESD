#include<stdio.h>

void bubblesort(int a[], int size);
int main()
{
	int a[200],size, i;
	printf("Enter the size of array  :");
	scanf("%d", &size);
	printf("Enter %d elements :", size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before Sorting  : ");
        for(i=0;i<size;i++)
        {
                printf("%d\t",a[i]);
        }
	bubblesort(a,size);
	printf("\nAfter Sorting   : ");
        for(i=0;i<size;i++)
        {
                printf("%d\t",a[i]);
        }
                printf("\n");
        return 0;
}

void bubblesort(int a[], int size)
{
	int i, j,temp;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
