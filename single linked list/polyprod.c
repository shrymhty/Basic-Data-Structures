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
    head->expo;
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

void multiplyPoly(struct node *p1, struct node *p2, struct node *p3)
{
    
}