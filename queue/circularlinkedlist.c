#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *front=NULL, *rear=NULL;

void insert()
{
    int item;
    struct node *nnode=(struct node*)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space.\n");
        exit(0);
    }
    nnode->info=item;
    nnode->next=front;
    if(front==NULL&&rear==NULL)
    {
        front=nnode;
        rear=nnode;
        rear->next=front;
    }
    else 
    {
        rear->next=nnode;
        rear=nnode;
        nnode->next=front;
    }
}

int delete()
{
    int d;
    struct node *temp=front;
    if(temp==NULL)
    {
        printf("Queue is empty\n");
        exit(0);
    }
    else 
    {
        d=temp->info;
        front=front->next;
        free(temp);
    }
    return (d);
}

void display()
{
    struct node *curr=front;
    if(curr==NULL)
    {
        printf("OQueue is empty\n");
        exit(0);
    }
    else 
    {
        printf("The user defined queue: \n");
        do
        {
            printf("%d\t",curr->info);
            curr=curr->next;
        }
        while(curr!=front);        
    }
}

int main()
{
    int option=1;
    while(option!=4)
    {
        printf("\nMENU\n1.\tInsert\n2.\tDelete\n3.\tDisplay\n4.\tExit\n");
        printf("Enter a valid option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                printf("\nThe value deleted: %d\n",delete());
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
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