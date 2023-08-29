#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int front;
    int rear;
    int size;
    int *Q;
};

void create_q(struct queue *q)
{   
    q->front=0;
    q->rear=0;
    printf("Enter the size of queue\n");
    scanf("%d",&q->size);
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q, int x)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Q is full\n");
    }

    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}


void display(struct queue *q)
{
    int i=q->front+1;
    do
    {
        printf("%d ",q->Q[i]);
        i=(i+1)%q->size;
    }
    while(i!=(q->rear+1)%q->size);
    printf("\n");
}



void dequeue(struct queue *q)
{
    if(q->front==q->rear)
    {
        printf("Q is empty");
    }
    else
    {
        q->front=(q->front+1)%q->size;
    }
}

int main()
{
    struct queue *q1=(struct queue*)malloc(sizeof(struct queue));
    create_q(q1);
    enqueue(q1,1);
    enqueue(q1,2);
    enqueue(q1,3);
    enqueue(q1,4);
    enqueue(q1,5);
    display(q1);
    dequeue(q1);
    display(q1);
    dequeue(q1);
    enqueue(q1,5);
    display(q1);

}