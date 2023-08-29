#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL,*last=NULL;

void create_cll(int a[],int n)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->data=a[0];
    t->next=NULL;
    head=last=t;

    for(int i=1;i<n;i++)
    {
        struct node *t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=head;
        last->next=t;
        last=t;
        //printf("%d",last->data);
    }
}

void display()
{
    struct node *p=head;
    do{
        printf("%d",p->data);
        if(p->next && p->next!=head){printf("->");}
        p=p->next;
    }
    while(p!=head);
    printf("\n");
    
}

void insert(int ind, int x)
{
    struct node *p=head,*q;
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(ind==0)
    {

        if(head==NULL)
        {
            head=last=t;
            head->next=NULL;
        }
        else
        {
            t->next=head;
            last->next=t;
            head=t;
        }
    }
    else
    {
        for(int i=0;i<ind-1;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=t;
        t->next=q;
    }
}

void delete(int ind)
{
    struct node *t,*p,*q;
    p=head;
    if(ind==0)
    {
        if(head==NULL)
        {
            printf("No CLL");
        }
        else if(head==last)
        {
            free(head);
        }
        else
        {
            p=p->next;
            free(head);
            head=p;
            last->next=head;
        }
    }
    else
    {
        for(int i=0;i<ind-1;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        free(q);
    }
}

void main()
{
    int list[]={1,2,3,4,5,6};
    create_cll(list,6);
    display();
    insert(0,0);
    display();
    insert(0,-1);
    display();
    insert(1,10);
    display();
    insert(2,5);
    display();
    delete(0);
    display();
    delete(0);
    display();
    delete(1);
    display();
    delete(2);
    display();
}