#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int info;
    struct node *next;
};

void createList(struct node *head)
{
    int i=1;
    char ch;
    head->next=NULL;
    printf("Enter the value of %d node : ",i);
    scanf("%d",&head->info);
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
            printf("Out of memory space.");
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

void operation(struct node *head)
{
    struct node *prev;
    int c=0;
    int value;
    struct node *curr;
    curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("\nEnter the value to be searched: ");;
    scanf("%d",&value);
    while(curr!=NULL&&curr->info!=value)
    {
        prev=curr;
        curr=curr->next;
        c++;
    }
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    if(c)
    {
        temp->next=curr->next;
        prev->next=temp;
        temp->info=head->info;
        free(curr);

    }
    else
    {
        printf("NOT FOUND");
    }
    displayList(head);
}

int main(void)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    createList(ptr);
    displayList(ptr);
    operation(ptr);
    return 0;
}