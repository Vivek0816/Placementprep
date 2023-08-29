#include<stdio.h>
#include<stdlib.h>

void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                flag=1;
            }
        }
        if(flag==0){break;}
    }
}

void swap(int x,int y)
{
    int temp=x;
    x=y;
    y=temp;
}

int main()
{
    int a[]={30,10,20,50,40};
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    bubblesort(a,5);
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");
    int x=10;
    int y=20;
    swap(x,y);
    printf("%d   %d", x,y);

}