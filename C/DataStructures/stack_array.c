#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    int *s;
};

void create(struct stack *st)
{
    printf("Enter stack size\n");
    scanf("%d",st->size);
    st->s=(int *)malloc(st->size*sizeof(int));
    st->top=-1;
}

void display(struct stack *st)
{
    for(int i=st->top;i>=0;i--)
    {
        printf("%d ",st->s[i]);
    }
    printf("\n");
}


void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
    {
        printf("stack overflow");
    }
    else
    {
        st->s[++st->top]=x;
    }
    
}

void pop(struct stack *st)
{
    if(st->top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        st->top--;
    }
}

//peek....Returns the element at the required index
//isempty...returns bool if the stack is empty
//isfull...returns book if the stack is full
//stacktop...returns value at the stacktop

int main()
{
    struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
    create(s1);
    push(s1,1);
    display(s1);
    push(s1,2);
    push(s1,3);
    push(s1,4);
    push(s1,5);
    display(s1);
    pop(s1);
    display(s1);
}