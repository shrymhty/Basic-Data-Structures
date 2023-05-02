#include<stdio.h>
#include<stdlib.h>

struct  node
{
    struct node* next;
    int info;
};

struct node* front=NULL;
struct node* rear=NULL;

void enqueue(int n)
{
    struct node* nnode=(struct node*)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space\n");
        exit(0);
    }
    nnode->info=n;
    nnode->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=rear=nnode;
    }
    else 
    {
        rear->next=nnode;
        rear=nnode;
    }
}

int dequeue()
{
    int d;
    struct node* temp=front;
    if(front==NULL)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else if(rear==front)
    {
        d=front->info;
        rear=front=NULL;
    }
    else
    {
        d=front->info;
        front=front->next;
        free(temp);
    }
    return d;
}

void display()
{
    struct node *curr=front;
    if(curr==NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    printf("\nUser defined queue\n:");
    while(curr!=NULL)
    {
        printf("%d\t",curr->info);
    }
}

int main()
{
    
}