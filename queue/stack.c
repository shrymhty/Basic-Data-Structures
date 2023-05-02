#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int info;
    struct stack* next;
}node;

node* rear1=NULL,*rear2=NULL,*front1=NULL,*front2=NULL;

void del1();
void del2();

void copy1_2()
{   
    if(front1==NULL)
    {
        return;
    }
    while(front1!=NULL&&rear1!=NULL)
    {
        node* temp=(node*)malloc(sizeof(node));
        if(temp==NULL)
        {
            printf("Out of memory space\n");
            exit(0);
        }
        temp->info=front1->info;
        if(front2==NULL)
        {
            front2=rear2=temp;
        }
        else 
        {
            rear2->next=temp;
            rear2=temp;
        }
        del1();
    }
}
void copy2_1()
{
    if(front2==NULL)
    {
        return;
    }
    while(front2!=NULL&&rear2!=NULL)
    {
        node* temp=(node*)malloc(sizeof(node));
        if(temp==NULL)
        {
            printf("Out of memory space\n");
            exit(0);
        }
        temp->info=front2->info;
        if(front1==NULL)
        {
            front1=rear1=temp;
        }
        else 
        {
            rear1->next=temp;
            rear1=temp;
        }
        del2();
    }
}

void push()
{
    int i;
    int val;
    char c;
    do
    {
        printf("Enter the value to be pushed: ");;
        scanf("%d",&val);
        node* temp=(node*)malloc(sizeof(node));
        if(temp==NULL)
        {
            printf("Out of memory space\n");
            exit(0);
        }
        temp->info=val;
        copy1_2();
        if(front1==NULL)
        {
            front1=rear1==temp;
        }
        else 
        {
            rear1->next=temp;
            rear1=temp;
        }
        copy2_1();
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&c); 
    } while (c!='n');
}

void del1()
{
    node* p;
    int x=-1;
    if(front1==NULL&&rear1==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else{
        node* temp=front1;
        x=front1->info;
        if(front1==rear1)
        {
            front1=rear1=NULL;
        }
        else 
        {
            front1=front1->next;
        }
        free(temp);
    }
}

void del2()
{
    struct node *p;
    int x = -1;
    if (front2 == NULL && rear2 == NULL)
        printf("Queue is empty \n");
    else
    {
        struct node *temp = front2;
        if(front2==rear2){
            front2=NULL;
            rear2=NULL;
        }
        else{
            front2 = front2->next;
        }
        free(temp);
        
    }
}

void pop()
{
    
}
