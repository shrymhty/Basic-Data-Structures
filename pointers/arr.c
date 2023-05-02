#include <stdio.h>
int main(void)
{
    int a[5];
    int i;
    int *b;
    b=&a[1];
    printf("Enter the 2nd element :");
    scanf("%d",b);
    for(i=1;i<5;i++)
    {
        *(b+i)=*b+2*i;
    }
    for(i=1;i>=0;i--)
    {
        *(b-i)=*b-2*i;
    }
    for(int j=0;j<5;j++)
    {
        printf("%d ",*(a+j));
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("%p ",&*(a+1));
    }
    return 0;
}