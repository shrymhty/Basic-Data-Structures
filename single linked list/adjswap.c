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

void swap(struct node *head)
{
    if(head==NULL||head->next==NULL)
    {
        printf("Invalid");
        exit(0);
    }
    int temp;
    struct node *nptr;
    struct node *ptr=head;
    nptr=head->next;
    while(nptr!=NULL)
    {
        temp=ptr->info;
        ptr->info=nptr->info;
        nptr->info=temp;
        ptr=ptr->next->next;
        nptr=nptr->next->next;
    }
    displayList(head);

}

int main()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    createList(p);
    displayList(p);
    swap(p);
    displayList(p);
    return 0;
}