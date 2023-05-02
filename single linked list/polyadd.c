#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int coeff;
    int expo;
    struct node *next;
};

void createPoly(struct node *head, int n)
{
    int i=1;
    char ch;
    printf("\nEnter the coefficient and exponent of %d Polynomial: ",n);
    printf("\nEnter the coefficient of %d node: ",i);
    scanf("%d",&head->coeff);
    printf("Enter the exponent of %d node: ",i);
    scanf("%d",&head->expo);
    head->next=NULL;
    printf("Enter n to exit, any key to continue: ");
    getchar();
    scanf("%c",&ch);
    struct node *curr=head;
    while(ch!='n')
    {
        i++;
        curr->next=(struct node*)malloc(sizeof(struct node));
        if(curr->next==NULL)
        {
            printf("Out of memory space.");
            exit(0);
        }
        curr=curr->next;
        printf("\nEnter the coefficient of %d node: ",i);
        scanf("%d",&curr->coeff);
        printf("Enter the exponent of %d node: ",i);
        scanf("%d",&curr->expo);
        curr->next=NULL;
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&ch);
    }
}

void displayPoly(struct node *head)
{
    struct node *curr=head;
    printf("\nPolynomial: ");
    while(curr!=NULL)
    {
        printf("%dx^%d",curr->coeff,curr->expo);
        if(curr->next==NULL)
        {
            printf("\n");
        }
        else{
            printf(" + ");
        }
        curr=curr->next;
    }
}

void addPoly(struct node *p1, struct node* p2, struct node *p3)
{
    while(p1->next!=NULL&&p2->next!=NULL)
    {
        if(p1->expo>p2->expo)
        {
            p3->expo=p1->expo;
            p3->coeff=p1->coeff;
            p1=p1->next;
        }
        else if(p2->expo>p1->expo)
        {
            p3->coeff=p2->coeff;
            p3->expo=p2->expo;
            p2=p2->next;
        }
        else
        {
            p3->coeff=p1->coeff+p2->coeff;
            p3->expo=p1->expo;
            p1=p1->next;
            p2=p2->next;
        }
        p3->next=(struct node*)malloc(sizeof(struct node));
        p3=p3->next;
        p3->next=NULL;
    }
    p3->next=(struct node*)malloc(sizeof(struct node));
    p3=p3->next;
    p3->next=NULL;
    while(p1->next!=NULL||p2->next!=NULL)
    {
        if(p1->next)
        {
            p3->coeff=p1->coeff;
            p3->expo=p1->expo;
            p1=p1->next;
        }
        if(p2->next)
        {
            p3->coeff=p2->coeff;
            p3->expo=p2->expo;
            p2=p2->next;
        }
        p3->next=(struct node*)malloc(sizeof(struct node));
        p3=p3->next;
        p3->next=NULL;
    }
}


int main()
{
    struct node *ptr1;
    struct node *ptr2;
    struct node *ptr3;
    ptr1=(struct node*)malloc(sizeof(struct node));
    ptr2=(struct node*)malloc(sizeof(struct node));
    ptr3=(struct node*)malloc(sizeof(struct node));
    if(ptr1==NULL||ptr2==NULL||ptr3==NULL)
    {
        printf("Out of memory space.");
        exit(0);
    }
    createPoly(ptr1,1);
    displayPoly(ptr1);
    createPoly(ptr2,2);
    displayPoly(ptr2);
    addPoly(ptr1,ptr2,ptr3);
    displayPoly(ptr3);
    return 0;
}