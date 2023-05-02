#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* next;
    int info;
};

void createList(struct node* head)
{
    int i=1;
    char ch;
    printf("Enter the value of%d node: ");
    scanf("%d",&head->info);
    head->next=NULL;
    printf("Enter n to exit, any key to continue: ");
    getchar();
    scanf("%c",&ch);
    struct node* temp=head;
    while(ch!='n')
    {
        i++;
        temp->next=(struct node*)malloc(sizeof(struct node));
        if(temp->next==NULL)
        {
            printf("Out of memory space\n");
            exit(0);
        }
        temp=temp->next;
        temp->next=NULL;
        printf("Enter the value of node %d: ",i );
        scanf("%d",&temp->info);
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&ch);
    }
}

void displayList(struct node* head)
{
    struct node* curr=head;
    if(curr==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    printf("\nThe used defined linked list: \n");
    while(curr!=NULL)
    {
        printf("%d\t",curr->info);
        curr=curr->next;
    }
}

int llength(struct node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    return llength(head->next)+1;
}

struct node* findmiddle(struct node *head)
{
    struct node* slow=head;
    struct node* fast=head->next;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast)
    {
        return fast;
    }
    return slow;
}

int main()
{
    struct node* ptr=(struct  node*)malloc(sizeof(struct node));
    createList(ptr);
    displayList(ptr);
    printf("\nLength of the linked list: %d",llength(ptr));
    struct node *mid=findmiddle(ptr);
    printf("\nMiddle element: %d",mid->info);
    return 0;
}