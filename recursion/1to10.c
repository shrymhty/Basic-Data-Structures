#include<stdio.h>
void num(int);
void num(int n)
{
    if(n)
    {
        num(n-1);
    }
    else
    {
        return;
    }
    printf("%d ",n);
}
int main()
{
    int n=10;
    printf("\nNumbers from 1 To 10 are: ");
    num(n);
    return 0;
}
