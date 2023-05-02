#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *next;
    int info;
};

struct node *front=NULL, *rear=NULL;

void insert()
{
    int item;
    printf("Enter the number to be inserted: ");
    scanf("%d",&item);
    struct node *nnode=(struct node *)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space.\n");
        exit(0);
    }
    nnode->info=item;
    if(front==NULL&&rear==NULL)
    {
        front=nnode;
        rear=nnode;
        front->next=NULL;
        rear->next=NULL;
    }
    else 
    {
        rear->next=nnode;
        rear=nnode;
        rear->next=NULL;
    }

}

int delete()
{
    struct node *temp=front;
    int d=front->info;
    if(front==rear)
    {
        front=rear=NULL;
    }
    else 
    {
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
        printf("Queue is empty\n");
        exit(0);
    }
    printf("The user defined queue: \n");
    while(curr!=NULL)
    {
        printf("%d\t",curr->info);
        curr=curr->next;
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