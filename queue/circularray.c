#include<stdio.h>
#include<stdlib.h>
int rear=-1,front=-1;
#define size 10
int queue[size];

void insert()
{
    int b;
    printf("Enter a number to be inserted: ");
    scanf("%d",&b);
    if((front==0&&rear==size-1)||(front==rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    else if(front<0)
    {
        front=0;
        rear=0;
    }
    else if(rear==size-1)
    {
        rear=0;
    }
    else 
    {
        rear=rear+1;
    }
    queue[rear]=b;
}

int delete()
{
    int d;
    if(front<0)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    d=queue[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==size-1)
    {
        front=0;
    }
    else 
    {
        front=front+1;
    }
    return (d);
}

void display()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else 
    {
        printf("The user defined queue is: \n");
        while(front<rear+1)
        {
            printf("%d\t",queue[front]);
            front=front+1;
        }
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