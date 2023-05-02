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
    char ch;
    printf("Enter the value of %d node: ",i);
    scanf("%d",&head->info);
    head->next=NULL;
    printf("Enter n to exit, any key to continue: ");
    getchar();
    scanf("%c",&ch);
    struct node *temp=head;
    while(ch!='n')
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
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&ch);
    }
}

void reverse(struct node *head)
{
    struct node *curr=head;
    struct node *prev=NULL;
    struct node *next=NULL;
    if(curr==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    displayList(head);
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
    reverse(ptr);
    return 0;
}