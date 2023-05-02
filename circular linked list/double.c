#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

void displayDList(struct node *head)
{
    struct node *curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("\nThe user defined linked list: \n");
    do
    {
        printf("%d\t",curr->info);
        curr=curr->next;
    } while (curr!=head);   
}

void createDList(struct node *head)
{
    int i=1;
    char ch;
    printf("Enter the value of %d node: ",i);
    scanf("%d",&head->info);
    head->next=head;
    head->prev=head;
    printf("Enter n to exit, any key to continue: ");
    getchar();
    scanf("%c",&ch);
    struct node *curr,*start;
    start=head;
    while(ch!='n')
    {
        i++;
        curr=(struct node*)malloc(sizeof(struct node));
        if(curr==NULL)
        {
            printf("Out of memory space.");
            exit(0);
        }
        head->next=curr;
        curr->prev=head;
        head=head->next;
        printf("Enter the value %d node: ",i);
        scanf("%d",&head->info);
        head->next=start;
        start->prev=head;
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&ch);
    }
}

void insert1(struct node *head)
{
    struct node *start=head;
    struct node *curr=head;
    struct node *nnode;
    nnode=(struct node *)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    printf("\nEnter the value to be inserted at the beginning: ");
    scanf("%d",&nnode->info);
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    nnode->next=start;
    start->prev=nnode;
    nnode->prev=curr;
    curr->next=nnode;
    head=nnode;
    displayDList(head);
}

void insertloc(struct node *head)
{
    struct node *curr=head;
    struct node *nnode;
    nnode=(struct node*)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    int i=1;
    int loc;
    printf("\nEnter the location where a node is inserted: ");
    scanf("%d",&loc);
    printf("Enter the value of the node to be inserted: ");
    scanf("%d",&nnode->info);
    while(curr->next!=head&&i<loc-1)
    {
        curr=curr->next;
        i++;
    }
    nnode->next=curr->next;
    curr->next=nnode;
    nnode->prev=curr;
    displayDList(head);
}

void insertend(struct node *head)
{
    struct node *curr=head;
    struct node *nnode;
    nnode=(struct node*)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    printf("\nEnter the value of the node to be inserted at the end: ");
    scanf("%d",&nnode->info);
    nnode->next=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    nnode->prev=curr;
    curr->next=nnode;
    head->prev=nnode;
    displayDList(head);
}

void delete1(struct node *head)
{
    struct node *start=head;
    if(start==NULL)
    {
        printf("Underflow");
        exit(0);
    }
    struct node *curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    head=head->next;
    head->prev=curr;
    curr->next=head;
    free(start);
    displayDList(head);
}

void deleteloc(struct node *head)
{
    int i=1;
    int loc;
    struct node *curr=head;
    struct node *prev;
    printf("\nEnter the location of the node to be deleted: ");
    scanf("%d",&loc);
    if(curr==NULL)
    {
        printf("Underflow");
        exit(0);
    }
    while(curr->next!=head&&i<loc)
    {
        prev=curr;
        curr=curr->next;
        i++;
    }
    prev->next=curr->next;
    curr->next->prev=prev;
    free(curr);
    displayDList(head);
}

void deleteend(struct node *head)
{
    struct node *prev;
    struct node *curr=head;
    printf("\nDeletion at the end: \n");
    while(curr->next!=head)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=head;
    head->prev=curr;
    free(curr);
    displayDList(head);
}

int main(void)
{
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    int option=1;
    while(option)
    {
        printf("\n\nOPERATIONS\t\t\tOPTION\n");
        printf("Creation\t\t\t\t1\nTraversal\t\t\t\t2\nInsertion in the beginning\t\t3\nInsertion at any loc\t\t\t4\nInsertion at the end\t\t\t5\nDeletion of 1 node\t\t\t5\nDeletion of any node\t\t\t6\nDeletion of last node\t\t\t7\nExit\t\t\t\t\t0\n");
        printf("\nEnter a valid option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                createDList(ptr);
                break;
            }
            case 2:
            {
                displayDList(ptr);
                break;
            }
            case 3:
            {
                insert1(ptr);
                break;
            }
            case 4:
            {
                insertloc(ptr);
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
                break;
            }
            default:
            {
                printf("\n\n");
            }
        }
    }
    return 0;
}