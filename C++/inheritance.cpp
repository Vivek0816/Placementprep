#include <iostream>
using namespace std;
class stack
{
    int top;
    int size=5;
    int stak[size];

    stack()
    {
        top=-1;
    }
    void push(int a)
    {
        if(top==size-1)
        {
            cout<<"Stack Full";
            return;
        }
        else
        {
            stak[++top]=a;
        }
    }

    int pop()
    {
        if(top<0)
        {
            cout<<"stack empty";
            return;
        }
        else
        {
            return stak[top--];
        }
    }

    void display()
    {
        if(top<0)
        {
            cout<<"Stack empty";
        }

        for(int i=0;i<top;i++)
        {
            cout<<stak[i];
        }
    }


}