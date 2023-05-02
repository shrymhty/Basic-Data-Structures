#include<stdio.h>

int tower(int n)
{
    if(n==0)
    {
        return 0;
    }
    return 2*tower(n-1)+1;
}

int main()
{
    printf("%d",tower(3));
    return 0;
}