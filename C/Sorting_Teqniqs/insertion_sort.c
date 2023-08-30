#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int x=a[i];
        int j=i-1;
        while(j>-1 && a[j]>x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}


int main()
{
    int test[]={50,20,10,40,30};
    for(int i=0;i<5;i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    insertion_sort(test,5);
    for(int i=0;i<5;i++)
    {
        printf("%d ",test[i]);
    }
}