#include<stdio.h>
#include<malloc.h>
#define max 10
typedef struct 
{
   int coeff[max];
   int expo;
}poly;
void input(poly *p)
{
    int i;
    printf("Enter the highest degree of the polynomial: ");
    scanf("%d",&p->expo);
    if(p->expo>max)
    {
        return;
    }
    printf("\nEnter the coefficient of terms of the polynomial: \n");
    for(i=0;i<=p->expo;i++)
    {
        printf("Coefficient of term with %d degree : ",i);
        scanf("%d",&p->coeff[i]);
    }
}
void insert(poly *p1, poly *p2)
{
    int i;
    printf("Enter the highest degree of the first polynomial: ");
    scanf("%d",&p1->expo);
    printf("Enter the highest degree of the second polynomial: ");
    scanf("%d",&p2->expo);
    if(p1->expo>max||p2->expo>max)
    {
        printf("Exponent is out of the range of the array.");
        return;
    }
    printf("Enter the coefficient fo the first polynomial: \n");
    for(i=0;i<=p1->expo;i++)
    {
        printf("The coefficient of the term with %d degree: ",i);
        scanf("%d",&p1->coeff[i]);
    }
    printf("Enter the coeffeicients of the second polynomial: \n");
    for(i=0;i<=p2->expo;i++)
    {
        printf("The coefficient of the term with %d degree: ",i);
        scanf("%d",&p2->coeff[i]);
    }
}
int maximum(int a,int b)
{
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void addData(poly *p1,poly *p2,poly *p)
{
    int i;
    p->expo=maximum(p1->expo,p2->expo);
    for(i=0;i<=p->expo;i++)
    {
        p->coeff[i]=p1->coeff[i]+p2->coeff[i];
    }
}
void multiData(poly*p1,poly *p2, poly *p)
{
    int i;
    p->expo=p1->expo+p2->expo;
    if(p->expo>max)
    {
        printf("Beyond array range");
        return;
    }
    for(i=0;i<p1->expo;i++)
    {
        for(int j=0;j<p2->expo;j++)
        {
            p->coeff[i+j]+=p1->coeff[i]*p2->coeff[j];
        }
    }
}
void display(poly *p)
{
    int k;
    printf("\nThe polynomial: \n");
    printf("COEFFICIENT\tEXPONENT\n");
    for(k=0;k<=p->expo;k++)
    {
        printf("%d\t\t%d\n",p->coeff[k],k);
    }
}
int main()
{
    int option;
    poly *ptr;
    poly *ptr1;
    poly *ptr2;
    option=1;
    while(option)
    {
        printf("Enter a valid option:\nInsertion of values:\t1\nDisplaying the values:\t2\nAddition of two polynomials:\t3\nMultiplication of two polynomials:\t4\nExit:\t0\nOption: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                input(ptr);
                display(ptr);
                break;
            case 2:
                display(ptr);
                break;
            case 3:
                ptr1=(poly*)calloc(1,sizeof(poly));
                ptr2=(poly*)calloc(1,sizeof(poly));
                ptr=(poly*)calloc(1,sizeof(poly));
                insert(ptr1,ptr2);
                addData(ptr1,ptr2,ptr);
                display(ptr);
                break;
            case 4:
                ptr1=(poly*)malloc(sizeof(poly));
                ptr2=(poly*)malloc(sizeof(poly));
                ptr=(poly*)malloc(sizeof(poly));
                insert(ptr1,ptr2);
                multiData(ptr1,ptr2,ptr);
                display(ptr);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("\n");
        }
    }
}