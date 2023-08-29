#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int findmax(int a[],int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;

}

void countsort(int a[],int n)
{
    int j=0;
    int max_ele=findmax(a,n);
    int count[max_ele+1];
    for(int i=0;i<max_ele+1;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }

    printf("\n");
    for(int i=0;i<max_ele+1;)
    {
        if(count[i]>0)
        {
            a[j++]=i;
            count[i]--;
        }
        else{i++;}

    }
}

int main()
{
    int test[]={30,20,10,40,20};
    for(int i=0;i<5;i++)
    {
        printf("%d ",test[i]);
    }
    printf("\n");
    countsort(test,5);
    for(int i=0;i<5;i++)
    {
        printf("%d ",test[i]);
    }
}