#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *next;
    int info;
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

void sort(struct node *head)
{
    int t;
    struct node *temp1=head;
    struct node *temp2;
    if(head==NULL)
    {
        printf("\nThere are no elements in the linked list.");
        exit(0);
    }
    for(temp1=head;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
        {
            if(temp1->info>temp2->info)
            {
                t=temp1->info;
                temp1->info=temp2->info;
                temp2->info=t;
            }
        }
    }
    printf("\nThe sorted linked list: \n");
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
    sort(ptr);
    return 0;
}