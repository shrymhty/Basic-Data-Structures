#include<stdio.h>
int main()
{
    int a[5]={1,2,3,4,5};
    int *p=a;
    printf("%d",*p);
    printf("\n%d",*(++p));
    printf("\n%d",++(*p));
    return 0;
}