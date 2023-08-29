#include<stdio.h>
#include<stdlib.h>

struct deque
{
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct deque *q)
{
    printf("Enter the deque size\n");
    scanf("%d",&q->size);
    q->Q=(int *)malloc(sizeof(struct deque));
    q->front=0;
    q->rear=-1;
}

void pop_front(struct deque *q)
{
    if(q->rear<q->front)
    {
        printf("deq is empty\n");
    }
    else{
        q->front++;
    }
}

void pop_back(struct deque *q)
{
    if(q->rear<q->front)
    {
        printf("deq is empty\n");
    }
    else{
        q->rear--;
    }
}

void push_back(struct deque *q,int x)
{
    if(q->rear==q->size-1)
    {
        printf("deq is full\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

void push_front(struct deque *q,int x)
{
    if(q->front<=0)
    {
        printf("deq is full\n");
    }

    else
    {
        q->front--;
        q->Q[q->front]=x;
    }
}

void display(struct deque *q)
{
    for(int i =q->front;i<=q->rear;i++)
    {
        printf("%d ",q->Q[i]);
    }
    printf("\n");
}

int main()
{
    struct deque *q1=(struct deque*)malloc(sizeof(struct deque));
    struct deque *q2=(struct deque*)malloc(sizeof(struct deque));
    /*create(q1);
    push_back(q1,1);
    push_back(q1,2);
    push_back(q1,3);
    push_back(q1,4);
    push_back(q1,5);
    display(q1);
    pop_front(q1);
    pop_front(q1);
    display(q1);
    pop_front(q1);
    pop_front(q1);
    pop_front(q1);
    display(q1);
    */
    create(q2);
    push_back(q2,1);
    push_back(q2,2);
    push_back(q2,3);
    push_back(q2,4);
    push_back(q2,5);
    display(q2);
    pop_front(q2);
    pop_front(q2);
    display(q2);
    pop_back(q2);
    display(q2);
    push_back(q2,10);
    display(q2);
    push_front(q2,1);
    display(q2);
    push_front(q2,2);
    display(q2);
    push_front(q2,3);
    pop_front(q2);
    display(q2);
    pop_back(q2);
    display(q2);
    push_back(q2,4);
    display(q2);
    push_front(q2,5);
    display(q2);



    return 0;
}