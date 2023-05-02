#include <stdio.h>
void digitrev(int);
void digit(int);
void digit(int num)
{
    if(num)
    {
        digit(num/10);
    }
    if(num!=0)
    {
        printf("%d ",num%10);
    }
}
void digitrev(int num)
{
    int n;
    if(num)
    {
        n=num%10;
        printf("%d ",n);
        num=num/10;
        digitrev(num);
    }
    else
    {
        return;
    }
}
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("The digits : ");
    digit(num);
    printf("\nThe digits in reverse order: ");
    digitrev(num);
}