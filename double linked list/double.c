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

void insert1(struct node *head)
{
    struct node *nnode;
    nnode=(struct node*)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    printf("\n Enter the value to be inserted in the beginning: ");
    scanf("%d",&nnode->info);
    nnode->prev=NULL;
    nnode->next=head;
    head=nnode;
    displayList(head);
}

void insert(struct node *head)
{
    struct node *prev;    
    struct node *curr=head;
    int i=1;
    int loc;
    struct node *nnode;
    nnode=(struct node *)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("\nEnter the location at which a node is to be inserted: ");
    scanf("%d",&loc);
    printf("Enter the value to be inserted: ");
    scanf("%d",&nnode->info);
    while(curr!=NULL&&i<loc)
    {
        prev=curr;
        curr=curr->next;
        i++;
    }
    prev->next=nnode;
    nnode->prev=prev;
    nnode->next=curr;
    curr->prev=nnode;
    displayList(head);
}

void insertend(struct node *head)
{
    struct node *nnode;
    nnode=(struct node*)malloc(sizeof(struct node));
    struct node *curr=head;
    if(nnode==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    nnode->next=NULL;
    nnode->prev=curr;
    curr->next=nnode;
    printf("\nEnter the value to be inserted at the end of the list: ");
    scanf("%d",&nnode->info);
    displayList(head);
}

void delete1(struct node *head)
{
    struct node *curr;
    curr=head;
    if(curr==NULL)
    {
        printf("UNDERFLOW");
        exit(0);
    }
    head=head->next;
    free(curr);
    displayList(head);
}

void deleteloc(struct node *head)
{
    struct node *curr;
    struct node *prev;

    curr=head;
    int loc;
    int i=1;
    printf("\nEnter the node that is to be deleted: ");
    scanf("%d",&loc);
    if(curr==NULL)
    {
        printf("UNDERFLOW");
        exit(0);
    }
    if(loc==1)
    {
        delete1(head);
    }
    else{
    while(curr!=NULL&&i<loc)
    {
        prev=curr;
        curr=curr->next;
        i++;
    }
    }
    if(curr==NULL)
    {
        printf("LOCATION NOT FOUND");
    }
    else
    {
        prev->next=curr->next;
        curr->next->prev=prev;
        free(curr);
    }
    displayList(head);
}

void deleteend(struct node *head)
{
    struct node *prev;
    struct node *curr;
    curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    free(curr);
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
    int option=1;
    while(option)
    {
        printf("\nOPERATONS\t\t\tOPTION\n");
        printf("\nCREATE LIST\t\t\t1\nTRAVERSING\t\t\t2\nINSERTING AT 1 NODE\t\t3\nINSERTING AT ANY NODE\t\t4\nINSERTING AT LAST NODE\t\t5\nDELETEING 1 NODE\t\t6\nDELETION AT A NODE\t\t7\nDELETION OF LAST NODE\t\t8\nEXIT\t\t\t\t0");
        printf("\nEnter a valid option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                createList(ptr);
                break;
            }
            case 2:
            {
                displayList(ptr);
                break;
            }
            case 3:
            {
                insert1(ptr);
                break;
            }
            case 4:
            {
                insert(ptr);
                break;
            }
            case 5:
            {
                insertend(ptr);
                break;
            }
            case 6:
            {
                delete1(ptr);
                break;
            }
            case 7:
            {
                deleteloc(ptr);
                break;
            }
            case 8:
            {
                deleteend(ptr);
                break;
            }
            case 0:
            {
                exit(0);
            }
            default:
            {
                printf("\n\n");
            }
        }
    }
    return 0;
}