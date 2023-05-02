#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 10  
int rear=-1;
int front=-1;
int q[maxsize];

void insert(int val)
{
    if (rear==maxsize-1||front<rear)
    {
        printf("Queue is Full/Queue Overflow\n");
        return;
    }  
    else if(rear==-1&&front==-1)
    {
        front=rear=0;
    }
    else
    {
        rear++;
    }
    q[rear]=val;
}

int delete()
{
    int d;
    if(front==-1)
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        d=q[front];
        front++;
        if(front>rear)
        {
            front=rear=-1;
        }
    }
    return d;
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
        printf("\nUser defined Queue: \n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",q[front]);
        }
    }
}

int main()
{
    int value;
    int option=1;
    while(option)
    {
        printf("\n1.\tInsert\n2.\tDelete\n3.\tDisplay\n0.\tExit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                printf("Enter ")
            }
        }
    }
}