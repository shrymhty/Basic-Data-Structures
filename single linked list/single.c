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

void insert(struct node *head)
{
    int loc;
    int i=1;
    struct node *nnode;
    struct node *temp=head;
    nnode=(struct node*)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of space memory");
        exit(0);
    }
    printf("\nEnter the location at which a node is to be inserted: ");
    scanf("%d",&loc);
    printf("Enter the value to be inserted: ");
    scanf("%d",&nnode->info);
    struct node *curr;
    curr=head;
    while(curr!=NULL&&i<loc-1)
    {
        curr=curr->next;
        i++;
    }
    nnode->next=curr->next;
    curr->next=nnode;
    displayList(temp);
}

void insert1(struct node *head)
{
    struct node *nnode;
    nnode=(struct node*)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("\nEnter the value to be inserted at the beginning: ");
    scanf("%d",&nnode->info);
    nnode->next=head;
    head=nnode;
    displayList(head);
}

void insertend(struct node *head)
{
    struct node *nnode;
    struct node *temp=head;
    nnode=(struct node*)malloc(sizeof(struct node));
    if(nnode==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("Enter the value to be inserted at the end: ");
    scanf("%d",&nnode->info);
    struct node *curr;
    curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    nnode->next=NULL;
    curr->next=nnode;
    displayList(temp);
}

void deleteloc(struct node *head)
{
    int i=1;
    int loc;
    struct node *curr;
    struct node *prev;
    struct node *temp=head;
    curr=head;
    if(curr==NULL)
    {
        printf("UNDERFLOW.");
        exit(0);
    }
    printf("Enter the location of the node ot be deleted: ");
    scanf("%d",&loc);
    while(curr!=NULL&&i<loc)
    {
        prev=curr;
        curr=curr->next;
        i++;
    }
    if(curr==NULL)
    {
        printf("LOCATION NOT FOUND.");
        exit(0);
    }
    else
    {
        prev->next=curr->next;
        free(curr);
    }
    displayList(temp);
}

void delete1(struct node *head)
{
    struct node *curr;
    curr=head;
    if(curr==NULL)
    {
        printf("UNDERFLOW");
        exit(0);
    }
    head=head->next;
    free(curr);
    printf("\n\nDELETION OF FIRST NODE \n");
    displayList(head);
}

void deleteend(struct node *head)
{
    struct node *curr;
    struct node *prev;
    curr=head;
    if(curr==NULL)
    {
        printf("UNDERFLOW");
        exit(0);
    }
    if(curr->next==NULL)
    {
        free(curr);
        exit(0);
    }
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    free(curr);
    printf("\n\nDELETION OF LAST NODE\n");
    displayList(head);
}

void numberofnodes(struct node *head)
{
    int c=0;
    struct node *curr;
    curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    while(curr!=NULL)
    {
        if(curr->info!=0)
        {
            c++;
        }
        curr=curr->next;
    }
    printf("\nThe number of nodes in the created linked list: %d",c);
}

void search(struct node *head)
{
    int c=0;
    int value;
    struct node *curr;
    curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("\nEnter the value to be searched: ");;
    scanf("%d",&value);
    while(curr!=NULL)
    {
        c++;
        if(curr->info==value)
        {
            break;
        }
        curr=curr->next;
    }
    printf("%d is found in %d node\n",value,c);
    
}

void reverse(struct node *head)
{
    struct node *prev=NULL;
    struct node *next=NULL;
    struct node *curr;
    curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    while(curr!=NULL)
    {   
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    displayList(head);

}

void printmlast(struct node *head)
{
    int loc;
    int i=1;
    struct node *prev=NULL;
    struct node *next=NULL;
    struct node *curr;
    curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    while(curr!=NULL)
    {   
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    struct node* temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    printf("\nEnter the node from the end to be displayed: ");
    scanf("%d",&loc);
    while(temp!=NULL&i<loc)
    {
        temp=temp->next;
        i++;
    }
    printf("The value of the %d node is %d: ",i,temp->info);
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
    int option=1;
    while(option)
    {
        
        printf("\nOPERATONS\t\t\tOPTION\n");
        printf("\nCREATE LIST\t\t\t1\nTRAVERSING\t\t\t2\nINSERTING AT 1 NODE\t\t3\nINSERTING AT ANY NODE\t\t4\nINSERTING AT LAST NODE\t\t5\nDELETEING 1 NODE\t\t6\nDELETION AT A NODE\t\t7\nDELETION OF LAST NODE\t\t8\nNUMBER OF NODES\t\t\t9\nSEARCH\t\t\t\t10\nREVERSE\t\t\t\t11\nPRINT THE Mth NODE FROM THE END\t12\nEXIT\t\t\t\t0");
        printf("\nEnter a valid option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                createList(ptr);
                break;
            }
            case 2:
            {
                displayList(ptr);
                break;
            }
            case 3:
            {
                insert1(ptr);
                break;
            }
            case 4:
            {
                insert(ptr);
                break;
            }
            case 5:
            {
                insertend(ptr);
                break;
            }
            case 6:
            {
                delete1(ptr);
                break;
            }
            case 7:
            {
                deleteloc(ptr);
                break;
            }
            case 8:
            {
                deleteend(ptr);
                break;
            }
            case 9:
            {
                numberofnodes(ptr);
                break;
            }
            case 10:
            {
                search(ptr);
                break;
            }
            case 11:
            {
                reverse(ptr);
                break;
            }
            case 12:
            {
                printmlast(ptr);
                break;
            }
            case 0:
            {
                exit(0);
            }
            default:
            {
                printf("\n\n");
            }
        }
    }
    return 0;
}