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

void delete(struct node *head)
{
    struct node *prev;
    struct node *curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    struct node *temp=head;
    while(curr!=NULL)
    {
        curr=curr->next;
        while(temp!=NULL)
        {
            if(temp->info==curr->info)
            {
                temp->next=curr->next;
                prev=curr->next;
                free(curr);
            }
            temp=temp->next;
        }
        curr=prev;
    }
}