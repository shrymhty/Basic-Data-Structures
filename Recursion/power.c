#include<stdio.h>

int power(int n,int x)
{
    if(n==0)
    {
        return 1;
    }
    return x*power(n-1,x);
}

int main()
{
    printf("%d",power(3,5));
    return 0;
}