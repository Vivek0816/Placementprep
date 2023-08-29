#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void create_dll(int a[],int n)
{
    struct node *t,*last;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=a[0];
    t->prev=NULL;
    t->next=NULL;
    first=t;
    last=first;

    for(int i=1;i<n;i++)
    {
      t=(struct node*)malloc(sizeof(struct node));
      t->data=a[i];
      last->next=t;
      t->prev=last;
      t->next=NULL;
      last=t;
    }
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

void push_back(struct node *a,int x)
{
    struct node *t,*last;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    while(a->next!=NULL)
    {
        a=a->next;
    }
    last=a;
    last->next=t;
    t->prev=last;
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
    t->prev=NULL;
    t->next=*a;
    (*a)->prev=t;
    *a=t;
} 

void pop_front(struct node **a)
{
    struct node *t=*a;
    (*a)=(*a)->next;
    (*a)->prev=NULL;
    free(t);

}

void insert_at_pos(struct node **a, int ind, int x)
{
    struct node *t,*p,*q;
    p=*a;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(ind == 0)
    {
        t->prev=NULL;
        t->next=*a;
        (*a)->prev=t;
        *a=t;
    }
    else
    {
        for(int i=0;i<ind-1;i++)
        {
            p=p->next;
        }
        q=p->next;
        t->next=q;
        t->prev=p;
        q->prev=t;
        p->next=t;
    }
}
    

void deleten(struct node **a, int ind)
{   
    struct node *t=NULL,*p=*a,*q=NULL;
    if(ind==0)
    {
        *a=(*a)->next;
        (*a)->prev=NULL;
        free(p);
    }

    else
    {
        for(int i=0;i<ind-1;i++)
        {
            p=p->next;
        }
        t=p->next;
        q=t->next;
        p->next=q;
        q->prev=p;
        free(t);
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
            if(q->next)
            {
                q->next->prev=p;
                free(q);
                q=p->next;
            }
            else{free(q);q=NULL;}
            
        }
    }

    
}
/*
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
*/

int main()
{
    int list[]={1,2,2,4,4};
    create_dll(list,5);
    display(first);
    push_back(first,4);
    display(first);
    push_back(first,7);
    display(first);
    push_back(first,8);
    display(first);
    pop_back(first);
    display(first);
    pop_back(first);
    display(first);
    push_front(&first,0);
    display(first);
    push_front(&first,-1);
    display(first);
    pop_front(&first);
    display(first);
    pop_front(&first);
    display(first);
    push_front(&first,0);
    insert_at_pos(&first,0,-1);
    display(first);
    deleten(&first,2);
    display(first);
    deletedup(&first);
    display(first);
    return 0;
}