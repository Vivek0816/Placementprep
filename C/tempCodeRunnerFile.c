#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void merge(int a[],int mid, int l,int h)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int b[h++];
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }

    for(;i<=mid;i++)
    {
        b[k++]=a[i];
    }

    for(;j<=h;j++)
    {
        b[k++]=a[j];
    }
    
    for(int x=l;x<=h;x++)
    {
        a[x]=b[x];
    }
}


void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,mid,l,h);
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
    mergesort(test,0,5);
    for(int i=0;i<6;i++)
    {
        printf("%d ",test[i]);
    }
    return 0;
}