#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int x)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(top==NULL)
    {
        top=t;
        top->next=NULL;
    }
    else
    {
        t->next=top;
        top=t;
    }
}

void pop()
{
    struct node *t=NULL;
    t=top;
    top=top->next;
    free(t);
}

void display()
{
    struct node *t=top;
    while(t!=NULL)
    {
        printf("%d",t->data);
        if(t->next){printf("->");}
        t=t->next;
    }
    printf("\n");
}

int main()
{
    push(1);
    display();
    push(2);
    display();
    push(3);
    display();
    pop();
    display();
}