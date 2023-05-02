#include <stdio.h>
#include<stdlib.h>

struct node 
{
    int info;
    struct node *next;
    struct node *prev;
};

void displayList(struct node *head)
{
    struct node *curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("\nThe user defined linked list: \n");
    while(curr!=NULL)
    {
        printf("%d\t",curr->info);
        curr=curr->next;
    }
}

void createList(struct node *head)
{
    int i=1;
    char ch;
    printf("Enter the value of %d node: ",i);
    scanf("%d",&head->info);
    head->next=NULL;
    head->prev=NULL;
    printf("Enter n to exit, any key to continue: ");
    getchar();
    scanf("%c",&ch);
    struct node *curr;
    while(ch!='n')
    {
        i++;
        curr=(struct node *)malloc(sizeof(struct node));
        if(curr==NULL)
        {
            printf("Out of memory space.");
            exit(0);
        }
        head->next=curr;
        curr->prev=head;
        head=head->next;
        printf("Enter the value of %d node: ",i);
        scanf("%d",&head->info);
        head->next=NULL;
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&ch);
    }
}

void rev(struct node *head)
{
    struct node *curr=head;
    struct node *temp=NULL;
    if(curr==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    while(curr->next!=NULL)
    {
        temp=curr->next;
        curr->next=curr->prev;
        curr->prev=temp;
        curr=curr->prev;

    }
    displayList(temp);
}

void main()
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    createList(ptr);
    displayList(ptr);
    rev(ptr);
}