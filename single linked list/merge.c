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

void createList(struct node *head, int x)
{
    int i=1;
    char ch;
    printf("\nEnter the value of %d node of List %d: ",i,x);
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
        printf("Enter the value of %d node of list %d: ",i,x);
        scanf("%d",&temp->info);
        temp->next=NULL;
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&ch);
    }
}

void merge(struct node *head1,struct node *head2)
{
    struct node *curr=head1;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=head2;
    printf("\nMERGED:\n");
    displayList(head1);
}

int main(void)
{
    struct node *ptr1;
    struct node *ptr2;
    ptr1=(struct node *)malloc(sizeof(struct node));
    ptr2=(struct node*)malloc(sizeof(struct node));
    createList(ptr1,1);
    displayList(ptr1);
    createList(ptr2,2);
    displayList(ptr2);
    merge(ptr1,ptr2);
    return 0;
}