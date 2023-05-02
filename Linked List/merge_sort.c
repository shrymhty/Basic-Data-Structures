//merging two unsorted LLs to a sorted one

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

struct node* merge(struct node* list1, struct node* list2)
{
    if(list1==NULL)return list2;
    if(list2==NULL)return list1;

    struct node *head=NULL;
    if(list1->info<list2->info)
    {
        head=list1;
        list1=list1->next;
    }
    else 
    {
        head=list2;
        list2=list2->next;
    }
    struct node *p=head;
    while(list1&&list2)
    {
        if(list1->info<list2->info)
        {
            p->next=list1;
            list1=list1->next;
        }
        else 
        {
            p->next=list2;
            list2->next;
        }
    }
    if(list1)
    {
        p->next=list1;
    }
    else 
    {
        p->next=list2;
    }
    return p;
}

int main()
{
    struct node *ptr1;
    struct node *ptr2;
    struct node *ptr;
    ptr1=ptr2=ptr=(struct node*)malloc(sizeof(struct node));
    createList(ptr1);
    createList(ptr2);
    displayList(ptr1);
    displayList(ptr2);
    ptr=(ptr1,ptr2);
    displayList(ptr);
    return 0;
}