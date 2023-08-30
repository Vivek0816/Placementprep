#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l;
    int j=h;
    do
    {do
    {
        i++;
    } while (a[i]<=pivot);
    do
    {
        j--;
    } while (a[j]>pivot);
    if(i<j){
    int temp=a[j];
    a[j]=a[i];
    a[i]=temp;

    }

    } while (i<j);
    int temp2=a[l];
    a[l]=a[j];
    a[j]=temp2;
    return j;
    
}

void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
    int j=partition(a,l,h);
    quicksort(a,l,j);
    quicksort(a,j+1,h);

    }
}

int main()
{
    int test[]={50,20,10,40,30,0};
    for(int i=0;i<6;i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    quicksort(test,0,6);
    for(int i=0;i<6;i++)
    {
        printf("%d ",test[i]);
    }
}