#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void displayList(struct node *head)
{
    struct node *temp=head;
    if(temp==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("\nThe user defined linked List: \n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
}

void createList(struct node *head)
{
    int i=1;
    int n;
    int j=1;
    printf("Enter the number of node: ");
    scanf("%d",&n);
    printf("Enter the value of %d node: ",i);
    scanf("%d",&head->info);
    head->next=NULL;
    struct node *temp=head;
    while(j<n)
    {
        i++;
        temp->next=(struct node*)malloc(sizeof(struct node));
        if(temp->next==NULL)
        {
            printf("Out of space memory.");
            exit(0);
        }
        temp=temp->next;
        printf("Enter the value of %d node: ",i);
        scanf("%d",&temp->info);
        temp->next=NULL;
        j++;
    }
}

void count(struct node *head)
{
    int c=0;
    struct node *curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    int value;
    printf("\nEnter the value to be counted: ");
    scanf("%d",&value);
    while(curr!=NULL)
    {
        if(curr->info==value)
        {
            c++;
        }
        curr=curr->next;
    }
    if(c!=0)
    {
        printf("\nThe frequency of %d is %d.",value,c);
    }
    else
    {
        printf("\nLOCATION NOT FOUND");
    }
}

int main(void)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    createList(ptr);
    displayList(ptr);
    count(ptr);
    return 0;
}