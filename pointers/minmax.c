#include <stdio.h>
int main(void)
{
    int a,b,c;
    printf("Enter three integers: ");
    scanf("%d%d%d",&a,&b,&c);
    int *p=&a;
    int *q=&b;
    int *r=&c;
    int max = (*p > *q) ? (*p > *r ? *p : *r) : (*q > *r ? *q : *r);
    int min = (*p < *q) ? (*p < *r ? *p : *r) : (*q < *r ? *q : * r);
    printf("The maximum value of the three numbers is %d",max);
    printf("\nThe minimum value of the the three numbers is %d",min);
    return 0;
}