#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void selection_sort(int a[],int n)
{   
    int j,k,temp;
    for(int i=0;i<n;i++)
    {
        for(j = k = i;j<n;j++)
        {
            if(a[j]<a[k]){k=j;}
        }
        temp=a[k];
        a[k]=a[i];
        a[i]=temp;

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
    selection_sort(test,5);
    for(int i=0;i<5;i++)
    {
        printf("%d ",test[i]);
    }
}