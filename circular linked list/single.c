#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void displayList(struct node* head)
{
    struct node *curr=head;
    if(curr==NULL)
    {
        printf("out of memory space.");
        exit(0);
    }
    printf("\nThe user defined linked list: \n");
    do
    {
        printf("%d\t",curr->info);
        curr=curr->next;
    } while (curr!=head);    
}

void createList(struct node* head)
{
    int i=1;
    char ch;
    printf("Enter the value of %d node: ",i);
    scanf("%d",&head->info);
    printf("Enter n to exit, any key to continue: ");
    getchar();
    scanf("%c",&ch);
    head->next=head;
    struct node *temp=head;
    while(ch!='n')
    {
        i++;
        temp->next=(struct node*)malloc(sizeof(struct node));
        if(temp->next==NULL)
        {
            printf("Out of memory space.");
            exit(0);
        }
        temp=temp->next;
        printf("Enter the value of %d node: ",i);
        scanf("%d",&temp->info);
        temp->next=head;
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&ch);
    }
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
    return 0;
}