#include <stdio.h>
int main(void)
{
    int a,b;
    int *p=&a;
    int *q=&b;
    printf("Enter two integers: ");
    scanf("%d%d",&*p,&*q);
    printf("The two integers are : %d %d",*p,*q);
    printf("\nThe values (not pointers): %d and %d",a,b);
    return 0;
}