#include <stdio.h>
#include<malloc.h>
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
    printf("Enter the coefficient for the first polynomial: \n");
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
void display(poly *p)
{
    int i;
    printf("The polynomial after adding the two polynomials : \n");
    for(i=0;i<=p->expo;i++)
    {
        printf("%d\t%d\n",p->coeff[i],i);
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

int main()
{
    poly *ptr1;
    poly *ptr2;
    poly *ptr;
    ptr1=(poly*)malloc(sizeof(poly));
    ptr2=(poly*)malloc(sizeof(poly));
    
    insert(ptr1,ptr2);
    addData(ptr1,ptr2,ptr);
    display(ptr);
}