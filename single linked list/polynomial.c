#include<stdio.h>
#include<stdlib.h>

/*typedef struct polydef
{
    int expo;
    int coeff;
    struct polydef *next;
}poly;

void createPoly(poly *ptr)
{
    poly *curr;
    int i=1;
    char ch;
    printf("Enter the coefficient of %d node: ",i);
    scanf("%d",&ptr->coeff);
    printf("Enter the degree of the %d node: ",i);
    scanf("%d",&ptr->expo);
    ptr->next=NULL;
    printf("Enter n to exit, any ket to continue: ");
    getchar();
    scanf("%c",&ch);
    while(ch!='n')
    {
        i++;
        curr=(poly*)malloc(sizeof(poly));
        if(curr==NULL)
        {
            printf("Out of memory space.");
            exit(0);
        }
        ptr->next=curr;
        ptr=ptr->next;
        printf("Enter the coefficient of %d node: ",i);
        scanf("%d",&ptr->coeff);
        printf("Enter the exponent of the %d node: ",i);
        scanf("%d",&ptr->expo);
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&ch);
        ptr->next=NULL;
    }
}

void displayList(poly *head)
{
    poly *curr=head;
    if(curr==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    printf("\nThe polynomial is : \n");
    while(curr!=NULL)
    {
        printf("%d^x%d + ",curr->coeff,curr->expo);
        curr=curr->next;
    }    
}

int main(void)
{
    poly *p;
    p=(poly *)malloc(sizeof(poly));
    if(p==NULL)
    {
        printf("Out of memory space");
        exit(0);
    }
    createPoly(p);
    displayList(p);
    return 0;
}*/

typedef struct polydef
{
    int info;
    int expo;
    struct polydef *next;
    
}poly;

void create(poly* head)
{
    char c;
    int i=1;
    printf("Enter coeffcient and exponent of %d node: ",i);
    scanf("%d%d",&head->info,&head->expo);
    head->next=NULL;
    printf("Enter n to exit, any key to continue: ");
    getchar();
    scanf("%c",&c);
    while(c!='n')
    {
        i++;
        poly* nnode=(poly*)malloc(sizeof(poly));
        if(nnode==NULL)
        {
            printf("Out of memory space");
            exit(0);
        }
        head->next=nnode;
        printf("Enter the coefficient and exponent of %d node: ",i);
        scanf("%d%d",&nnode->info,&nnode->expo);
        nnode->next=NULL;
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&c);
    }
}

void display(poly *head)
{
    poly* curr=head;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("\nUser defined polynomial: \n");
    while(curr!=NULL)
    {
        printf("%dx^%d\t",curr->info,curr->expo);
        if(curr->next==NULL)
        {
            printf("\n");
        }
        else 
        {
            printf("+\t");
        }
        curr=curr->next;
    }
}

int main()
{
    poly *ptr;
    ptr=(poly*)malloc(sizeof(poly));
    if(ptr==NULL)
    {
        printf("Out of memory space\n");
        exit(0);
    }
    create(ptr);
    display(ptr);
    return 0;
}