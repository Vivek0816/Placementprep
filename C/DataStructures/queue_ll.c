#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(rear==NULL)
    {
        front=rear=t;
    }
    else
    {
        rear->next=t;
        rear=t;
    }
}

void dequeue()
{
    struct node *t;
    if(front==NULL||front==rear)
    {
        printf("Queue is empty");
    }
    else
    {
        t=front;
        front=front->next;
        free(t);
    }

}

void display()
{
    struct node *t=front;
    if(front==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        while(t!=NULL)
        {
            printf("%d",t->data);
            if(t->next){printf("->");}
            t=t->next;
        }
    }
    printf("\n");
}

int main()
{
    enqueue(1);
    display();
    enqueue(2);
    display();
    enqueue(3);
    display();
    dequeue();
    display();
}