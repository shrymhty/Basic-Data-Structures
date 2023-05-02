#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct 
{
    int coeff[max];
    int expo;

}poly;
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
    poly *ptr1;
    poly *ptr2;
    poly *ptr;
    ptr1=(poly*)calloc(1,sizeof(poly));
    ptr2=(poly*)calloc(1,sizeof(poly));
    ptr=(poly*)calloc(1,sizeof(poly));
    insert(ptr1,ptr2);
    multiData(ptr1,ptr2,ptr);
    display(ptr);
    return 0;
}