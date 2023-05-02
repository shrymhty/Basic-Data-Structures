#include<stdio.h>
int sum=0;

void digit(int n)
{
    if(n==0)
    {
        return;
    }
    sum=sum+(n%10);
    digit(n/10);
}

int main()
{
    digit(12345);
    printf("%d ",sum);
    return 0;
}