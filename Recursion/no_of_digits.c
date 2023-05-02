#include<stdio.h>
int c=0;

void count(int n)
{
    if(n==0)
    {
        return;
    }
    c++;
    count(n/10);
}

int main()
{
    count(7820);
    printf("%d",c);
    return 0;
}