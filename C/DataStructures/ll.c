#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL;

void create_ll(int a[],int n)
{
    struct node *t,*last;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=a[0];
    t->next=NULL;
    first=t;
    last=first;

    for(int i=1;i<n;i++)
    {
      t=(struct node*)malloc(sizeof(struct node));
      t->data=a[i];
      t->next=NULL;
      last->next=t;
      last=t;
    }
}

void push_back(struct node *a,int x)
{
    struct node *t,*last;
    t=(struct node*)malloc(sizeof(struct node*));
    t->data=x;
    t->next=NULL;
    while(a->next!=NULL)
    {
        a=a->next;
    }

    last=a;
    last->next=t;
    last=t;
}

void pop_back(struct node *a)
{
    struct node *last;
    while(a->next->next!=NULL)
    {
        a=a->next;
    }
    last=a->next;
    free(last);
    a->next=NULL;
}

void push_front(struct node **a,int x)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=*a;
    *a=t;
} 

void pop_front(struct node **a)
{
    struct node *t=*a;
    *a = (*a)->next;
    free(t);   
}


void display(struct node *a)
{
    while(a!=NULL)
    {
        printf("%d",a->data);
        if(a->next!=NULL){printf("->");}
        a=a->next;
    }
    printf("\n");
}

void insert_at_pos(struct node **a, int ind, int x)
{
    struct node *p=*a;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    if(ind==0)
    {
        push_front(a,x);
    }
    
    else
    {
    temp->data=x;
    for (int i=0;i<ind-1;i++)
    {
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
    }
    
}

void delete(struct node **a, int ind)
{   
    struct node *t,*p,*q;
    p=*a;
    if(ind==0)
    {
        q=p->next;
        *a=q;
        free(p);
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

void deletedup(struct node **a)
{   
    struct node *t,*p,*q;
    p=*a;
    q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
        p=q;
        q=q->next;
        }
        
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
            
        }
    }
    
}

void reverse(struct node **a)
{
    struct node *p=*a,*q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    *a=q;

}

void main()
{
    int list[]={1,2,2,2,5};
    create_ll(list,5);
    display(first);
    push_back(first,6);
    push_back(first,7);
    display(first);
    pop_back(first);
    display(first);
    pop_back(first);
    display(first);
    push_front(&first,0);
    push_front(&first,-1);
    display(first);
    pop_front(&first);
    display(first);
    insert_at_pos(&first, 5,30);
    display(first);
    delete(&first,0);
    display(first);
    deletedup(&first);
    display(first);
    reverse(&first);
    display(first);
}