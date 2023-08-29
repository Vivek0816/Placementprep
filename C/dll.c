#include<stdio.h>
#include<stdlib.h>


struct node{
    struct node *prev;
    int data;
    struct node *next;
};
 
struct node* create_ll(struct node *first,int start_ele)
{
    struct node *f=(struct node*)malloc(sizeof(struct node*));
    f->data=start_ele;
    f->prev=NULL;
    f->next=NULL;
    first=f;
    return first;
}

struct node* push_front(struct node *first, int req_data){
    struct node *temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=req_data;
    temp->next=first;
    temp->prev=NULL;
    temp=first;
    return temp;  
}

int pop_front(struct node *first){
    struct node *p;
    p=first->next;
    int x=first->data;
    first=p;
    first->prev=NULL;
    free(p);
    return x;
}

void main()
{
    struct node *first;
    first=create_ll(first,1);
    first=push_front(first,2);
    int x=pop_front(first);
    printf("%d",x);


    //printf("Works");
}