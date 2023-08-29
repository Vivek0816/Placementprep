#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *s;
};

void create(struct queue *q)
{
    printf("Enter q size\n");
    scanf("%d",&q->size);
    q->front=0;
    q->rear=-1;
    q->s=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        printf("Queue is Full");
    }
    else
    {
        q->s[++q->rear]=x;
    }
}

void dequeue(struct queue *q)
{
    if(q->front==q->rear)
    {
        printf("Queue is Empty");
    }
    else
    {
        q->front++;
    }
}

void display(struct queue *q)
{
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d",q->s[i]);
    }
    printf("\n");
}

int main()
{   
    struct queue *q1 = (struct queue *)malloc(sizeof(struct queue));
    create(q1);
    enqueue(q1,1);
    enqueue(q1,2);
    display(q1);
    dequeue(q1);
    display(q1);

    return 0;
}